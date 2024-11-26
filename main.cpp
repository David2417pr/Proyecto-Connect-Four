
// Luis D. Figueroa Olmo
#include <iostream>
#include <iomanip>
#include <string>
using namespace  std;

const int COLS = 7;
const int rows = 6;




/*void arraysum(const int arr[][COLS], int rows) {


for(int i = 0; i < rows; i++){
    for(int j = 0; j < COLS; j++){
        if (j == 0)
        total +=  arr[i][j];
        else 
        total2 += arr[i][j];


    }
 

 }



return ;
}*/

int main()
{


string hours[rows][COLS] =    {   {"- ", "- ", "- ", "- ", "- ", "- ", "- "}, 
                                {"- ", "- ", "- ", "- ", "- ", "- ", "- "}, 
                                {"- ", "- ", "- ", "- ", "- ", "- ", "- "},
                                { "- ", "- ", "- ", "- ", "- ", "- ", "- "},
                                { "- ", "- ", "- ", "- ", "- ", "- ", "- "},
                                { "- ", "- ", "- ", "- ", "- ", "- ", "- "}};


//arraysum(hours, rows);

for(int i = 0; i < rows; i++){
    cout << "\n";
    for(int j = 0; j < COLS; j++)
        cout << hours[i][j];
}


return 0;

}




