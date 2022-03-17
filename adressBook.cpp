#include "adressBook.hpp"

Head::Head(const std::initializer_list<Person> &ls)
{
    for (auto [name, surname, age, email] : ls)
    {
        add(name, surname, age, email);
        counter++;
    }
}

int Head::getSize() const
{
    return counter;
}

void Head::add(const std::string &name, const std::string &surname, const int &age, const std::string &email)
{
    database_.push_back(std::move(Person(name, surname, age, email)));
    counter++;
}

std::vector<Person *> Head::ptrToPerson(const std::string &name, const std::string &surname)
{
    std::vector<Person *> result;

    for (auto &el : database_)
    {
        if (el.name_ == name && el.surname_ == surname)
        {
            Person *ptr = &el;
            result.push_back(ptr);
        }
    }

    if (result.size() > 0)
    {
        return result;
    }
    else
    {
        std::cout << "No records with this name and surname" << std::endl;
        return result;
    }
}

std::vector<Person *> Head::ptrToPerson()
{
    std::vector<Person *> result;

    for (auto &el : database_)
    {
        Person *ptr = &el;
        result.push_back(ptr);
    }
    return result;
}

void Head::show(const std::string &name, const std::string &surname)
{
    auto vec = ptrToPerson(name, surname);

    std::for_each(begin(vec), end(vec), [](Person *ptr)
                  {
        std::cout << "----------------------------------" << std::endl;
        std::cout << "Name: " << ptr->name_ << std::endl;
        std::cout << "Surname: " << ptr->surname_ << std::endl;
        std::cout << "Age: " << ptr->age_ << std::endl;
        std::cout << "E-mail: " << ptr->email_ << std::endl;
        std::cout << "----------------------------------" << std::endl; });
}

void Head::show()
{
    auto vec = ptrToPerson();

    for (const auto &el : vec)
    {
        showRecord(el);
    }
}

void Head::showRecord(Person *ptr) const
{
    std::cout << "----------------------------------" << std::endl;
    std::cout << "Name: " << ptr->name_ << std::endl;
    std::cout << "Surname: " << ptr->surname_ << std::endl;
    std::cout << "Age: " << ptr->age_ << std::endl;
    std::cout << "E-mail: " << ptr->email_ << std::endl;
    std::cout << "----------------------------------" << std::endl;
}

void Head::edit(const std::string &name, const std::string &surname)
{
    auto vec = ptrToPerson(name, surname);

    for (auto &el : vec)
    {
        if ((el->name_ == name) && (el->surname_ == surname))
        {
            showRecord(el);

            std::string tempString;
            int tempInt;

            std::cout << "Edit name: ";
            std::cin >> tempString;
            el->name_ = tempString;

            std::cout << "Edit surname: ";
            std::cin >> tempString;
            el->surname_ = tempString;

            std::cout << "Edit age: ";
            std::cin >> tempInt;
            el->age_ = tempInt;

            std::cout << "Edit e-mail: ";
            std::cin >> tempString;
            el->email_ = tempString;
        }
    }
}

void Head::remove(const std::string &name, const std::string &surname)
{
    database_.erase(std::remove_if(begin(database_), end(database_),
                                   [&](auto Person)
                                   { return (Person.name_ == name && Person.surname_ == surname); }),
                    end(database_));
}
