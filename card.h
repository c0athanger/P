#pragma once

#include "eval_card.h"
#include <string>
#include <map>




class Card{
public:
    // EvaluationCard ec;
    // TO DO pretty printing
    // TO DO: Create code for eval card classs variable, pyhon code : self._eval_card = EvaluationCard.new(f"{rank_char}{suit_char}")
    static std::map<unsigned int, std::string> CONV_SUIT;
    static std::string CONV_RANK;
    Card(unsigned int rk, unsigned int st);

//    void setCard(unsigned int x, unsigned int y);

    unsigned int getRank() const;
    unsigned int getSuit() const;
    unsigned int eval_card() const;



    unsigned int rank;
    unsigned int suit;
    unsigned int _eval_card;
};

