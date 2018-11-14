#include <iostream>
#include <type_traits>
#include "wallet.h"


template <typename Type, typename From>
using is_implicitly_constructible = std::bool_constant<
        std::is_constructible<Type, From>::value &&
        std::is_convertible<From, Type>::value>;


// TODO: Change value printing to assertions or binary results (OK/ERROR)
// TODO: Possibly move those checks to functions to support generalization

int main()
{
    using std::cout;

    cout << "\n----------Unit tests----------\n\n\n";

    cout << "> Default Constructor:\n\n";
    {
        Wallet w;
        cout << "   Implicit constructor call: " << w.getUnits() << "\n";
    }
    cout << "   Explicit constructor call: " << Wallet().getUnits() << "\n";
    {
        Wallet w{};
        cout << "   Empty initializer list: " << w.getUnits() << "\n";
    }
    cout << "\n";

    cout << "> Integer Constructor:\n\n";
    cout << "   Explicit constructor call: " << Wallet(5).getUnits() << "\n";
    {
        Wallet w{5};
        cout << "   Initializer list: " << w.getUnits() << "\n";
    }
    {
        Wallet w = 5;
        cout << "   Implicit conversion call: " << w.getUnits() << "\n";
    }
    cout << "\n";

    cout << "> String Constructor:\n\n";
    cout << "   Explicit constructor call: " << Wallet("350").getUnits() << "\n";
    {
        Wallet w{"350"};
        cout << "   Initializer list: " << w.getUnits() << "\n";
    }
    cout << "\n";

    cout << "> Implicit Conversions:\n\n";
//    static_assert(!is_implicitly_constructible<Wallet, float>::value &&
//                  !is_implicitly_constructible<Wallet, double>::value,
//                  "Implicit conversion from float and double should not be allowed!");
//    cout << "   Implicit conversions from floating point values: OK\n";
//    static_assert(!is_implicitly_constructible<Wallet, std::string>::value &&
//                  !is_implicitly_constructible<Wallet, char*>::value &&
//                  !is_implicitly_constructible<Wallet, char>::value,
//                  "Implicit conversion from string, char and char* should not be allowed!");
//    cout << "   Implicit conversions from strings, chars and char*: OK\n";
//    static_assert(!is_implicitly_constructible<Wallet, bool>::value,
//                "Implicit conversion from bool should not be allowed!");
//    cout << "   Implicit conversion from bool: OK\n";
//    cout << "\n";

    666 < Wallet(10);

    return 0;
}