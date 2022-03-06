#include <iostream>
#include "adressBook.hpp"

int main()
{
    // Head head;
    // head.add("Jan", "Kowalski", 35, "jan.k@onet.pl");
    // head.add("Piotr", "Nowak", 20, "pitr@wp.pl");
    // head.add("Jan", "Kowalski", 16, "Jank@wp.pl");
    // head.show();
    // head.show("Jan", "Kowalski");
    // head.edit("Piotr", "Nowak");
    // head.show("Kazimierz", "Wielki");
    // head.remove("Jan", "Kowalski");
    // head.show();

    Head head {{"Jan", "Kowalski", 35, "jan.k@onet.pl"},
               {"Piotr", "Nowak", 20, "pitr@wp.pl"},
               {"Jan", "Kowalski", 16, "Jank@wp.pl"}};
    head.show();
}
