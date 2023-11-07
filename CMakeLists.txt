cmake_minimum_required(VERSION 3.20)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_CXX_FLAGS -pthread)

set(SOURCES
    actions.cpp
    card.cpp
    cli.cpp
    dealer.cpp
    deck.cpp
    eval_card.cpp
    main.cpp
    table.cpp
    player.cpp
    pot.cpp
    seed_time.cpp
)
include_directories(.)
add_executable(test ${SOURCES})
