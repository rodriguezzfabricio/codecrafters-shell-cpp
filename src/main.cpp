#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include "print.h"
#include "echo.h"
#include "type.h"

int main() {
    std::cout << std::unitbuf; // Flush output buffers immediately

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

        // Split input into command and arguments
        std::istringstream iss(input);
        std::vector<std::string> args;
        std::string token;
        while (iss >> token) {
            args.push_back(token);
        }

        // Print arguments in the expected format
        if (!args.empty()) {
            for (size_t i = 0; i < args.size(); ++i) {
                if (i == 0) {
                    std::cout << "Arg #" << i << " (program name): " << args[i] << std::endl;
                } else {
                    std::cout << "Arg #" << i << ": " << args[i] << std::endl;
                }
            }
            continue;
        }

        // If no recognized command matches, print "command not found"
        std::cout << input << ": command not found" << std::endl;
    }

    return 0;
}
