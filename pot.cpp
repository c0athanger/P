
#include "pot.h"
#include "player.h"
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <numeric>

std::unordered_map<std::string, int> Pot::weird_bet_values = {};

Pot::Pot(){
    reset();
}

void Pot::reset() {
    mapPot.clear();
}

std::vector<std::map<std::string, int>> Pot::side_pots() {

    bool boolSidepot = true;
    std::vector<int> dif_bet_vals;



    dif_bet_vals.push_back(mapPot.begin()->second);
    for (std::map<std::string, int>::iterator it = mapPot.begin(); it != std::prev(mapPot.end(), 1); ++it) {
        bool otherBool = true;
        for (int bet : dif_bet_vals) {
            if (bet == std::next(it)->second) {
                otherBool = false;
            }
        }

        if (otherBool) {
            dif_bet_vals.push_back(std::next(it)->second);
        }

        if (it->second != std::next(it)->second) {
            boolSidepot = false;
        }
    }

    if (boolSidepot == false) {
        std::vector<std::map<std::string, int>> empty;
        empty.push_back(mapPot);
        return empty;
    }

    std::sort(dif_bet_vals.begin(), dif_bet_vals.end());

    std::vector<std::map<std::string, int>> side_pot2;
    std::map<std::string, int> side_pot1 = mapPot;
    for (std::map<std::string, int>::iterator it1 = side_pot1.begin(); it1 != side_pot1.end(); ++it1) {
        if (it1->second > dif_bet_vals[0]) {
            it1->second = dif_bet_vals[0];
        }
    }
    side_pot2.push_back(side_pot1);
    if (dif_bet_vals.size() == 2) {
        std::map<std::string, int> side_pot1 = mapPot;
        std::vector<std::string> players_to_pop;
        for (std::map<std::string, int>::iterator it1 = side_pot1.begin(); it1 != side_pot1.end(); ++it1) {
            it1->second -= dif_bet_vals[0];
            if (it1->second <= 0) {
                players_to_pop.push_back(it1->first);
            }
        }

        for (std::string& player : players_to_pop) {
            side_pot1.erase(side_pot1.find(player));
        }

        side_pot2.push_back(side_pot1);
        return side_pot2;
    }


    for (std::vector<int>::iterator it = dif_bet_vals.begin(); it != std::prev(dif_bet_vals.end()); ++it) {
        std::map<std::string, int> side_pot1 = mapPot;
        std::vector<std::string> players_to_pop;
        for (std::map<std::string, int>::iterator it1 = side_pot1.begin(); it1 != side_pot1.end(); ++it1) {
            it1->second -= *it;
            if (it1->second <= 0) {
                players_to_pop.push_back(it1->first);
            }

            if ((it1->second + (*it)) >  std::next(it1)->second){
                it1->second = std::next(it1)->second;
            }

        }

        for (std::string& player : players_to_pop) {
            side_pot1.erase(side_pot1.find(player));
        }



        side_pot2.push_back(side_pot1);


    }

    return side_pot2;

}

void Pot::add_chips(const Player &player, int n_chips) {

    mapPot[player.getName()] += n_chips;

}

void Pot::remove_chips(const Player &player, int n_chips)
{
    mapPot[player.getName()] -= n_chips;
}

int Pot::playerTotal(const std::string& player) const {
    return mapPot.at(player);
}

int Pot::total() {
    int sum_of_elems = 0;
    for(std::map<std::string, int>::iterator it = mapPot.begin(); it != mapPot.end(); ++it){
        sum_of_elems += it->second;
    }
    return sum_of_elems;
}

void Pot::set_players_in_pot(const std::vector<Player> & players)
{
    for (auto & p : players) mapPot[p.getName()] = 0;
}
