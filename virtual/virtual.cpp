#include <iostream>
#include <string>
using namespace std;

class Animal
{
public:
    Animal()
    {
        printf("Animal::Animal()\n");
    }
    /*virtual*/ ~Animal()
    {
        printf("Animal::~Animal()\n");
    }

    virtual string classname()
    {
        return "Animal";
    }
    virtual bool isA(string type)
    {
        if (type == "Animal")
        {
            return true;
        }
        return false;
    }
    virtual void makeSound()
    {
        printf("Animal::makeSound()\n");
    }
    void pet()
    {
        printf("Animal::pet()\n");
    }

};

class Dog : public Animal
{
public:
    Dog()
    {
        printf("Dog::Dog()\n");
    }
    ~Dog()
    {
        printf("Dog::~Dog()\n");
    }

    string classname() override
    {
        return "Dog";
    }
    bool isA(string type)
    {
        if (type == "Dog")
        {
            return true;
        }
        return Animal::isA(type);
    }
    void makeSound() override
    {
        printf("Dog::makeSound()\n");
    }
    void pet() 
    {
        printf("Dog::pet()\n");
    }


    void guard()
    {
        printf("Dog::guard()\n");
    }
};

class Cat : public Animal
{
public:
    Cat()
    {
        printf("Cat::Cat()\n");
    }
    ~Cat()
    {
        printf("Cat::~Cat()\n");
    }

    string classname() override
    {
        return "Cat";
    }
    bool isA(string type)
    {
        if (type == "Cat")
        {
            return true;
        }
        return Animal::isA(type);
    }
    void makeSound() override
    {
        printf("Cat::makeSound()\n");
    }


    void makeAMess()
    {
        printf("Cat::makeAMess()\n");
    }
};

int main()
{
    Animal* animalA = new Dog();
    Animal* animalB = new Cat();
    Dog* dog = new Dog();

    printf("\nNonvirtual overridden methods:\n");
    animalA->pet();       // inherited method is called
    dog->pet();             // overridden method is called

    printf("\nVirtual overridden methods:\n");
    animalA->makeSound(); // overridden method is called
    dog->makeSound();       // overridden method is called

    printf("\nUnsafe casting\n");
    ((Cat*)animalB)->makeAMess();

    printf("\nSafe casting by string type check\n");
    if (animalA->classname() == "Dog")
    {
        ((Dog*)animalA)->guard();
    }
    if (dog->classname() == "Animal") // Won't be called
    {
        ((Animal*)dog)->makeSound();
    }
    else
    {
        printf("((Animal*)dog)->makeSound() was not called\n");
    }
}
