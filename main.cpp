#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include "text.h"


int main()
{
    Text text;
    text.readFile("1.txt");
    std::cout << std::endl;
    text.readFile("2.txt");
    std::string searchWord;
    std::cout << "Enter a word to search: ";
    std::cin >> searchWord;
    text.searchWord(searchWord);
    return 0;
}