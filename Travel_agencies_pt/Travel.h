#pragma once
#include <iomanip>
#include <Windows.h>
#include <iostream>
#include <vector>
#include <conio.h>
#include <map>

using namespace std;

enum class Keys
{
    NOSET,

    LEFT = 75,
    RIGHT = 77,
    TOP = 72,
    DOWN = 80,
    ESC = 27,
    SPACE = 32,
    ENTER = 13,

};
string Show_menu(vector <string> st, string str);

class Travel
{
protected:
    string name;
    double price;
public:
    Travel() {}
    virtual void Set_n() = 0;
    virtual void Set_p(double p) = 0;
    virtual double Get_p() = 0;
    virtual void   Print() = 0;
    virtual void addObj(Travel* p) {  }//assert(false);
};

class Country : public Travel
{
public:
    Country() {}
    void Set_n() ;
    void Set_p (double p);
    double Get_p();
    void   Print();
};
class Hotel : public Travel
{
public:
    Hotel() {}
    void Set_n();
    void Set_p(double p);
    double Get_p();
    void   Print();
};
class Transfer : public Travel
{
public:
    Transfer() {}
    void Set_n();
    void Set_p(double p);
    double Get_p();
    void   Print();
};
class Excursion : public Travel
{
public:
    Excursion() {}
    void Set_n();
    void Set_p(double p);
    double Get_p();
    void   Print();
};

class Factory
{
public:
    virtual Travel* createTravel() = 0;
    virtual ~Factory() {}
};

class CountryFactory : public Factory
{
public:
    Travel* createTravel()
    {
        Country* cntr = new Country();
        cntr->Set_n();
        return cntr;
    }
};
class HotelFactory : public Factory
{
public:
    Travel* createTravel()
    {
        Hotel* h = new Hotel();       
        h->Set_n();
        return h;
    }
};
class TransferFactory : public Factory
{
public:
    Travel* createTravel()
    {
        Transfer* tr = new Transfer();
        tr->Set_n();
        return tr;
    }
};
class ExcursionFactory : public Factory
{
public:
    Travel* createTravel()
    {
        Excursion* ex = new Excursion();
        ex->Set_n();
        return ex;
    }
};

class CompositeTravel : public Travel
{
    vector <Travel*> t;
public:
    double Get_p()
    {
        double total = 0;
        for (int i = 0; i < t.size(); ++i)
            total += t[i]->Get_p();
        return total;
    }
    void addObj(Travel* t1) { t.push_back(t1); }
    void ClearH() { t.clear(); }
    void Set_n() 
    {
        for (int i = 0; i < t.size(); ++i)
            t[i]->Set_n();
    }
    void Set_p(double p)
    {
        for (int i = 0; i < t.size(); ++i)
            t[i]->Set_p(p);
    }
    void  Print() 
    {
        for (int i = 0; i < t.size(); ++i)
            t[i]->Print();
    }

    ~CompositeTravel()
    {
        for (int i = 0; i < t.size(); ++i)
            delete t[i];
    }
};

CompositeTravel* MyTour();