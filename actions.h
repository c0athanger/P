#pragma once

struct Action {};

struct Call : Action {

};

struct Fold : Action {

};

struct Raise : Action {
    int m_amount;

    void raise_amount (int amount);

};


