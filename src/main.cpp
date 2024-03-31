// Copyright 2024 <alenapoliakova>
#include <iostream>
#include <string>
#include "Automata.h"

int main() {
    Automata drinking_machine;

    drinking_machine.on();
    drinking_machine.coin(1000);
    // Get americano
    drinking_machine.choice(1);

    if (drinking_machine.check()) {
        drinking_machine.cook();
        drinking_machine.finish();
    } else {
        drinking_machine.cancel();
    }

    drinking_machine.off();
    return 0;
}
