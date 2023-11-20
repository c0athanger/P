#pragma once

#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif

#include <fstream>
#include <filesystem>
#include <iostream>
#include <string>
#include <vector>
#include <iostream>
#include <map>
#include "deck.h"
#include "player.h"
#include "actions.h"
#include "pot.h"
#include "dealer.h"
#include "table.h"

void cli(std::vector<std::string> &args);