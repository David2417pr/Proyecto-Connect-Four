#include <iostream>
#include <iomanip>
#include <string>
using namespace  std;

const int COLS = 7;
const int rows = 6;



void DisplayBoard(string [][COLS],int rows);




int main()
{


string Gamearray[rows][COLS] =    {   {"- ", "- ", "- ", "- ", "- ", "- ", "- "}, 
                                {"- ", "- ", "- ", "- ", "- ", "- ", "- "}, 
                                {"- ", "- ", "- ", "- ", "- ", "- ", "- "},
                                { "- ", "- ", "- ", "- ", "- ", "- ", "- "},
                                { "- ", "- ", "- ", "- ", "- ", "- ", "- "},
                                { "- ", "- ", "- ", "- ", "- ", "- ", "- "}};


DisplayBoard(Gamearray, rows);





return 0;

}


void DisplayBoard(string Gamearr[][COLS], int rows){
for(int i = 0; i < rows; i++){
    cout << "\n";
    for(int j = 0; j < COLS; j++)
        cout << Gamearr[i][j];

}}

