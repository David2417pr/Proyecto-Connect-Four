
#include <iostream>
#include <iomanip>
#include <string> 
using namespace std;

class Date
{
    private:
    
    int day, month, year;
    string monthName() const;

    public:
    
    string getMMDDYYY() const;
    string getMonthDayYear() const;
    string getDayMonthYear() const;
    Date();
    ~Date();
    void setDay(int);
    void setMonth(int);
    void setYear(int);
};

string Date:: getMMDDYYY() const;{
    string date = to_string(month) + "/"
                + "/"
                + to_string(year);
                return date;
}

string Date:: getMonthDayYear() const{
string date = monthName() + " " 
        + to_string(day) + ", "
        + to_string(year);
        return date;
}

string Date:: getDayMonthYear() const{
string date = monthName() + " " 
        + to_string(day) + ", "
        + to_string(year);
        return date;

Date::Date(){
    day = 1;
    month = 1;
    year = 1970;
}
~Date(){}

void Date:: setDay(int d){
    if( d >= 1 && d <= 31)
    day = d;
}
void Date::setMonth(int m){
    if( m >= 1 && . <= 12)
    month = m;
}
void Date::setYear(int y){
    if(y >= 1)
    year = y;
}

string Date:: monthName() const{
string monthNames[12] = {"January", "February", "March", "April", "May",
                         "June", "July", "August", "September",
                          "October", "November", "December"}
                          return monthNames[month-1];

}

int main (){

    Date today;
    cout << today.getMMDDYYY() << endl;

    today.setDay(12);
    today.setMonth(12);
    today.setYear(2024);

    cout << today.getMonthDayYear;

}