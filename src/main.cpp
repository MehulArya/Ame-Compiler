#include <iostream>
#include <fstream>
#include <optional>
#include <sstream>
#include <vector>
#include "./generation.h"

int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cout << "Incorrect Usage" << std::endl;
        std::cout << "Ame <input.ame>" << std::endl;
        return EXIT_FAILURE;
    }

    std::string contents;
    {
        std::stringstream contents_stream;
        std::fstream input(argv[1], std::ios::in);
        contents_stream << input.rdbuf();
        contents = contents_stream.str();
    }

    tokenizer tokenizer(std::move(contents));
    std::vector<Token> tokens = tokenizer.tokenize();


    Parser parser(std::move(tokens));
    std::optional<NodeExit> tree = parser.parse();

    if (!tree.has_value()) {
        std::cout << "No Exit Statement Found" << std::endl;
        exit(EXIT_FAILURE);
    }

    Generator generator(tree.value());

    {
        std::fstream file("out.asm", std::ios::out);
        file << generator.generate();
    }

    system("nasm -felf64 out.asm -o out.o");
    system("ld out.o -o out");


    return EXIT_SUCCESS;
}