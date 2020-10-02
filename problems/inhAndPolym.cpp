#include <iostream>
#include "pet.h"
#include "dog.h"
using namespace std;

int main()
{

    Dog sharo("sharo", 41, Black); 
    Pet dog = sharo;
    Pet *pet = new Dog("sharo", 41, Black);
    //Dog sharo2 = dog; - taka ne moje
    
    Pet pet1("riba", 1);
    Pet *pet2 = new Dog("sharo", 42, Black);
    Dog pet3("charli", 70, White);

    cout << pet1.getAge() << endl;
    cout << pet2->getAge() << endl;    
    cout << pet3.getAge() << endl;

    delete pet2;

    return 0;
}