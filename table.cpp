
#include "table.h"
#include "dealer.h"
#include <vector>
#include "player.h"
#include "pot.h"

#include<memory>

//PokerTable::PokerTable(const PokerTable& other)
//    : m_players(other.m_players), m_pot(std::shared_ptr<Pot>(other.m_pot)), m_dealer(new Dealer(*other.m_dealer)), community_cards(other.community_cards), n_games(other.n_games), total_n_chips_on_table(other.total_n_chips_on_table) {

//}

PokerTable::PokerTable(std::vector<Player> &players)
    : m_players(players) {
    community_cards.clear();





}


int PokerTable::n_players() {
    return m_players.size();
}

void PokerTable::set_players(const std::vector<Player> &players) {
    m_players = players;

}

void PokerTable::add_community_card(const Card &card) {
    community_cards.push_back(card);
}
