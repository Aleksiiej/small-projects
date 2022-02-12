#include <iostream>
#include <stdexcept>
#include <tuple>

struct Element
{
    Element(int nr) : number_(nr) // parametri constructor of node
    {
    }

    int number_; // content of node

    Element *ptrToNext_{nullptr}; // pointer to next node
};

class forwardList
{
public:
    ~forwardList() // deletes all nodes
    {
        Element *tempPtr = ptrToFirst_;
        Element *deletor = ptrToFirst_;

        while (tempPtr->ptrToNext_)
        {
            tempPtr = tempPtr->ptrToNext_;
            std::cout << deletor->number_ << std::endl;
            delete deletor;
            std::cout << deletor->number_ << std::endl;
            deletor = tempPtr;
        }
        delete tempPtr; // SPRAWDZIC VALGIRNDEM CZY NIE MA WYCIEKU
    }

    void addElement(int number = 0) // adds node
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

    void deleteElement(int position) // deletes node
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
        }
    }

    void showList() // shows all nodes
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

    void clear() // deletes all nodes
    {
        Element *tempPtr = ptrToFirst_;
        Element *deletor = ptrToFirst_;

        while (tempPtr->ptrToNext_)
        {
            tempPtr = tempPtr->ptrToNext_;
            std::cout << deletor->number_ << std::endl;
            delete deletor;
            std::cout << deletor->number_ << std::endl;
            deletor = tempPtr;
        }
        delete tempPtr; // SPRAWDZIC VALGIRNDEM CZY NIE MA WYCIEKU
    }

    int at(int number) // returns content of node
    {
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

    Element *getPtrToN(int position) // returns pointer to specific node
    {
        Element *tempPtr = ptrToFirst_;
        for (int i = 0; i < position; i++)
        {
            tempPtr = tempPtr->ptrToNext_;
        }
        return tempPtr;
    }

    std::tuple<Element *, Element *, Element *> getPtrToRemoving(int position) // return tuple with pointers to nodes -1N, N and +1N
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

public:                            // should be private
    Element *ptrToFirst_{nullptr}; // pointer to begin of list
    inline static int totalNumber; // total amount of nodes
};

int main()
{
    forwardList List;
    List.addElement(10);
    List.addElement(20);
    List.addElement(30);
    List.addElement();

    List.showList();
    List.clear();
    List.showList();
}
