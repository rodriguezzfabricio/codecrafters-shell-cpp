#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <cstdlib>
#include <unistd.h>
#include "type.h"

// Helper function to split a string by a delimiter
std::vector<std::string> split(const std::string& str, char delimiter) {
    std::vector<std::string> tokens;
    std::stringstream ss(str);
    std::string token;

    while (std::getline(ss, token, delimiter)) {
        tokens.push_back(token);
    }
    return tokens;
}

void handleType(const std::string& input) {
    const std::string typeCommand = "type ";
    if (input.substr(0, typeCommand.size()) != typeCommand) {
        std::cout << input << ": command not found" << std::endl;
        return;
    }

    // Extract the command to check
    std::string command = input.substr(typeCommand.size());

    // Check for built-in commands
    if (command == "echo" || command == "exit" || command == "type") {
        std::cout << command << " is a shell builtin" << std::endl;
        return;
    }

    // Get the PATH environment variable
    const char* pathEnv = std::getenv("PATH");
    if (!pathEnv) {
        std::cout << command << ": not found" << std::endl;
        return;
    }

    // Split PATH into directories
    std::vector<std::string> directories = split(pathEnv, ':');

    // Search for the command in each directory
    for (const auto& dir : directories) {
        std::string fullPath = dir + "/" + command;
        if (access(fullPath.c_str(), X_OK) == 0) {
            std::cout << command << " is " << fullPath << std::endl;
            return;
        }
    }

    // Command not found
    std::cout << command << ": not found" << std::endl;
}
