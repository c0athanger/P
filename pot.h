#pragma once
#include "player.h"
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <numeric>
#include <unordered_map>

// ADD side pots
class Player;

class Pot {




public:
    std::map<std::string, int> mapPot;
    static std::unordered_map<std::string, int> weird_bet_values;

    Pot();

    void reset();

    std::vector<std::map<std::string, int>> side_pots();

    void add_chips(const Player &player, int n_chips);

    void remove_chips(const Player &player, int n_chips);

    int playerTotal(const std::string& player) const;

    int total();

    void set_players_in_pot(const std::vector<Player> & players);

};


