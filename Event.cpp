#include "Event.h"

Event::Event(int id, string n, string d, string t, string day, string sh, string eh)
{
    this->id = id;
    this->name = n;
    this->desc = d;
    this->type = t;
    this->day = day;
    this->starth = sh;
    this->endh = eh;
}

