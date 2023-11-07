#pragma once

#include "card.h" //delete later
#include <string>
#include <vector>
#include <algorithm>
#include <stdlib.h>
class Deck
{
public:
    Deck();

    void reset();


    Card pick(bool random);

    void place_in_deck(const Card &card);

    void remove(Card m_card);
    static const unsigned int rank[13];
    static const unsigned int suit[4];

private:

    std::vector<Card> _cards_in_deck;
    std::vector<Card> _dealt_cards;
};


