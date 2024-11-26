#include <iostream>
#include <iomanip>
#include <string>
using namespace  std;

const int COLS = 7;
const int ROWS = 6;



void DisplayBoard(string [][COLS],int ROWS);
void Token(string [][COLS],int ROWS);



int main()
{


string Gamearray[ROWS][COLS] =    {{" - ", " - ", " - ", " - ", " - ", " - ", " - "}, 
                                {" - ", " - ", " - ", " - ", " - ", " - ", " - "}, 
                                {" - ", " - ", " - ", " - ", " - ", " - ", " - "},
                                { " - ", " - ", " - ", " - ", " - ", " - ", " - "},
                                { " - ", " - ", " - ", " - ", " - ", " - ", " - "},
                                { " - ", " - ", " - ", " - ", " - ", " - ", " - "}};


DisplayBoard(Gamearray, ROWS);
Token(Gamearray, ROWS);




return 0;

}


void DisplayBoard(string Gamearr[][COLS], int ROWS){
cout << " 1   2   3   4   5   6   7";
for(int i = 0; i < ROWS; i++){
    cout << "\n";
    for(int j = 0; j < COLS; j++){

        cout << Gamearr[i][j] << "|";
    }
}}

void Token(string Tok[][COLS],int ROWS){
int Column;
cout << "Entra columna (1-7): ";
cin >> Column;
while(Column < 1 || Column > 7){
    cout << "Entra columna (1-7): ";
    cin >> Column;   

}
}