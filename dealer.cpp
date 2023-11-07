
#include "dealer.h"
#include <vector>
#include <string>
#include "player.h"
#include "table.h"

Dealer::Dealer()
{
    c_deck.reset();
}

Card Dealer::deal_card() {

    return c_deck.pick(true);
}
void Dealer::deal_private_cards(std::vector<Player>& player) {

    for (int i=0; i < 2; i++) {
        for (std::vector<Player>::iterator it = player.begin(); it != player.end(); ++it ) {


            it->add_private_card(deal_card());
        }
    }
}

void Dealer::redo_deal_private_cards(std::vector<Player> &player) {
    for (auto& p : player) {
        for (auto& c : p.m_cards) {
            c_deck.place_in_deck(c);
        }
        p.m_cards.clear();
    }
    deal_private_cards(player);
}

void Dealer::deal_community_cards(PokerTable &m_table, int n_cards) {

    for (int i = 0; i < n_cards; i++) {
        m_table.add_community_card(deal_card());
    }

}

void Dealer::redo_community_cards(PokerTable &m_table, int n_cards)
{
    for (auto & c : m_table.community_cards) {
        c_deck.place_in_deck(c);
    }
    m_table.community_cards.clear();
    for (int i = 0; i < n_cards; i++) {
        m_table.add_community_card(deal_card());
    }

}

void Dealer::redo_all_cards(PokerTable &m_table, int n_cards)
{


    for (auto & c : m_table.community_cards) {
        c_deck.place_in_deck(c);
    }
    m_table.community_cards.clear();


    for (auto& p : m_table.m_players) {
        for (auto& c : p.m_cards) {
            c_deck.place_in_deck(c);
        }
        p.m_cards.clear();
    }

    deal_private_cards(m_table.m_players);

    for (int i = 0; i < n_cards; i++) {
        m_table.add_community_card(deal_card());
    }

}

void Dealer::deal_flop(PokerTable &m_table) {
    deal_community_cards(m_table, 3);
}

void Dealer::deal_turn(PokerTable &m_table) {
    deal_community_cards(m_table, 1);
}

void Dealer::deal_river(PokerTable &m_table) {
    deal_community_cards(m_table, 1);
}
