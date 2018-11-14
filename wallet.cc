// Implementation of the Wallet class

#include <iostream>
#include "wallet.h"


long long Wallet::totalCoins = 0;

//template <typename T, typename = IntegerType<T>>
Wallet::Wallet(long long n) : coins(n)
{
    // TODO: Decide what exception to throw if new coins exceeded the limit. Maybe custom one?
    totalCoins += coins;
    std::cout << "Constructor call with " << coins << "\n";
};

Wallet::Wallet(const std::string &str) : coins(std::stoll(str))
{
    // TODO: Decide what exception to throw if new coins exceeded the limit. Maybe custom one?
    totalCoins += coins;
};

Wallet Wallet::fromBinary(const std::string &str)
{
    return Wallet(std::stoll(str, nullptr, 2));
};

Wallet::Wallet(Wallet &&other) noexcept
{
    coins = other.coins;
    other.coins = 0;
    history = other.history; // TODO: add new entry
};

Wallet::Wallet(Wallet &&w1, Wallet &&w2) noexcept
{
    coins = w1.coins + w2.coins;
    // TODO: combine histories
}

const std::string& Wallet::operator[](size_t index) const
{
    return "";
}

long long Wallet::getUnits() const
{
    return coins;
}

int Wallet::opSize() const
{
    return 0;
}

const Wallet Empty()
{
    return Wallet();
}

bool operator<(Wallet &&left, Wallet &&right)
{
    return 1;
}