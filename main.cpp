#include <iostream>
#include "cli.h"
#include <string>
#include <sstream>
#include <vector>
#include <iterator>

template <typename Out>
void split(const std::string &s, char delim, Out result)
{
    std::istringstream iss(s);
    std::string item;
    while (std::getline(iss, item, delim))
    {
        *result++ = item;
    }
}

std::vector<std::string> split(const std::string &s, char delim)
{
    std::vector<std::string> elems;
    split(s, delim, std::back_inserter(elems));
    return elems;
}

void process(const std::string &line)
{
    char de = ' ';
    std::vector<std::string> a = split(line, de);
    cli(a);
}

int main()
{
    process("intro");
    for (std::string line; std::cout << "POKER APP > " && std::getline(std::cin, line);)
    {
        if (!line.empty())
        {
            process(line);
        }
    }
    return 0;
}
