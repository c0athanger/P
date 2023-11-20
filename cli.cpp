#include "cli.h"

static std::map<std::string, int> pi = {{"p1", 0}, {"p2", 1}};

static Dealer dealer = Dealer();

static std::vector<Player> p_s = {Player("p1", 10000), Player("p2", 10000)};

static PokerTable table = PokerTable(p_s);

static Pot pot = Pot();

void p(const std::string &s)
{
	std::cout << s << std::endl;
}

void cli(std::vector<std::string> &args)
{
	if (args[0] == "deal-players")
	{
		dealer.deal_private_cards(table.m_players);
		p("All player cards have been dealt.");
	}
	else if (args[0] == "shuffle")
	{
		p("Are you sure you want to shuffle? This action will cause all active cards to return to the deck(yn)");
		std::string s;
		std::cin >> s;
		if (s[0] = 'n')
		{
			p("Alright, cancelling the shuffle action");
			return;
		}
		dealer = Dealer();
		table.community_cards.clear();
		for (int i = 0; i < table.m_players.size(); i++)
		{
			table.m_players[i].m_cards.clear();
		}
		p("The deck has been shuffled. All cards in play have been returned to the deck");
	}
	else if (args[0] == "deal-flop")
	{
		dealer.deal_flop(table);
		p("The flop has been dealt. To see it type show community");
	}
	else if (args[0] == "deal-turn")
	{
		dealer.deal_turn(table);
		p("The turn has been dealt. To see it type show community");
	}
	else if (args[0] == "deal-river")
	{
		p("The river has been dealt. To see it type show community");
	}
	else if (args[0] == "blinds")
	{
		table.m_players[0].add_to_pot(50, pot);
		table.m_players[1].add_to_pot(100, pot);
		p("Blinds have been taken from big blind and little blind");
	}
	else if (args[0] == "raise")
	{
		table.m_players[pi[args[1]]].raise_to(stoi(args[2]), pot);
		p("You have raise by " + args[2]);
	}
	else if (args[0] == "call")
	{
		table.m_players[pi[args[1]]].call(table.m_players, pot);
		p("You have called");
	}
	else if (args[0] == "fold")
	{
		table.m_players[pi[args[1]]].fold();
		p("You have folded");
	}
	else if (args[0] == "show-community")
	{
		std::string s = "";
		for (int i = 0; i < table.community_cards.size(); i++)
		{
			s += Card::CONV_RANK[table.community_cards[i].getRank()];
			s += Card::CONV_SUIT[table.community_cards[i].getSuit()];
			s += " ";
		}
		p(s);
	}
	else if (args[0] == "show-hand")
	{
		std::string s = "";
		for (int i = 0; i < 2; i++)
		{
			s += Card::CONV_RANK[table.m_players[pi[args[1]]].m_cards[i].getRank()];
			s += Card::CONV_SUIT[table.m_players[pi[args[1]]].m_cards[i].getSuit()];
			s += " ";
		}
		p(s);
	}
	else if (args[0] == "intro")
	{
		p("Hello and welcome to my poker app. This app is designed by poker players for poker players. If you enjoy poker, you should give it a try. Just remember to bet responsibly, poker is about having fun after all! If its your first time using this app or playing poker type the help command for more details");
	}
	else if (args[0] == "help")
	{
		p("Dealer commands:");
		p("deal-player [player_name]: dealer deals 2 cards to player called [player_name]");
		p("shuffle: dealer shuffles deck, returning all active cards to the deck");
		p("deal-flop: Dealer deals flop");
		p("deal-turn: Dealer deals turn card, dealer, also deals flop if not already dealt");
		p("deal-river: Deals deals river card, also deals flop if not already dealt");
		p("");
		p("Pot commands:");
		p("blinds: Takes big blind and small blinds from players");
		p("raise [player] [int]: Raise by [int] where [int] is some int");
		p("call [player]: Call a raise");
		p("fold [player]: Give up your hand.");
		p("Show-community: shows community cards and pot");
		p("show-hand [player_name]: shows hand of [player_name]");
		p("pot-payout [player_name]: payout winner");
		p("");
		p("For now there are 2 players allowed, named p1 and p2");
		p("To see the rules of Texas hold’em and instructions on how to play a simple game, visit:");
		p("www.on.pokerstars.ca");
	}
	else if (args[0] == "pot-payout")
	{
		p("Winner gained " + std::to_string(pot.total()));
	}
	else if (args[0] == "bank")
	{
		std::ofstream outfile;
		outfile.open("../bankcomms.txt");
		outfile << "request " + args[1] + " " + args[2] + " " + args[3] << std::endl;
		outfile.close();
		const std::filesystem::path p = "../bankcomms.txt";
		auto last_mtime = std::filesystem::last_write_time(p);
		while (last_mtime == std::filesystem::last_write_time(p))
		{
			sleep(1);
		}
		std::cout << "The bank has completed your transaction" << std::endl;
	}
	else if (args[0] == "check-bank")
	{

		std::fstream filein("../bankcomms.txt");
		for (std::string line; std::getline(filein, line);)
		{
			std::cout << line << std::endl;
		}
	}
}