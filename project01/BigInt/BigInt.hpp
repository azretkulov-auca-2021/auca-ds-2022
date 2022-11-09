#pragma once

#include <vector>
#include <iostream>
#include <string>
#include <stdexcept>
#include <cctype>

class BigInt
{
    friend std::ostream &operator <<(std::ostream &out, const BigInt &x);

    std::vector<int> mDigits;
    bool mIsNegative;

public:
    BigInt()
    : mIsNegative(false) 
    {
        mDigits.push_back(0);
    }

    BigInt(const std::string &s)
        : mIsNegative(false)
    {
        if(s.empty())
        {
            throw std::runtime_error("value is empty");
        }

        for (auto d : s)
        {
            mDigits.push_back(d - '0');
        }
    }
};

inline std::ostream &operator <<(std::ostream &out, const BigInt &x)
{
   if (x.mIsNegative)
   {
       out << "-";
   }
   for (auto digit : x.mDigits)
   {
       out << digit;
   }

   return out;
}