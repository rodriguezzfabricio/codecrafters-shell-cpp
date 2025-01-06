#include <iostream>
#include <string>
#include "print.h" // Ensure this contains the `printPrompt` function declaration
#include "echo.h"  // Include the echo command handler

int main() {
    // Flush output buffers for immediate printing
    std::cout << std::unitbuf;

    while (true) {
        // Display the shell prompt
        printPrompt();

        // Get user input
        std::string input;
        if (!std::getline(std::cin, input)) {
            break; // Exit the loop on EOF
        }

        // Handle exit command
        if (input == "exit 0") {
            break;
        }

        // Handle echo command
        const std::string echoCommand = "echo ";
        if (input.substr(0, echoCommand.size()) == echoCommand) {
            handleEcho(input);
            continue;
        }

        // Print "command not found" for all other inputs
        std::cout << input << ": command not found" << std::endl;
    }

    return 0;
}
