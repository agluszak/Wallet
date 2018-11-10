#include <iostream>
#include "wallet.h"


int main()
{
    Wallet w{6};
    Wallet a{std::move(w)};
    Wallet s{"123"};
    Wallet b = Wallet::fromBinary("101");
    Wallet sum{Wallet(7), Wallet(20)};

    std::cout << w.getUnits() << '\n' << a.getUnits()
            << '\n' << s.getUnits() << '\n' << b.getUnits()
            << '\n' << sum.getUnits();

    return 0;
}