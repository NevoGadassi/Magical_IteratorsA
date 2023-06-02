#ifndef MAGICALCONTAINER_HPP
#define MAGICALCONTAINER_HPP

#include "MisticalElementNode.hpp"

namespace ariel
{
    class MagicalContainer // NOLINT
    {
    public:
        MagicalContainer();
        ~MagicalContainer();
        void addElement(int value);
        void removeElement(int value);
        int size() const;

    private:
        // helpers methods
        bool isPrime(int num) const;
        void insertNode_asc(MisticalElementNode *pNode);
        void insertNode_prime(MisticalElementNode *pNode);
        MisticalElementNode *removeNode_asc(int value);
        MisticalElementNode *removeNode_prime(int value);
        void printLinkedListAscNext() const;
        void printLinkedListAscBack() const;
        void printLinkedListPrimeNext() const;
        void printLinkedListPrimeBack() const;

        // members
        MisticalElementNode *_head;
        MisticalElementNode *_tail;
        MisticalElementNode *_primeHead;
        MisticalElementNode *_primeTail;
        int _size;
        int _primeSize;
    
    // code for Iterators in extrenal hpp files.
    // https://stackoverflow.com/questions/28176371/how-can-i-avoid-this-ugly-nested-class-c-code
    public:
        class AscendingIterator;
        class SideCrossIterator;
        class PrimeIterator;
    };


    class MagicalContainer::AscendingIterator // NOLINT
    {
    private:
        MagicalContainer& _container;
        MisticalElementNode *_pElement;
        int _stepsNo;
        
    public:
        AscendingIterator(MagicalContainer& container);
        AscendingIterator(AscendingIterator& other);
        ~AscendingIterator();

        // operatores
        AscendingIterator& operator=(const AscendingIterator& other);
        AscendingIterator& operator++(); // pre
        int operator*();
        bool operator!=(const AscendingIterator& other) const;
        bool operator==(const AscendingIterator& other) const;
        bool operator>(const AscendingIterator& other) const;
        bool operator<(const AscendingIterator& other) const;

        AscendingIterator begin();
        AscendingIterator end();
    };


    class MagicalContainer::SideCrossIterator // NOLINT
    {
    private:
        MagicalContainer& _container;
        MisticalElementNode *_pElementFromStart;
        MisticalElementNode *_pElementFromEnd;
        bool _moveFromStart;
        int _stepsNo;
        
    public:
        SideCrossIterator(MagicalContainer& container);
        SideCrossIterator(SideCrossIterator& other);
        ~SideCrossIterator();

        // operatores
        SideCrossIterator& operator=(const SideCrossIterator& other);
        SideCrossIterator& operator++(); // pre
        int operator*();
        bool operator!=(const SideCrossIterator& other) const;
        bool operator==(const SideCrossIterator& other) const;
        bool operator>(const SideCrossIterator& other) const;
        bool operator<(const SideCrossIterator& other) const;

        SideCrossIterator begin();
        SideCrossIterator end();
    };


    class MagicalContainer::PrimeIterator // NOLINT
    {
    private:
        MagicalContainer& _container;
        MisticalElementNode *_pElement;
        int _stepsNo;
        
    public:
        PrimeIterator(MagicalContainer& container);
        PrimeIterator(PrimeIterator& other);
        ~PrimeIterator();

        // operatores
        PrimeIterator& operator=(const PrimeIterator& other);
        PrimeIterator& operator++(); // pre
        int operator*();
        bool operator!=(const PrimeIterator& other) const;
        bool operator==(const PrimeIterator& other) const;
        bool operator>(const PrimeIterator& other) const;
        bool operator<(const PrimeIterator& other) const;

        PrimeIterator begin();
        PrimeIterator end();
    };
};

#endif // !MAGICALCONTAINER_HPP