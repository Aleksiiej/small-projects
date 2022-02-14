#include "forwardList.hpp"

forwardList::~forwardList() // deletes all nodes when leaving scope
{
    if (ptrToFirst_ != nullptr)
    {
        Element *tempPtr = ptrToFirst_;
        Element *deletor = ptrToFirst_;

        for (int i = 0; i < (totalNumber - 1); i++)
        {
            tempPtr = tempPtr->ptrToNext_;
            delete deletor;
            deletor = tempPtr;
        }
        delete tempPtr;
        ptrToFirst_ = nullptr;
        totalNumber = 0;
    }
}

void forwardList::addElement(int number /*= 0*/) // adds node
{

    if (ptrToFirst_ == nullptr)
    {
        ptrToFirst_ = new Element(number);
        totalNumber = 1;
    }
    else
    {
        Element *newElement = new Element(number);
        Element *tempPtr = ptrToFirst_;
        while (tempPtr->ptrToNext_)
        {
            tempPtr = tempPtr->ptrToNext_;
        }
        tempPtr->ptrToNext_ = newElement;
        totalNumber++;
    }
}

void forwardList::deleteElement(int position) // deletes node
{
    if (position == 0)
    {
        Element *tempPtr;
        tempPtr = ptrToFirst_;
        ptrToFirst_ = tempPtr->ptrToNext_;
        delete tempPtr;
        totalNumber--;
        std::cout << std::endl;
    }
    else if (position > 0 && position < (totalNumber - 1))
    {
        auto [ptrToPrevNode, ptrToN, ptrToNextNode] = getPtrToRemoving(position);
        delete ptrToN;
        ptrToPrevNode->ptrToNext_ = ptrToNextNode;
        totalNumber--;
    }
    else if (position == (totalNumber - 1))
    {
        Element *tempPtr = ptrToFirst_;
        for (int i = 0; i < (totalNumber - 2); i++)
        {
            tempPtr = tempPtr->ptrToNext_;
        }
        Element *tempPtrDeletor;
        tempPtrDeletor = tempPtr->ptrToNext_;
        delete tempPtrDeletor;
        tempPtr->ptrToNext_ = nullptr;
        totalNumber--;
    }
}

void forwardList::showList() // shows all nodes
{
    if (ptrToFirst_ == nullptr)
    {
        std::cout << "List is empty" << std::endl;
    }
    else if (ptrToFirst_ != nullptr)
    {

        Element *tempPtr = ptrToFirst_;
        std::cout << tempPtr->number_ << " ";
        while (tempPtr->ptrToNext_)
        {
            tempPtr = tempPtr->ptrToNext_;
            std::cout << tempPtr->number_ << " ";
        }
        std::cout << std::endl;
    }
}

void forwardList::clear() // deletes all nodes
{
    Element *tempPtr = ptrToFirst_;
    Element *deletor = ptrToFirst_;

    for (int i = 0; i < (totalNumber - 1); i++)
    {
        tempPtr = tempPtr->ptrToNext_;
        delete deletor;
        deletor = tempPtr;
    }
    delete tempPtr;
    ptrToFirst_ = nullptr;
    totalNumber = 0;
}

int forwardList::at(int number) // returns content of node
{
    // std::cout << number << std::endl;
    // std::cout << totalNumber << std::endl;
    if (number == 0)
    {
        return ptrToFirst_->number_;
    }
    else if (number > 0 && number < totalNumber)
    {
        Element *tempPtr = ptrToFirst_;
        for (int i = 0; i < number; i++)
        {
            tempPtr = tempPtr->ptrToNext_;
        }
        return tempPtr->number_;
    }
    else if (number < 0 || number >= totalNumber)
    {
        throw std::out_of_range("There is no number with this index...");
    }
    return (-1);
}

Element *forwardList::getPtrToN(int position) // returns pointer to specific node
{
    Element *tempPtr = ptrToFirst_;
    for (int i = 0; i < position; i++)
    {
        tempPtr = tempPtr->ptrToNext_;
    }
    return tempPtr;
}

std::tuple<Element *, Element *, Element *> forwardList::getPtrToRemoving(int position) // return tuple with pointers to nodes -1N, N and +1N
{
    Element *tempPtr = ptrToFirst_;
    Element *ptrToPrev;
    Element *ptrToN;
    Element *ptrToNext;

    for (int i = 0; i < (position - 1); i++)
    {
        tempPtr = tempPtr->ptrToNext_;
    }
    ptrToPrev = tempPtr;
    tempPtr = tempPtr->ptrToNext_;
    ptrToN = tempPtr;
    tempPtr = tempPtr->ptrToNext_;
    ptrToNext = tempPtr;

    std::tuple<Element *, Element *, Element *> pointers = std::make_tuple(ptrToPrev, ptrToN, ptrToNext);

    return pointers;
}
