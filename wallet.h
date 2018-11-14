//
// Class allowing for crypto currency transactions with the limited amount
// of coins in the universe. It also keeps track of all of the operations' history.
//

#include <string>
#include <type_traits>


// Class for keeping track of the transaction history.
class History
{

};


//template <typename T>
//using IntegerType = std::enable_if_t<std::is_same_v<T, int> || std::is_same_v<T, short> ||
//        std::is_same_v<T, long long>>;


class Wallet
{

public:

    // Returns a new Wallet object with the number of coins equal
    // to the str written in binary
    static Wallet fromBinary(const std::string &str);

    Wallet() = default;

    // Constructs a new Wallet with n coins. Throws an exception if new coins
    // would exceed the limit.
    //template <typename T, typename = IntegerType<T>>
    Wallet(long long n);

    // Constructs a new Wallet with the number of coins equal
    // to the str. It ignores trailing whitespaces and can accept
    // a non-integer value separated by either a comma or a period.
    // Throws an exception if new coins would exceed the limit.
    explicit Wallet(const std::string &str);

    // A move constructor. Copy construction is not allowed.
    Wallet(Wallet &&other) noexcept;

    // Constructs a new Wallet object by moving all coins from w1 and w2 into it
    // and combining their history. Both w1 and w2 are left empty after the call.
    Wallet(Wallet &&w1, Wallet &&w2) noexcept;

    Wallet(Wallet &other) = delete;

    // TODO: Overload operators

    // Returns index-th oldest operation from history, counting from 0
    const std::string& operator[](size_t index) const;

    // Returns number of coins currently in the Wallet
    long long getUnits() const;

    // Returns number of operations in the Wallet's history
    int opSize() const;

private:

    static const long long LIMIT {(long long)21e6};
    static long long totalCoins;

    long long coins {0}; // TODO: change it to allow for non-integer values
    History history {}; // TODO: Consider whether a separate class is really necessary

};


// Returns an empty Wallet object that is immutable
const Wallet Empty();


bool operator<(Wallet &&left, Wallet &&right);