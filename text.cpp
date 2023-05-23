#include <iostream>
#include <fstream>
#include <sstream>
#include "text.h"

const std::string& Text::getFName() const
{
    return mFName;
}

void Text::setFName(const std::string& fName)
{
    mFName = fName;
}
    
const std::vector<Word*>& Text::getWords() const
{
    return mWords;
}

void Text::setWords(const std::vector<Word*>& words)
{
    mWords = words;
}

std::string Text::toLow(const std::string& word) 
{
    std::string tmp = word;
    for (char& ch : tmp) 
    {
        if (ch >= 'A' && ch <= 'Z') 
        {
            ch = ch + 32;
        }
    }
    return tmp;
}

bool Text::checkDir(const std::string& word)
{
    std::ifstream dirFile("words_alpha.txt");
    if (!dirFile.is_open()) 
    {
        std::cerr << "Failed to open the dictionary file." << std::endl;
        return false;
    }
    std::string dWord;
    while (dirFile >> dWord) 
    {
        if (dWord == word) 
        {
            dirFile.close();
            return true;
        }
    }
    dirFile.close();
    return false;
}

std::string Text::toUpp(const std::string& word) 
{
    std::string tmp = word;
    for (auto ch : word) 
    {
        if (ch >= 'A' && ch <= 'Z') 
        {
            ch = ch - 32;
        }
    }
    return tmp;
}


std::string Text::cleanText(const std::string& word)
{
    std::string clnWord;
    for (char ch : word) 
    {
        if (!std::isalnum(ch) || std::isdigit(ch)) 
        {
            ch = ' ';
        }
        clnWord += ch;
    }
    return toLow(clnWord);
}

void Text::readFile(const std::string& fName)
{
    int fI = std::stoi(fName.substr(0, fName.find('.')));

    std::ifstream inFile(fName);
    if (!inFile) 
    {
        std::cerr << "Failed to open the input file." << std::endl;
        return;
    }
    std::string word;

    while (inFile >> word) 
    {
        Word* tmp = new Word();
        tmp->setData(cleanText(word));
        mWords.push_back(tmp);
    }

    inFile.close();
    std::ofstream outFile("db.txt", std::ios::app);
    if (!outFile) 
    {
        std::cerr << "Failed to open the output file." << std::endl;
        return;
    }
    for (auto& word : mWords) 
    {
        outFile << word->getData() << " :   " << fI << std::endl;
    }
    outFile.close();
    std::cout << "Words saved to db.txt." << std::endl;
}

void Text::searchWord(const std::string& word)
{
    std::ifstream inFile("db.txt");
    if (!inFile)
    {
        std::cerr << "Failed to open the db.txt file." << std::endl;
        return;
    }
    std::string line;
    std::vector<std::string> fileNames;

    while (std::getline(inFile, line))
    {
        if (line.find(word) != std::string::npos)
        {
            fileNames.push_back(line);
        }
    }

    inFile.close();

    if (fileNames.empty())
    {
        std::cout << "No matching words found." << std::endl;
    }
    else
    {
        std::cout << "Matching words found in the following file(s):" << std::endl;
        for (const auto& fileName : fileNames)
        {
            std::cout << fileName << std::endl;
        }
    }
}

