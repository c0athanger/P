
#include "eval_card.h"
#include <vector>

std::unordered_map<int, int> EvaluationCard::CONVERTER_SUIT = {{1,0}, {2,1}, {4,2}, {8,3}};



// const char STR_RANKS[13] = {'2', '3', '4', '5', '6', '7', '8', '9', 'T', 'J', 'Q', 'K', 'A'};

// const unsigned int INT_RANKS[13] = {0,1,2,3,4,5,6,7,8,9,10,11,12};

const unsigned int EvaluationCard::PRIMES[13] = {2 , 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41};

// const std::map<char, unsigned int> CHAR_SUIT_TO_INT_SUIT {{'s', 1}, {'h', 2}, {'d', 4}, {'c', 8}};
// const char INT_SUIT_TO_CHAR_SUIT[9] = {'x', 's', 'h', 'x', 'd', 'x', 'x', 'x', 'd' };

unsigned int EvaluationCard::_new(unsigned int stri0, unsigned int stri1) {

    unsigned int rank_int = stri0;
    unsigned int suit_int = stri1;

    unsigned int rank_prime = PRIMES[rank_int];

    unsigned int bitrank = 1 << rank_int << 16;

    unsigned int suit = suit_int << 12;

    unsigned int rank = rank_int << 8;

    return bitrank | suit | rank | rank_prime;



}

unsigned int EvaluationCard::get_rank_int(const unsigned int card_int) {
    return (card_int >> 8) & 0xF;
}

unsigned int EvaluationCard::get_suit_int(const unsigned int card_int) {
    return (card_int >> 12) & 0xF;
}

unsigned int EvaluationCard::get_suit_int_not_exponential(const unsigned int card_int) {
    return CONVERTER_SUIT.at((card_int >> 12) & 0xF);
}

unsigned int EvaluationCard::get_bitrank_int(const unsigned int card_int) {
    return (card_int >> 16) & 0x1FFF;
}

unsigned int EvaluationCard::get_prime(const unsigned int card_int) {
    return  card_int & 0x3F;
}

std::vector<unsigned int> EvaluationCard::hand_to_binary(std::vector<std::pair<unsigned int, unsigned int>>& card_strs) {
    std::vector<unsigned int> bhand;
    bhand.reserve(card_strs.size());
    for (auto& it : card_strs) {
        bhand.push_back(_new(it.first, it.second));
    }
    return bhand;
}

unsigned int EvaluationCard::prime_product_from_hand(std::vector<unsigned int>& card_ints) {
    unsigned int product = 1;
    for (std::vector <unsigned int>::iterator it = card_ints.begin(); it != card_ints.end(); ++it) {
        product *= *it & 0xFF;
    }
    return product;
}

unsigned int EvaluationCard::prime_product_from_rankbits(unsigned int rankbits) {
    unsigned int product = 1;
    for (unsigned int i = 0; i < 13; i++) {
        if (rankbits & (1 << i)) {
            product *= PRIMES[i];
        }
    }
    return product;
}
