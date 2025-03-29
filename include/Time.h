#ifndef TIME_H
#define TIME_H

#include <iostream>
using namespace std;

class Time
{
private:
    int hours;
    int minutes;
    void simplify();
public:
    // Constructor
    Time(int h = 0, int m = 0) : hours(h), minutes(m) {simplify();}

    // Getter functions (for testing)
    int getHours() const { return hours; }
    int getMinutes() const { return minutes; }
    
    // Overload the ostream display function
    friend ostream& operator<<(ostream& os, const Time& t);

    // Overload the + operator
    Time operator+(const Time &other) const;

    // Overload the += operator
    Time &operator+=(const Time &other);

    // Overload the < operator
    bool operator<(const Time &other) const;

    // Overload the > operator
    bool operator>(const Time &other) const;

    // Overload the == operator
    bool operator==(const Time &other) const;
};

#endif // TIME_H