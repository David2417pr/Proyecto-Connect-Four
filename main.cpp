
// Luis D. Figueroa Olmo
#include <iostream>
using namespace  std;

int main()
{




cout << "\n";
for (int x = 10; x >= -10; x -=2 )
    if (x == -10)
    cout << x;
    else
    cout << x << ",";
cout << "\n\n";
    
for (int number = 1; number <= 22; number+= 3)
    if ( number == 22)
    cout << number;
    else
    cout << number << ",";
      
    
cout << "\n\n";

for (int mult3 = 1; mult3 <= 81; mult3 *= 3)
    if (mult3 == 81)
    cout << mult3;
    else
    cout << mult3 << ",";
cout << "\n\n";  

for (int raro = 0; raro <= 14; raro++)
    if (raro == 3 || raro == 6 || raro == 9 || raro == 12)
    continue;
    else if (raro == 14)
    cout << raro;
    else
    cout << raro << ",";
    
cout << "\n\n";

for (int quinto = 54; quinto >= 0 ; quinto /= 2)
    if (quinto == 0)
    {cout << quinto;
    break;}
    else
    cout << quinto << ",";
    
cout << "\n\n";

for (char abcd = 'A'; abcd <= 'Z'; abcd ++)
    if (abcd == 'Z')
    cout << abcd;
    else
    cout << abcd << ",";
 
 cout << "\n\n";   

return 0;

}
