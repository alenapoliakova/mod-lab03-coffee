// Copyright 2024 <alenapoliakova>
#include <gtest/gtest.h>
#include <stdexcept>
#include <iostream>
#include <string>
#include "Automata.h"

TEST(test1, incorrect_operation) {
    Automata drinking_machine;
    drinking_machine.state = CHECK;
    try {
        drinking_machine.on();
    }
    catch(std::domain_error& err) {
        ASSERT_STREQ("Error, incorrect operation", err.what());
    }
}

TEST(test2, incorrect_operation) {
    Automata drinking_machine;
    drinking_machine.state = CHECK;
    try {
        drinking_machine.off();
    }
    catch(std::domain_error& err) {
        ASSERT_STREQ("Error, incorrect operation", err.what());
    }
}

TEST(test3, incorrect_operation) {
    Automata drinking_machine;
    drinking_machine.state = OFF;
    try {
        drinking_machine.coin(100);
    }
    catch(std::domain_error& err) {
        ASSERT_STREQ("Error, incorrect operation", err.what());
    }
}

TEST(test4, incorrect_operation) {
    Automata drinking_machine;
    drinking_machine.state = WAIT;
    try {
        drinking_machine.cancel();
    }
    catch(std::domain_error& err) {
        ASSERT_STREQ("Error, incorrect operation", err.what());
    }
}

TEST(test5, incorrect_operation) {
    Automata drinking_machine;
    drinking_machine.state = WAIT;
    try {
        drinking_machine.choice(3);
    }
    catch(std::domain_error& err) {
        ASSERT_STREQ("Error, incorrect operation", err.what());
    }
}

TEST(test6, incorrect_operation) {
    Automata drinking_machine;
    drinking_machine.state = ACCEPT;
    try {
        drinking_machine.check();
    }
    catch(std::domain_error& err) {
        ASSERT_STREQ("Error, incorrect operation", err.what());
    }
}

TEST(test7, incorrect_operation) {
    Automata drinking_machine;
    drinking_machine.state = OFF;
    try {
        drinking_machine.cook();
    }
    catch(std::domain_error& err) {
        ASSERT_STREQ("Error, incorrect operation", err.what());
    }
}

TEST(test8, incorrect_operation) {
    Automata drinking_machine;
    drinking_machine.state = CHECK;
    try {
        drinking_machine.finish();
    }
    catch(std::domain_error& err) {
        ASSERT_STREQ("Error, incorrect operation", err.what());
    }
}

TEST(test9, incorrect_value) {
    Automata drinking_machine;
    drinking_machine.state = ACCEPT;
    try {
        drinking_machine.coin(-500);
    }
    catch(std::invalid_argument& err) {
        ASSERT_STREQ("Error, incorrect value", err.what());
    }
}

TEST(test10, states) {
    Automata drinking_machine;
    drinking_machine.on();
    EXPECT_EQ(WAIT, drinking_machine.state);
}

TEST(test11, states) {
    Automata drinking_machine;
    drinking_machine.on();
    drinking_machine.coin(1000);
    EXPECT_EQ(ACCEPT, drinking_machine.state);
}

TEST(test12, states) {
    Automata drinking_machine;
    drinking_machine.on();
    drinking_machine.coin(1000);
    drinking_machine.choice(5);
    EXPECT_EQ(CHECK, drinking_machine.state);
}

TEST(test13, states) {
    Automata drinking_machine;
    drinking_machine.on();
    drinking_machine.coin(1000);
    drinking_machine.choice(5);
    drinking_machine.cook();
    EXPECT_EQ(COOK, drinking_machine.state);
}

TEST(test14, states) {
    Automata drinking_machine;
    drinking_machine.on();
    drinking_machine.coin(1000);
    drinking_machine.choice(5);
    drinking_machine.cook();
    drinking_machine.finish();
    EXPECT_EQ(WAIT, drinking_machine.state);
}

TEST(test15, states) {
    Automata drinking_machine;
    drinking_machine.on();
    drinking_machine.coin(10);
    drinking_machine.choice(5);
    drinking_machine.cancel();
    EXPECT_EQ(WAIT, drinking_machine.state);
}

TEST(test16, states) {
    Automata drinking_machine;
    drinking_machine.on();
    drinking_machine.coin(1000);
    drinking_machine.choice(5);
    drinking_machine.cook();
    drinking_machine.finish();
    drinking_machine.off();
    EXPECT_EQ(OFF, drinking_machine.state);
}
