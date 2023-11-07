#pragma once

#include <string>
#include <vector>

#include "card.h"
#include "pot.h"
#include "actions.h"


#include <memory>


class Pot;
//class PokerTable;
class Player {


    bool _is_active;
    std::string m_name;

    

public:


    std::vector<Card> m_cards;
    int m_chips;
    int m_order;
    bool is_turn;

    Player();

    Player(std::string name, int initial_chips);



    //Player(const Player& other);

    std::string getName() const;
    
    bool is_all_in();
    
    int n_bet_chips(const Pot & m_pot) const;
    
    
    void add_chips(int chips);

    int _try_to_make_full_bet(int n_chips);

    int add_to_pot(int n_chips, Pot &m_pot);


    void add_private_card(const Card& card);

    // TO DO: ADD take_action method for smart agents

    bool g_is_active() const;

    void s_is_active(bool x);

    void s_is_turn(bool x);

    Fold fold();

    Call call(std::vector<Player>& players, Pot &m_pot);

    Raise raise_to(int n_chips, Pot & m_pot);



};


