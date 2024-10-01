
#include <iostream>
using namespace  std;

int main()
{

int x;
int number;
cout << "\n";
for (int x = 10; x > -10; x -=2 )
    if (x == -8)
    cout << x;
    else
    cout << x << ",";
cout << "\n" << endl;
    
for (int number = 1; number <= 22; number+= 3)
    if ( number == 22)
    cout << number;
    else
    cout << number << ",";
 cout << endl;   
 cout << "\n" << endl;       

    return 0;
}
