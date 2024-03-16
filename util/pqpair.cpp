#include "base.cpp"

struct myComp {
    constexpr bool operator()(
        pair<int, int> const& a,
        pair<int, int> const& b)
        const noexcept
    {
        // < para MAXHEAP, > para MINHEAP
        // first para ordenar pelo primero, second pelo segundo 
        return a.first < b.first;
    }
};