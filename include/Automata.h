// Copyright 2024 <alenapoliakova>
#pragma once
#include <iostream>
#include <string>

// Enumeration type for the states of the vending machine
enum STATES {OFF, WAIT, ACCEPT, CHECK, COOK};

class Automata {
 public:
        STATES state;  // Current state
        int cash;  // Сurrent amount of money
        const std::string menu[5] = {
            "americano",
            "cappuccino",
            "latte",
            "tea",
            "cocoa",
        };
        int option;  // User's choice of drink
        const int prices[5] = {
            10, 20, 30, 40, 50
            };

 public:
        Automata();
        void on();  // Turn on the vending machine
        void off();  // Turn off the vending machine
        void coin(int x);  // Add money to the user's account
        void getMenu();  // Read the menu
        void getState();  // Read the current state for the user
        void choice(int x);  // User's choice of drink
        bool check();  // Check for the necessary amount of money
        int getCash();  // Return change / money
        void cancel();  // Cancel user service session
        void cook();  // Simulate the process of making a drink
        void finish();  // Finish user service
};
