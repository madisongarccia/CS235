#include <iostream>
#include <fstream>
#include <string>
#include <unordered_set>

int main(int argc, char const* argv[]) {
    std::unordered_set<std::string> uniqueLines;
    std::string line;

    if (argc == 2) {
        // Read from the file specified in the command-line argument
        std::ifstream inputFile(argv[1]);
        if (!inputFile.is_open()) {
            std::cerr << "Error opening the file: " << argv[1] << std::endl;
            return 1;
        }

        while (std::getline(inputFile, line)) {
            uniqueLines.insert(line);
        }

        inputFile.close();
    } else {
        // Read from stdin
        while (std::getline(std::cin, line)) {
            uniqueLines.insert(line);
        }
    }

    // Output unique lines in the order they appear
    for (size_t i = 0; i < uniqueLines.size(); ++i) {
        std::cout << i << std::endl;
    }

    return 0;
}