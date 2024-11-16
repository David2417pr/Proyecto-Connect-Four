
// Luis D. Figueroa Olmo
#include <iostream>
#include <iomanip>
using namespace  std;

const int COLS = 2;
const int rows = 3;

int total = 0, total2 = 0;


void arraysum(const int arr[][COLS], int rows) {


for(int i = 0; i < rows; i++){
    for(int j = 0; j < COLS; j++){
        if (j == 0)
        total +=  arr[i][j];
        else 
        total2 += arr[i][j];


    }
 

 }



return ;
}

int main()
{


int hours[rows][COLS] =     {{8, 5}, 
                            {7,9}, 
                            {6,3}};
arraysum(hours, rows);

cout << total << " " << total2 << " ";


return 0;

}




