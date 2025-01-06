#include <iostream>
#include <string>
#include "print.h"
#include "echo.h"
#include "type.h"

int main() {
    std::cout << std::unitbuf;

    while (true) {
        printPrompt(); // Print the shell prompt

        std::string input;
        if (!std::getline(std::cin, input)) {
            break; // Exit on EOF
        }

        // Handle exit command
        if (input == "exit 0") {
            break;
        }

        // Handle echo command
        if (input.substr(0, 5) == "echo ") {
            handleEcho(input);
            continue;
        }

        // Handle type command
        if (input.substr(0, 5) == "type ") {
            handleType(input);
            continue;
        }

        // Print "command not found" for all other inputs
        std::cout << input << ": command not found" << std::endl;
    }

    return 0;
}
