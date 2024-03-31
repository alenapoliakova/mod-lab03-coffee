// Copyright 2024 <alenapoliakova>
#include <iostream>
#include <string>
#include <stdexcept>
#include "Automata.h"

Automata::Automata() {
    state = OFF;
    cash = 0;
    option = 0;
    getState();
}

void Automata::getMenu() {
    // Display the menu and prices
    for (int idx = 0; idx < 5; idx++) {
        std::cout << idx + 1 << ": "<< menu[idx];
        std::cout << " - " << prices[idx] << std::endl;
    }
}

void Automata::on() {
    // Turn ON the vending machine
    if (state == OFF) {
        state = WAIT;
        std::cout << "The drink machine is on" << std::endl;
        getMenu();
        getState();
    } else {
        throw std::domain_error("Error, incorrect operation");
    }
}

void Automata::off() {
    // Turn OFF the vending machine
    if (state == WAIT) {
        state = OFF;
        getState();
    } else {
        throw std::domain_error("Error, incorrect operation");
    }
}

void Automata::coin(int money) {
    // Add money to the vending machine
    if (state == WAIT || state == ACCEPT) {
        if (money < 0) {
            throw std::invalid_argument("Error, incorrect value");
        }
        state = ACCEPT;
        cash += money;
        getState();
    } else {
        throw std::domain_error("Error, incorrect operation");
    }
}

void Automata::cancel() {
    // Cancel the current operation
    if (state == ACCEPT || state == CHECK) {
        state = WAIT;
        std::cout << "You need more money to buy drink" << std::endl;
        getCash();
        getState();
    } else {
        throw std::domain_error("Error, incorrect operation");
    }
}

void Automata::choice(int menu_position) {
    // Select a drink from the menu
    if (state == ACCEPT) {
        if (sizeof(menu) < menu_position || menu_position <= 0) {
            throw std::invalid_argument("Error, incorrect value");
        }
        state = CHECK;
        std::cout << "Your choice is " << menu[menu_position - 1] << std::endl;
        getState();
    } else {
        throw std::domain_error("Error, incorrect operation");
    }
}

bool Automata::check() {
    // Check if there is enough money for the selected drink
    if (state == CHECK) {
        if (cash >= prices[option]) {
            return true;
        }
        getState();
        return false;
    }
    throw std::domain_error("Error, incorrect operation");
}

void Automata::cook() {
    // Simulate the process of making a drink
    if (state == CHECK) {
        state = COOK;
        cash -= prices[option];
        getCash();
        getState();
    } else {
        throw std::domain_error("Error, incorrect operation");
    }
}

void Automata::finish() {
    // Finish the current operation
    if (state == COOK) {
        state = WAIT;
        getCash();
        getState();
    } else {
        throw std::domain_error("Error, incorrect operation");
    }
}

int Automata::getCash() {
    // Display the current amount of money
    std::cout << "Your cash is " << cash << std::endl;
    return cash;
}

void Automata::getState() {
    // Display the current state of the vending machine
    switch (state) {
        case OFF:
            std::cout << "The drink machine is off" << std::endl;
            break;
        case WAIT:
            std::cout << "Waiting for your action" << std::endl;
            break;
        case ACCEPT:
            std::cout << "Give money, please" << std::endl;
            break;
        case CHECK:
            std::cout << "Checking your balance..." << std::endl;
            break;
        case COOK:
            std::cout << "Making your drink..."<< std::endl;
            break;
    }
}
