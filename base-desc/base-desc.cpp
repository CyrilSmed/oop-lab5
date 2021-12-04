#include <iostream>
#include <string>
using namespace std;

class Base
{
private:
    int baseNum = 0;
public:
    Base()
    {
        printf("Base::Base()\n");
    }
    Base(Base* obj) 
    {
        printf("Base::Base(Base* obj)\n");
        baseNum = obj->baseNum;
    }
    Base(Base& obj) 
    {
        printf("Base::Base(Base& obj)\n");
        baseNum = obj.baseNum;
    }
    Base(int num)
    {
        printf("Base::Base(int num)\n");
        baseNum = num;
    }
    virtual ~Base() {
        printf("Base::~Base()\n");
    }

    int getBaseNum()
    {
        return baseNum;
    }
    void setBaseNum(int num)
    {
        baseNum = num;
    }
};

class Desc : public Base
{
public:
    Desc()
    {
        printf("Desc::Desc()\n");
    }
    Desc(Desc* obj) : Base(obj)
    {
        printf("Desc::Desc(Desc* obj)\n");
    }
    Desc(Desc& obj) : Base(obj)
    {
        printf("Desc::Desc(Desc& obj)\n");
    }
    Desc(int num) : Base(num)
    {
        printf("Desc::Desc(int num)\n");
    }
    ~Desc() {
        printf("Desc::~Desc()\n");
    }
};

void funcOne(Base obj) // Uses copy constructor
{
    printf("funcOne()\n");
    printf("baseNum: %d\n", obj.getBaseNum());

    obj.setBaseNum(obj.getBaseNum() + 1); // only changes the copy
}
void funcTwo(Base* obj)
{
    printf("funcTwo()\n");
    printf("baseNum: %d\n", obj->getBaseNum());

    obj->setBaseNum(obj->getBaseNum() + 1);
}
void funcThree(Base& obj)
{
    printf("funcThree()\n");
    printf("baseNum: %d\n", obj.getBaseNum());

    obj.setBaseNum(obj.getBaseNum() + 1);
}

int main()
{

}