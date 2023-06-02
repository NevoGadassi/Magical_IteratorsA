#include "MagicalContainer.hpp"

using namespace ariel;


MagicalContainer::SideCrossIterator::SideCrossIterator(MagicalContainer& container)
    : _container(container)
{
    _stepsNo = 0;
    _pElementFromStart = nullptr;
    _pElementFromEnd = nullptr;
    _moveFromStart = true;           // Using as ping-pong flag say from where to go
};


MagicalContainer::SideCrossIterator::~SideCrossIterator(){};


MagicalContainer::SideCrossIterator::SideCrossIterator(SideCrossIterator& other)
    : _container(other._container)
{
    *this = other;
};


MagicalContainer::SideCrossIterator& MagicalContainer::SideCrossIterator::operator=(const SideCrossIterator& other)
{
    _container = other._container;
    _pElementFromStart = other._pElementFromStart;
    _pElementFromEnd = other._pElementFromEnd;
    _stepsNo = other._stepsNo;

    return *this;
};



MagicalContainer::SideCrossIterator& MagicalContainer::SideCrossIterator::operator++()
{
    if(_moveFromStart)
    {
        if(_pElementFromStart)
        {
            _pElementFromStart = _pElementFromStart->getAscNext();

            _moveFromStart = false;
            _stepsNo++;
        }
    }
    else
    {
        if(_pElementFromEnd)
        {
            _pElementFromEnd = _pElementFromEnd->getAscBack();

            _moveFromStart = true;
            _stepsNo++;
        }
    }

    return *this;
};


int MagicalContainer::SideCrossIterator::operator*()
{
    if(_moveFromStart)
    {
        if(_pElementFromStart == nullptr) throw "Ilegal iterator";

        return _pElementFromStart->value();
    }
    
    //else
    if(_pElementFromEnd == nullptr) throw "Ilegal iterator";

    return _pElementFromEnd->value();
};


bool MagicalContainer::SideCrossIterator::operator!=(const SideCrossIterator& other) const
{
    return _stepsNo != other._stepsNo;
};


bool MagicalContainer::SideCrossIterator::operator==(const SideCrossIterator& other) const
{
    return !(*this != other);
};


bool MagicalContainer::SideCrossIterator::operator>(const SideCrossIterator& other) const
{
    return _stepsNo > other._stepsNo;
};


bool MagicalContainer::SideCrossIterator::operator<(const SideCrossIterator& other) const
{
    return _stepsNo < other._stepsNo;
};


MagicalContainer::SideCrossIterator MagicalContainer::SideCrossIterator::begin()
{
    SideCrossIterator newIterator(_container);
    newIterator._pElementFromStart = _container._head;
    newIterator._pElementFromEnd = _container._tail;

    return newIterator;
};


MagicalContainer::SideCrossIterator MagicalContainer::SideCrossIterator::end()
{
    SideCrossIterator newIterator(_container);
    newIterator._stepsNo = _container._size;
    return newIterator;
};
