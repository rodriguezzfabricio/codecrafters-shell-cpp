#include <iostream>
#include <string>
#include "echo.h"

void handleEcho(const std::string& input) {
    // Check if the input starts with "echo "
    const std::string echoCommand = "echo ";
    if (input.substr(0, echoCommand.size()) == echoCommand) {
        // Remove "echo " and print the rest
        std::cout << input.substr(echoCommand.size()) << std::endl;
    } else {
        std::cout << input << ": command not found" << std::endl;
    }
}
