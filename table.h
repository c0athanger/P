#pragma once
#include "dealer.h"
#include <vector>
#include "player.h"
#include "pot.h"
#include <memory>

class Pot;
class Player;
class Dealer;
class PokerTable{









public:

    std::vector<Player> m_players;


    std::vector<Card> community_cards;


    PokerTable(std::vector<Player> &players);

    int n_players();

    void set_players(const std::vector<Player>& players);

    void add_community_card(const Card& card);


    
};


