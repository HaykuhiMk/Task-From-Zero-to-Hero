#include <iostream>
#include "word.h"

const std::string& Word::getData() const
    {
        return mData;
    }

void Word::setData(const std::string& data)
{  
    mData = data;
}
