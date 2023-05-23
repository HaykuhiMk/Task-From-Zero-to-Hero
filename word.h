#ifndef WORD_H
#define WORD_H

class Word
{
public:
    const std::string& getData() const;
    void setData(const std::string& data);

private:
    std::string mData;
};

#endif  //WORD_H