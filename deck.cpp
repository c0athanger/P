

#include <numeric>
#include <algorithm>
#include "card.h"
#include "deck.h"
#include <ctime>
#include <cstdlib>
#include "seed_time.h"

const unsigned int Deck::rank[13] = {0,1,2,3,4,5,6,7,8,9,10,11,12};
const unsigned int Deck::suit[4] = {0,1,2,3};

Deck::Deck() {


    _dealt_cards.reserve(17);
    _cards_in_deck.reserve(52);
    reset();
}

void Deck::reset()
{
    _cards_in_deck.clear();

    _dealt_cards.clear();


    for(int i = 0; i < 13;i++)
    {
        for(int j = 0; j < 4; j++)
        {


            _cards_in_deck.emplace_back(Card(rank[i],suit[j]));

        }


    }

    std::random_shuffle(_cards_in_deck.begin(), _cards_in_deck.end());

}

void Deck::place_in_deck(const Card &card) {
    for (auto it = _dealt_cards.begin(); it != _dealt_cards.end(); ++it) {
        if (it->_eval_card == card._eval_card) {
            _dealt_cards.erase(it);
            break;
        }
    }
    _cards_in_deck.push_back(card);
}

Card Deck::pick(bool random) {
    // TO DO: Error flag if deck is empty
    if (random) {


        int m_index = randSingleton::getInt(_cards_in_deck.size());
        Card m_card = _cards_in_deck[m_index];
        _cards_in_deck.erase(_cards_in_deck.begin()+m_index);
        _dealt_cards.push_back(m_card);
        return m_card;

    }

    else {
        int m_index = _cards_in_deck.size() - 1;
        Card m_card = _cards_in_deck[m_index];
        _cards_in_deck.pop_back();
        _dealt_cards.push_back(m_card);
        return m_card;
    }

}

void Deck::remove(Card m_card) {

    for (std::vector<Card>::iterator it = _cards_in_deck.begin() ; it != _cards_in_deck.end(); ++it) {

        if (it ->getRank()== m_card.getRank() and it ->getSuit() == m_card.getSuit()){
            _dealt_cards.push_back(m_card);
            _cards_in_deck.erase(it);
            break;
        }

    }
}
