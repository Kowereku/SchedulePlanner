#include "Event.h"

Event::Event(string n, string d, string t, string day, string sh, string eh)
{
    this->name = n;
    this->desc = d;
    this->type = t;
    this->day = day;
    this->starth = sh;
    this->endh = eh;
}

string Event::getName()
{
    return name;
}

string Event::getDesc()
{
    return desc;
}

string Event::getType()
{
    return type;
}

string Event::getDay()
{
    return day;
}

string Event::getStartH()
{
    return starth;
}

string Event::getEndH()
{
    return endh;
}
