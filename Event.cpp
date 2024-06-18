#include "Event.h"

Event::Event(int id, string n, string d, string day, string sh, string eh) // konstruktor wydarzenia
{
    this->id = id;
    this->name = n;
    this->desc = d;
    this->day = day;
    this->starth = sh;
    this->endh = eh;
}

