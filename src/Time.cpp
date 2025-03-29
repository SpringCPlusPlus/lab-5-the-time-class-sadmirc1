#include <iostream>
#include "../include/Time.h"
using namespace std;

void Time::simplify() {
    if (minutes >= 60) {
        hours++;
        minutes = minutes % 60;
    }
}

// Overload the + operator
Time Time::operator+(const Time &other) const
{   
    Time sum(hours + other.hours, minutes + other.minutes);
    sum.simplify();
    return sum;
}

// Overload the += operator
Time& Time::operator+=(const Time &other)
{
    hours += other.hours;
    minutes += other.minutes;
    simplify();
    return *this;
}

// Overload the < operator
bool Time::operator<(const Time &other) const
{
    return hours * 60 + minutes < other.hours * 60 + other.minutes;
}

// Overload the > operator
bool Time::operator>(const Time &other) const
{
    return hours * 60 + minutes > other.hours * 60 + other.minutes;
}

// Overload the == operator
bool Time::operator==(const Time &other) const
{
    return hours * 60 + minutes == other.hours * 60 + other.minutes;
}

// Overload the friend function operator<<
ostream &operator<<(ostream &os, const Time &tm)
{
    os << "Time duration of " << tm.hours << " hours and " << tm.minutes << " minutes." << endl;
    return os;
}
