#include "doctest.h"
#include "sources/MagicalContainer.hpp"
#include <iostream>
#include <stdexcept>

using namespace ariel;


TEST_CASE("Create container")
{
    CHECK_NOTHROW(MagicalContainer());
}


TEST_CASE("add items")
{
    MagicalContainer container;

    CHECK(container.size() == 0);

    container.addElement(5);
    container.addElement(26);
    container.addElement(3);
    container.addElement(7);
    container.addElement(12);

    CHECK(container.size() == 5); 
    container.removeElement(7);
    CHECK(container.size() == 4); 
    CHECK_THROWS_AS(container.removeElement(7), std::runtime_error);
    container.removeElement(5);
    CHECK(container.size() == 3); 
    container.removeElement(26);
    container.removeElement(12);
    CHECK(container.size() == 1); 
}

TEST_CASE("Ascending Iterator")
{
    MagicalContainer container;
    MagicalContainer container2;
    MagicalContainer::AscendingIterator ascIter(container);
    MagicalContainer::AscendingIterator ascIter2(container2);
    MagicalContainer::AscendingIterator it2=ascIter.begin() ;
    MagicalContainer::AscendingIterator it1=ascIter.end() ;
    CHECK(it1==it2); 
    it2=ascIter2.begin(); 
     it1=ascIter2.end() ;
    CHECK(it1==it2); 
    container.addElement(22);
    container.addElement(15);
    container.addElement(3);
    container.addElement(1);
    container.addElement(9);
    container2.addElement(9);
    container2.addElement(3);
    container2.addElement(16);
    container2.addElement(2);
    CHECK(*ascIter.begin() == 1);
    CHECK(*ascIter2.begin() == 2);

    CHECK_THROWS_AS(ascIter.operator==(ascIter2), std::invalid_argument); 
    CHECK_THROWS_AS(ascIter.operator>(ascIter2),  std::invalid_argument); 
    CHECK_THROWS_AS(ascIter.operator<(ascIter2),  std::invalid_argument); 
    CHECK(*ascIter.begin() == 1);
    CHECK(*(++ascIter) == 3);
    CHECK(*(++ascIter) == 9);
    CHECK(*(++ascIter) == 15);
    CHECK(*(++ascIter) == 22);
    container.addElement(13);

}


TEST_CASE("sideCross Iterator")
{
    MagicalContainer mc;
    MagicalContainer::SideCrossIterator si(mc);
    int elements[] = {3, 4, 6, 7, 11, 9, 10, 5, 1, 2, 12, 8};
    for(int i = 0; i < 12; i++)
    {
        mc.addElement(elements[i]);
    }
    auto it = si.begin();
    CHECK(*it == 1);
    ++it;
    CHECK(*it == 12);
    ++it;
    CHECK(*it == 2);
    ++it;
    CHECK(*it == 11);
    ++it;
    CHECK(*it == 3);
    ++it;
    CHECK(*it == 10);
    ++it;
    CHECK(*it == 4);
    ++it;
    CHECK(*it == 9);
    ++it;
    CHECK(*it == 5);
    ++it;
    CHECK(*it == 8);
    ++it;
    CHECK(*it == 6);
    ++it;
    CHECK(*it == 7);
    ++it;
    CHECK(it == si.end());
    auto it1 = si.begin();
    MagicalContainer::SideCrossIterator it2(it1);
    CHECK(it1 == it2);
    ++it2;
    CHECK(it1 < it2);
    CHECK(it2 > it1);
}


TEST_CASE("Prime Iterator")
{
    MagicalContainer container;
    MagicalContainer :: PrimeIterator primeIter(container);
    container.addElement(1);
    container.addElement(2);
    container.addElement(3);
    container.addElement(4);
    container.addElement(5);

    SUBCASE("Iterating In Prime Order") {
        CHECK_EQ(*primeIter, 2);
        ++primeIter;
        CHECK_EQ(*primeIter, 3);
        ++primeIter;
        CHECK_EQ(*primeIter, 5);
    }
    SUBCASE("Deleting Items While Iterating") {
        MagicalContainer :: PrimeIterator primeIter1(container);
        CHECK_EQ(*primeIter1, 2);
        ++primeIter1;
        CHECK_EQ(*primeIter1, 3);
        container.removeElement(2);
        CHECK_EQ(container.size(), 4);
        CHECK_EQ(*primeIter1, 3);
        container.removeElement(5);
        CHECK_EQ(container.size(), 3);
        CHECK_EQ(*primeIter1, 3);
        ++primeIter1;
        CHECK_EQ(primeIter1, primeIter1.end());
    }
}
