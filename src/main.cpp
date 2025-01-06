#include <iostream>
#include <string>
#include "print.h" // Ensure this contains the `printPrompt` function declaration

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

        // Print "command not found" for all inputs
        std::cout << input << ": command not found" << std::endl;
    }

    return 0;
}
