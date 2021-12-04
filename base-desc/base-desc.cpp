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

int main()
{

}