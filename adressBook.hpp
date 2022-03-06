#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

struct Person
{
    friend class Head;
  
public:
    Person(std::string name, std::string surname, int age, std::string email)
        : name_(name), surname_(surname), age_(age), email_(email)
    {
    }
  
private:
    std::string name_;
    std::string surname_;
    int age_;
    std::string email_;
};

class Head
{
public:
    Head() = default;
    Head(const std::initializer_list<Person>& ls);
    
    int getSize() const;
    void add(const std::string &name, const std::string &surname, const int &age, const std::string &email);
    std::vector<Person *> ptrToPerson(const std::string &name, const std::string &surname);
    std::vector<Person *> ptrToPerson();
    void show(const std::string &name, const std::string &surname);
    void show(); 
    void showRecord(Person *ptr) const;
    void edit(const std::string &name, const std::string &surname);
    void remove(const std::string &name, const std::string &surname);

private:
    std::vector<Person> database_;
    int counter{0};
};
