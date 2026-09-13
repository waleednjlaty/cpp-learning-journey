#include <iostream>
using namespace std;
template <typename T1, typename T2>
struct myPair
{
    T1 first;
    T2 second;
    myPair() : first(T1()), second(T2()) {}
    myPair(const T1& a, const T2& b) : first(a), second(b) {}
    bool operator==(const myPair<T1, T2> &other) const
    {
        return (first == other.first && second == other.second);
    }
    bool operator!=(const myPair<T1, T2> &other) const
    {
        return !(*this == other);
    }
    bool operator<(const myPair<T1, T2> &other) const
    {
        if (first < other.first)
            return true;
        if (other.first < first)
            return false;
        return second < other.second;
    }
};

template <typename T1, typename T2>
myPair<T1, T2> myMakePair(T1 a, T2 b)
{
    return myPair<T1, T2>(a, b);
}