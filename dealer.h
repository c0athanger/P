#pragma once

#include "deck.h"
#include "card.h"

#include <vector>
#include <string>
#include "player.h"
#include "table.h"

class Player;
class PokerTable;

class Dealer 
{
    Deck c_deck;


public:

    Dealer();

    Card deal_card();

    void deal_private_cards(std::vector<Player>& player);

    void redo_deal_private_cards(std::vector<Player>& player);

    void deal_community_cards(PokerTable &m_table, int n_cards);

    void redo_community_cards(PokerTable &m_table, int n_cards);

    void redo_all_cards(PokerTable &m_table, int n_cards);

    void deal_flop(PokerTable &m_table);

    void deal_turn(PokerTable &m_table);

    void deal_river(PokerTable &m_table);




};




