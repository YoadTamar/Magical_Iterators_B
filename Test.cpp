#include "doctest.h"
#include "sources/MagicalContainer.hpp"
#include <stdexcept>

using namespace std;


TEST_CASE("Test MagicalContainer") {

    MagicalContainer container;

    container.addElement(1);
    CHECK(container.size() == 1);

    container.addElement(10);
    container.addElement(20);
    container.addElement(30);
    CHECK(container.size() == 4);

    CHECK_NOTHROW(container.removeElement(10));
    CHECK(container.size() == 3);

    CHECK_THROWS_AS(container.removeElement(90), runtime_error);

    
}

TEST_CASE("Test AscendingIterator")
{
    MagicalContainer container;
    container.addElement(10);
    container.addElement(20);

    MagicalContainer::AscendingIterator it(container);
    CHECK(*it == 10);
    ++it;
    CHECK(*it == 20);
    ++it;
    CHECK(it == it.end());

    MagicalContainer emptyContainer;
    MagicalContainer::AscendingIterator it2(emptyContainer);
    CHECK(it2 == it2.end());

}

TEST_CASE("Test SideCrossIterator")
{
    MagicalContainer container;
    container.addElement(10);
    container.addElement(20);
    container.addElement(40);

    MagicalContainer::SideCrossIterator it(container);
    CHECK(*it == 10);
    ++it;
    CHECK(*it == 40);
    ++it;
    CHECK(*it == 20);
    ++it;
    CHECK(it == it.end());

    MagicalContainer emptyContainer;
    MagicalContainer::SideCrossIterator it2(emptyContainer);
    CHECK(it2 == it2.end());
}

TEST_CASE("Test PrimeIterator") {
    MagicalContainer container;
    container.addElement(1);
    container.addElement(2);
    container.addElement(3);
    container.addElement(4);
    container.addElement(5);

    MagicalContainer::PrimeIterator it(container);
    CHECK(*it == 2);
    ++it;
    CHECK(*it == 3);
    ++it;
    CHECK(*it == 5);
    ++it;
    CHECK(it == it.end());

    MagicalContainer emptyContainer;
    MagicalContainer::PrimeIterator it2(emptyContainer);
    CHECK(it2 == it2.end());  
}

TEST_CASE("Test PrimeIterator ---- 2")
{
    MagicalContainer container;
    container.addElement(4);
    container.addElement(6);

    SUBCASE("Iterating over elements") {
        MagicalContainer::PrimeIterator it(container);

        CHECK(it == it.end());
        CHECK_THROWS_AS(++it, runtime_error);
    }
}

TEST_CASE("Test side-cross order") {
    MagicalContainer container;
    container.addElement(1);
    container.addElement(2);
    container.addElement(4);
    container.addElement(5);
    container.addElement(14);

    //1 14 2 5 4
    MagicalContainer::SideCrossIterator it(container);
    CHECK(*it == 1);
    ++it;
    CHECK(*it == 14);
    ++it;
    CHECK(*it == 2);
    ++it;
    CHECK(*it == 5);
    ++it;
    CHECK(*it == 4);
    ++it;
    CHECK(it == it.end());
}

TEST_CASE("Test iterators") {
    MagicalContainer container;
    container.addElement(1);
    container.addElement(2);
    container.addElement(3);
    container.addElement(4);
    container.addElement(5);

    SUBCASE("Comparing AscendingIterator") {
        MagicalContainer::AscendingIterator it1(container);
        MagicalContainer::AscendingIterator it2(container);
        CHECK(it1 == it2);
        CHECK(!(it1 != it2));
        CHECK(!(it1 < it2));
        CHECK(!(it1 > it2));

        //check after change 
        ++it1;
        CHECK_FALSE((it1 == it2));
        CHECK((it1 != it2));
        CHECK((it1 > it2));
        CHECK_FALSE((it1 < it2));
    }
    

    SUBCASE("Comparing SideCrossIterator") {
        MagicalContainer::SideCrossIterator it1(container);
        MagicalContainer::SideCrossIterator it2(container);
        CHECK(it1 == it2);
        CHECK(!(it1 != it2));
        CHECK(!(it1 < it2));
        CHECK(!(it1 > it2));

        ++it1;
        CHECK_FALSE((it1 == it2));
        CHECK((it1 != it2));
        CHECK_FALSE((it1 < it2));
        CHECK((it1 > it2));
    }

    SUBCASE("Comparing PrimeIterator") {
        MagicalContainer::PrimeIterator it1(container);
        MagicalContainer::PrimeIterator it2(container);
        CHECK(it1 == it2);
        CHECK(!(it1 != it2));
        CHECK(!(it1 < it2));
        CHECK(!(it1 > it2));

        ++it1;
        CHECK_FALSE((it1 == it2));
        CHECK((it1 != it2));
        CHECK_FALSE((it1 < it2));
        CHECK((it1 > it2));
    }


}
