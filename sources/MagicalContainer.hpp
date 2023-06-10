#pragma once

#include "iostream"
#include "algorithm"
#include "vector"

namespace ariel
{
}

class MagicalContainer {
public:
    std::vector<int> container;
    std::vector<int*> primes;

    MagicalContainer(){}
    ~MagicalContainer(){for (int* ptr : primes) {
    delete ptr;
}}

    size_t size() const;
    bool isPrime(int);
    void addElement(int);
    void removeElement(int);

    class PrimeIterator{
    public:

        MagicalContainer* container;
        size_t index;
        int type = 2;

        PrimeIterator(MagicalContainer&);
        PrimeIterator(MagicalContainer&, size_t);
        PrimeIterator(const PrimeIterator&);
        ~PrimeIterator(){}

        PrimeIterator end() const;
        PrimeIterator begin() const;

        bool operator>(const PrimeIterator&) const;
        PrimeIterator& operator=(const PrimeIterator&);
        bool operator==(const PrimeIterator&) const;
        bool operator!=(const PrimeIterator&) const;
        int operator*();
        PrimeIterator& operator++();
        bool operator<(const PrimeIterator&) const;
    };
    class SideCrossIterator{
        public:

        MagicalContainer* container;
        size_t index;
        size_t side_index;

        SideCrossIterator(MagicalContainer&);
        SideCrossIterator(MagicalContainer&, size_t);
        SideCrossIterator(const SideCrossIterator&);
        ~SideCrossIterator(){}

        SideCrossIterator begin() const;
        SideCrossIterator end() const;

        bool operator>(const SideCrossIterator&) const;
        SideCrossIterator& operator=(const SideCrossIterator&);
        bool operator==(const SideCrossIterator&) const;
        bool operator!=(const SideCrossIterator&) const;
        int operator*();
        SideCrossIterator& operator++();
        bool operator<(const SideCrossIterator&) const;
    };

    class AscendingIterator{
        public:

        MagicalContainer*container;
        size_t index;
        int type = 1;

        AscendingIterator(MagicalContainer&);
        AscendingIterator(MagicalContainer&, size_t);
        AscendingIterator(const AscendingIterator&);
        ~AscendingIterator(){}

        AscendingIterator begin() const;
        AscendingIterator end() const;

        bool operator>(const AscendingIterator&) const;
        AscendingIterator& operator=(const AscendingIterator&);
        bool operator==(const AscendingIterator&) const;
        bool operator!=(const AscendingIterator&) const;
        int operator*();
        AscendingIterator& operator++();
        bool operator<(const AscendingIterator&) const;

    };
};