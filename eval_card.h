#pragma once
// #include <map>
#include <vector>
#include <unordered_map>



class EvaluationCard {
    static std::unordered_map<int, int> CONVERTER_SUIT;
    // const char STR_RANKS[13] = {'2', '3', '4', '5', '6', '7', '8', '9', 'T', 'J', 'Q', 'K', 'A'};

    // const unsigned int INT_RANKS[13] = {0,1,2,3,4,5,6,7,8,9,10,11,12};

    static const unsigned int PRIMES[13];

    // const std::map<char, unsigned int> CHAR_SUIT_TO_INT_SUIT {{'s', 1}, {'h', 2}, {'d', 4}, {'c', 8}};
    // const char INT_SUIT_TO_CHAR_SUIT[9] = {'x', 's', 'h', 'x', 'd', 'x', 'x', 'x', 'd' };
public:
    static unsigned int _new(unsigned int stri0, unsigned int stri1);

    static unsigned int get_rank_int(const unsigned int card_int);

    static unsigned int get_suit_int(const unsigned int card_int);

    static unsigned int get_bitrank_int(const unsigned int card_int);

    static unsigned int get_prime(const unsigned int card_int);

    std::vector<unsigned int> hand_to_binary(std::vector<std::pair<unsigned int, unsigned int>>& card_strs);

    unsigned int prime_product_from_hand(std::vector<unsigned int>& card_ints);

    unsigned int prime_product_from_rankbits(unsigned int rankbits);

    static unsigned int get_suit_int_not_exponential(const unsigned int card_int);



};

