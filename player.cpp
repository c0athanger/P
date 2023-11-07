
#include "player.h"
#include <string>
#include <vector>

#include "card.h"
#include "pot.h"
#include "actions.h"


#include <memory>



Player::Player()  {

}

Player::Player(std::string name, int initial_chips)
    : _is_active(1), m_name(name), m_chips(initial_chips), is_turn(0)
{
    m_cards.reserve(2);
}

// Player::Player(const Player& other) : _is_active(other._is_active), m_name(other.m_name),
//     m_pot(other.m_pot), m_cards(other.m_cards), m_chips(other.m_chips), m_order(other.m_order), is_turn(other.is_turn) {}

// Player::Player(const Player& other) : _is_active(other._is_active), m_name(other.m_name), m_pot(other.m_pot), m_chips(other.m_chips), m_order(other.m_order), is_small_blind(other.is_small_blind), is_big_blind(other.is_big_blind), is_dealer(other.is_dealer), is_turn(other.is_turn) {}


std::string Player::getName() const {
    return m_name;
}

bool Player::is_all_in() {
    if (_is_active and m_chips == 0) {
        return true;
    }
    else {
        return false;
    }
}

int Player::n_bet_chips(const Pot & m_pot) const {
    return m_pot.playerTotal(getName());
}


void Player::add_chips(int chips) {
    m_chips += chips;
}

int Player::_try_to_make_full_bet(int n_chips) {
    if (m_chips < n_chips) {
        n_chips = m_chips;
    }

    return n_chips;

}

int Player::add_to_pot(int n_chips, Pot & m_pot) {

    n_chips = _try_to_make_full_bet(n_chips);
    m_pot.add_chips(*this, n_chips);
    m_chips -= n_chips;
    return n_chips;

}

void Player::add_private_card(const Card& card) {
    m_cards.push_back(card);
}

// TO DO: ADD take_action method for smart agents

bool Player::g_is_active() const {
    return _is_active;
}

void Player::s_is_active(bool x) {
    _is_active = x;
}

void Player::s_is_turn(bool x) {
    is_turn = x;
}

Fold Player::fold() {
    _is_active = false;
    return Fold();
}

Call Player::call(std::vector<Player>& players, Pot & m_pot) {
    if (is_all_in()) {
        return Call();
    }
    else {
        // For efficiency might want to move this to somewhere else and add biggest_bet as a parameter instead
        int biggest_bet = 0;
        for (std::vector<Player>::iterator it = players.begin(); it != players.end(); ++it) {
            if (biggest_bet < it->n_bet_chips(m_pot)) {

                biggest_bet = it->n_bet_chips(m_pot);
            }
        }
        int n_chips_to_call = biggest_bet - n_bet_chips(m_pot);
        add_to_pot(n_chips_to_call, m_pot);
        return Call();
    }
}

Raise Player::raise_to(int n_chips, Pot & m_pot) {
    n_chips = add_to_pot(n_chips, m_pot);
    n_chips = _try_to_make_full_bet(n_chips);
    Raise ra;
    ra.raise_amount(n_chips);
    return ra;
}




