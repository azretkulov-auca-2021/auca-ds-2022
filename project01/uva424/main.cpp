#include <bits/stdc++.h>

class BigInt
{
    friend std::ostream &operator<<(std::ostream &out, const BigInt &x);
    friend std::istream &operator>>(std::istream &inp, const BigInt &x);
    friend BigInt operator+(const BigInt &x, const BigInt &y);
    friend bool operator==(const BigInt &x, const BigInt &y);
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
        if (s.empty())
        {
            throw std::runtime_error("BigInteger value cannot be empty");
        }

        int i = 0;
        if (s[i] == '-' || s[i] == '+')
        {
            if (s[i] == '-')
            {
                mIsNegative = true;
            }
            ++i;
        }

        while (i < (int)s.size())
        {
            if (!isdigit(s[i]))
            {
                throw std::runtime_error("Incorrect format of BigInteger");
            }

        mDigits.push_back(s[i] - '0');
        ++i;
        }

        if (mDigits.empty())
        {
            throw std::runtime_error("Incorrect format of BigInteger");
        }
    }

    BigInt(long long x)
        : BigInt(std::to_string(x))
    {
    }

    BigInt &operator+=(const BigInt &x)
    {
        *this = *this + x;
        return *this;
    }
private:
    static BigInt addAbsValues(const BigInt &x, const BigInt &y)
    {
        auto itX = x.mDigits.rbegin();
        auto itY = y.mDigits.rbegin();

        BigInt z;
        z.mDigits.resize(std::max(x.mDigits.size(), y.mDigits.size()) + 1);
        auto itZ = z.mDigits.rbegin();

        int carry = 0;

        while (itX != x.mDigits.rend() || itY != y.mDigits.rend())
        {
            int s = carry;
            if (itX != x.mDigits.rend())
            {
                s += *itX;
                ++itX;
            }
            if (itY != y.mDigits.rend())
            {
                s += *itY;
                ++itY;
            }
            *itZ = s % 10;
            carry = (s > 9) ? 1 : 0;
            ++itZ;
        }
        if (carry != 0)
        {
            *itZ = carry;
        }
        if (z.mDigits.size() > 1 && z.mDigits.front() == 0)
        {
            z.mDigits.erase(z.mDigits.begin());
        }

        return z;
    }
};

inline bool operator==(const BigInt &x, const BigInt &y)
{
    return x.mIsNegative == y.mIsNegative && x.mDigits == y.mDigits;
}

inline BigInt operator+(const BigInt &x, const BigInt &y)
{   
    BigInt z = BigInt::addAbsValues(x, y);
    return z;
}

inline std::ostream &operator<<(std::ostream &out, const BigInt &x)
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

inline std::istream &operator>>(std::istream &inp, BigInt &x)
{
    //   а нужно ли эти чар?
    char ch;
    if (!(inp >> ch))
    {
        return inp;
    }

    if (!(isdigit(ch) || ch == '+' || ch == '-'))
    {
        inp.putback(ch);
        inp.setstate(std::ios_base::failbit);
        return inp;
    }

    std::string s;
    s += ch;

    while (inp.get(ch) && isdigit(ch))
    {
        s += ch;
    }

    if (inp)
    {
        inp.putback(ch);
    }

    if (s.size() == 1 && (s[0] == '+' || s[0] == '-'))
    {
        inp.setstate(std::ios_base::failbit);
        return inp;
    }

    x = BigInt(s);

    return inp;
}

template <typename C>
int sz(const C &c) { return static_cast<int>(c.size()); }

using namespace std;

int main()
{
    iostream::sync_with_stdio(false);
    
    BigInt sum = 0;
    for (BigInt x; cin >> x;)
    {
        if (x == 0)
        {
            break;
        }

        sum += x;
    }

    cout << sum << "\n";
}