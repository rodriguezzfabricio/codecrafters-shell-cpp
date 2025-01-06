#include <iostream>
#include <string>
#include "type.h"

void handleType(const std::string& input) {
    // Check if the input starts with "type "
    const std::string typeCommand = "type ";
    if (input.substr(0, typeCommand.size()) != typeCommand) {
        std::cout << input << ": command not found" << std::endl;
        return;
    }

    // Extract the argument after "type "
    std::string command = input.substr(typeCommand.size());

    // Check for built-in commands
    if (command == "echo" || command == "exit" || command == "type") {
        std::cout << command << " is a shell builtin" << std::endl;
    } else {
        std::cout << command << ": not found" << std::endl;
    }
}
