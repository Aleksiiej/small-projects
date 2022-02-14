#pragma once
#include <iostream>
#include <stdexcept>
#include <tuple>

struct Element
{
    Element(int nr) : number_(nr) // parametric constructor of node
    {
    }

    int number_{}; // content of node

    Element *ptrToNext_{nullptr}; // pointer to next node
};

class forwardList
{
public:
    ~forwardList(); // deletes all nodes when leaving scope

    void addElement(int number = 0); // adds node

    void deleteElement(int position); // deletes node

    void showList(); // shows all nodes

    void clear(); // deletes all nodes

    int at(int number); // returns content of node

    Element *getPtrToN(int position); // returns pointer to specific node

    std::tuple<Element *, Element *, Element *> getPtrToRemoving(int position); // return tuple with pointers to nodes -1N, N and +1N

private:
    Element *ptrToFirst_{nullptr}; // pointer to begin of list
    inline static int totalNumber; // total amount of nodes
};