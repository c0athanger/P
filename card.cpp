// python code for importing eval card function : from poker_ai.poker.evaluation.eval_card import EvaluationCard
#include "card.h"
#include "eval_card.h"

#include <string>
#include <cmath>

std::map<unsigned int, std::string> Card::CONV_SUIT = {{1, "spades",}, {2, "hearts",}, {4, "diamonds",}, {8, "clubs",}, };
std::string Card::CONV_RANK = "23456789TJQKA";
Card::Card(unsigned int rk, unsigned int st) :rank(rk), suit(std::pow(2, st)), _eval_card(EvaluationCard::_new(rank, suit)) {

}

//void Card::setCard(unsigned int x, unsigned int y) {
//    rank = x;
//    suit = std::pow(2, y);
//};

unsigned int Card::getRank() const {
    return rank;
};
unsigned int Card::getSuit() const {
    return suit;
};

unsigned int Card::eval_card() const {
    return _eval_card;
}
