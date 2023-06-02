#include "MagicalContainer.hpp"
#include <iostream>

using std::cout;
using std::endl;

using namespace ariel;

// C'TOR
MagicalContainer::MagicalContainer()
{
    _size = 0;
    _primeSize = 0;
    _head = nullptr;
    _tail = nullptr;
    _primeHead = nullptr;
};


// D'TOR
MagicalContainer::~MagicalContainer()
{
    while(_size > 0)
    {
        removeElement(_head->value());
    }
};


/***************************    API    *****************************/
void MagicalContainer::addElement(int value)
{
    MisticalElementNode *pNewNode = new MisticalElementNode(value);
    insertNode_asc(pNewNode);
    _size++;

    if(isPrime(value))
    {
        insertNode_prime(pNewNode);
        _primeSize++;
    }
};

void MagicalContainer::removeElement(int value)
{
    MisticalElementNode *pRemoved  = removeNode_asc(value);
    
    if(isPrime(value))
    {
        if(removeNode_prime(value) != nullptr) // same address as pRemoved..
        {
            _primeSize--;
        }
    }

    // delete memory.
    if(pRemoved != nullptr) 
    {   
        delete pRemoved;
        _size--;
    }
};

int MagicalContainer::size() const
{
    return _size;
}
/*******************************************************************/



/*******************  INSERT TO THE LINKED-LISTS  ******************/
void MagicalContainer::insertNode_asc(MisticalElementNode *pNode)
{
    // for first node
    if(_head == nullptr)
    {
        _head = pNode;
        _tail = pNode;

        return;
    }

    // in case we need to change the head:
    if(pNode->value() < _head->value())
    {
        // update pointers
        pNode->setAscNext(_head);
        _head->setAscBack(pNode);


        // replace the head
        _head = pNode;
        
        return;
    }

    // all other cases: find the node will be before new node.
    MisticalElementNode *pCurr = _head;
    while(pCurr->getAscNext() && pCurr->getAscNext()->value() < pNode->value())
    {
        pCurr = pCurr->getAscNext();
    }

    // 2 options here: 'middle' or after tail..
    if(pCurr->getAscNext() == nullptr)                   // tail case
    {
        // update pointers
        pNode->setAscBack(pCurr);
        pCurr->setAscNext(pNode);

        // replace the tail
        _tail = pNode;
    }
    else                                                 // 'middle' case
    {
        // update pointers of new Node
        pNode->setAscBack(pCurr);
        pNode->setAscNext(pCurr->getAscNext());

        // updates pointers of two nodes we disconnect them
        pCurr->setAscNext(pNode);
        pNode->getAscNext()->setAscBack(pNode);
    }
}

void MagicalContainer::insertNode_prime(MisticalElementNode *pNode)
{
    // for first prime node
    if(_primeHead == nullptr)
    {
        _primeHead = pNode;
        _primeTail = pNode;

        return;
    }

    // in case we need to change the head of primes:
    if(pNode->value() < _primeHead->value())
    {
        // update pointers
        pNode->setPrimeNext(_primeHead);
        _primeHead->setPrimeBack(pNode);


        // replace the head of primes
        _primeHead = pNode;
        
        return;
    }

    // all other cases: find the node will be before new node.
    MisticalElementNode *pCurr = _primeHead;
    while(pCurr->getPrimeNext() && pCurr->getPrimeNext()->value() < pNode->value())
    {
        pCurr = pCurr->getPrimeNext();
    }

    // 2 options here: 'middle' or after tail of primes
    if(pCurr->getPrimeNext() == nullptr)                   // prime-tail case
    {
        // update pointers
        pNode->setPrimeBack(pCurr);
        pCurr->setPrimeNext(pNode);

        // replace the tail
        _primeTail = pNode;
    }
    else                                                 // 'middle' case
    {
        // update pointers of new Node
        pNode->setPrimeBack(pCurr);
        pNode->setPrimeNext(pCurr->getPrimeNext());

        // updates pointers of two nodes we disconnect them
        pCurr->setPrimeNext(pNode);
        pNode->getPrimeNext()->setPrimeBack(pNode);
    }
}
/*******************************************************************/



/******************  REMOVE FROM THE LINKED-LISTS  *****************/
MisticalElementNode *MagicalContainer::removeNode_asc(int value)
{   
    if(_size == 0) return nullptr;

    MisticalElementNode *pRemoved = nullptr;

    if(_size == 1)
    {
        // save pointer to node will be delete
        pRemoved = _head;

        // update pointers
        _head = nullptr;
        _tail = nullptr;
    }

    // if we need to remove the first Node
    else if(value == _head->value())
    {
        // save pointer to node will be delete
        pRemoved = _head;

        // update the new head
        _head = _head->getAscNext();
        _head->setAscBack(nullptr);

        // 'clean' the removed node pointers.
        pRemoved->setAscNext(nullptr);
    }

    //if we need to remove the tail Node
    else if(value == _tail->value())
    {
        // save pointer to node will be delete
        pRemoved = _tail;

        // update new tail
        _tail = _tail->getAscBack();

        // update pointers.
        _tail->setAscNext(nullptr);

        // 'clean' the removed node pointers.
        pRemoved->setAscBack(nullptr);
    }
    else
    {
        // find the node will remove
        MisticalElementNode *pCurr = _head;
        while(pCurr)
        {
            if(value == pCurr->value())
            {
                pRemoved = pCurr;
                break;
            }
            else pCurr = pCurr->getAscNext();
        }

        // if we found node to delete..
        if(pRemoved != nullptr)
        {
            // update pointers
            pRemoved->getAscBack()->setAscNext(pRemoved->getAscNext());
            pRemoved->getAscNext()->setAscBack(pRemoved->getAscBack());

            // 'clean' the removed node pointers.
            pRemoved->setAscNext(nullptr);
            pRemoved->setAscBack(nullptr);
        }
    }

    return pRemoved;
}

MisticalElementNode *MagicalContainer::removeNode_prime(int value)
{   
    if(_primeSize == 0) return nullptr;

    MisticalElementNode *pRemoved = nullptr;

    if(_primeSize == 1)
    {
        // save pointer to node will be delete
        pRemoved = _primeHead;

        // update pointers
        _primeHead = nullptr;
        _primeTail = nullptr;
    }

    // if we need to remove the first Node
    else if(value == _primeHead->value())
    {
        // save pointer to node will be delete
        pRemoved = _primeHead;

        // update the new head
        _primeHead = _primeHead->getPrimeNext();
        _primeHead->setPrimeBack(nullptr);

        // 'clean' the removed node pointers.
        pRemoved->setPrimeNext(nullptr);
    }

    //if we need to remove the tail Node
    else if(value == _primeTail->value())
    {
        // save pointer to node will be delete
        pRemoved = _primeTail;

        // update new tail
        _primeTail = _primeTail->getPrimeBack();

        // update pointers.
        _primeTail->setPrimeNext(nullptr);

        // 'clean' the removed node pointers.
        pRemoved->setPrimeBack(nullptr);
    }
    else
    {
        // find the node will remove
        MisticalElementNode *pCurr = _primeHead;
        while(pCurr)
        {
            if(value == pCurr->value())
            {
                pRemoved = pCurr;
                break;
            }
            else pCurr = pCurr->getPrimeNext();
        }

        // if we found node to delete..
        if(pRemoved != nullptr)
        {
            // update pointers
            pRemoved->getPrimeBack()->setPrimeNext(pRemoved->getPrimeNext());
            pRemoved->getPrimeNext()->setPrimeBack(pRemoved->getPrimeBack());

            // 'clean' the removed node pointers.
            pRemoved->setPrimeNext(nullptr);
            pRemoved->setPrimeBack(nullptr);
        }
    }

    return pRemoved;
}
/*******************************************************************/


bool MagicalContainer::isPrime(int num) const
{
    if (num <= 1) return false;

    for(int i = 2; i * i <= num; i++)
    {
        if(num % i == 0) return false;
    }

    return true;
};


/*********************  PRINT THE LINKED-LISTS *********************/
void MagicalContainer::printLinkedListAscNext() const
{
    MisticalElementNode *pCurr = _head;

    while(pCurr)
    {
        cout << *pCurr << " --> ";
        pCurr = pCurr->getAscNext();
    }
    cout << "NULL" << endl;
}

void MagicalContainer::printLinkedListAscBack() const
{
    MisticalElementNode *pCurr = _tail;

    while(pCurr)
    {
        cout << *pCurr << " --> ";
        pCurr = pCurr->getAscBack();
    }
    cout << "NULL" << endl;
}

void MagicalContainer::printLinkedListPrimeNext() const
{
    MisticalElementNode *pCurr = _primeHead;

    while(pCurr)
    {
        cout << *pCurr << " --> ";
        pCurr = pCurr->getPrimeNext();
    }
    cout << "NULL" << endl;
}

void MagicalContainer::printLinkedListPrimeBack() const
{
    MisticalElementNode *pCurr = _primeTail;

    while(pCurr)
    {
        cout << *pCurr << " --> ";
        pCurr = pCurr->getPrimeBack();
    }
    cout << "NULL" << endl;
}
/*******************************************************************/