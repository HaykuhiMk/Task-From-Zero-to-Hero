#ifndef TEXT_H
#define TEXT_H
#include <vector>
#include "word.h"

class Text
{
public:
    const std::string& getFName() const;
    void setFName(const std::string& fName);
    const std::vector<Word*>& getWords() const;
    void setWords(const std::vector<Word*>& words);
    void readFile(const std::string&);
    std::string cleanText(const std::string&);
    std::string toLow(const std::string& word); 
    std::string toUpp(const std::string& word); 
    bool checkDir(const std::string&);
    void searchWord(const std::string& word);

private:
    std::string mFName;
    std::vector<Word*> mWords;
};

#endif  //TEXT_H