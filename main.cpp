#include <iostream>
#include <iomanip>
#include <string>
using namespace  std;

const int COLS = 7;
const int ROWS = 6;
string Player1 = " X ", Player2 = " O ";


void DisplayBoard(string [][COLS],int ROWS);
void Token(string [][COLS],int ROWS,string);
void Token2(string Tok[][COLS],int ROWS, string);


int main()
{



// Juego Board

string Gamearray[ROWS][COLS] =    {{" - ", " - ", " - ", " - ", " - ", " - ", " - "}, 
                                {" - ", " - ", " - ", " - ", " - ", " - ", " - "}, 
                                {" - ", " - ", " - ", " - ", " - ", " - ", " - "},
                                { " - ", " - ", " - ", " - ", " - ", " - ", " - "},
                                { " - ", " - ", " - ", " - ", " - ", " - ", " - "},
                                { " - ", " - ", " - ", " - ", " - ", " - ", " - "}};

// Secuencia de el juego
int count = 0;
while(count < 42){
DisplayBoard(Gamearray, ROWS);
Token(Gamearray, ROWS, Player1);
DisplayBoard(Gamearray, ROWS);
Token2(Gamearray, ROWS, Player2);
count++;
}


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
// COls = 7, Rows = 6

void Token(string Tok[][COLS],int ROWS, string Player){
int Column, decrement = 1;
bool lleno = true;
//Input del Usuario y verificar si esta lleno

cout << " Jugador " << Player;
cout << "Entra columna (1-7): ";
cin >> Column;
while(Column < 1 || Column > 7){
    cout << "Las columnas son de 1 a 7: ";
    cin >> Column;    
  
}


// Si da falso(Da falso es porque hay un espacio vacio), sale del ciclo while 

for(int i = 1; i <= ROWS; i++){
    if (Tok[ROWS-i][Column-1]== Player1 || Tok[ROWS-i][Column-1]== Player2)
    lleno = true;
    else {
    lleno = false;
    break;}
}

while(lleno == true){
    cout << "La columna que has ingresado esta llena. Entre otra columna.";
    cin >> Column;
    for(int i = 1; i <= ROWS; i++){
    if (Tok[ROWS-i][Column-1]== Player1 || Tok[ROWS-i][Column-1]== Player2)
    lleno = true;
    else {
    lleno = false;
    break;}
}}
    

//Encontrar el espacio vacio

while(Tok[ROWS-decrement][Column-1] == Player1 || Tok[ROWS-decrement][Column-1] == Player2){
    decrement++;    
}
Tok[ROWS-decrement][Column-1] = Player;

}



void Token2(string Tok[][COLS],int ROWS, string Player){
int Column, decrement = 1;
bool lleno = true;
//Input del Usuario y verificar si esta lleno

cout << " Jugador " << Player;
cout << "Entra columna (1-7): ";
cin >> Column;
while(Column < 1 || Column > 7){
    cout << "Las columnas son de 1 a 7: ";
    cin >> Column;    
  
}


// Si da falso(Da falso es porque hay un espacio vacio), sale del ciclo while 

for(int i = 1; i <= ROWS; i++){
    if (Tok[ROWS-i][Column-1]== Player1 || Tok[ROWS-i][Column-1]== Player2)
    lleno = true;
    else {
    lleno = false;
    break;}
}

while(lleno == true){
    cout << "La columna que has ingresado esta llena. Entre otra columna.";
    cin >> Column;
    for(int i = 1; i <= ROWS; i++){
    if (Tok[ROWS-i][Column-1]== Player1 || Tok[ROWS-i][Column-1]== Player2)
    lleno = true;
    else {
    lleno = false;
    break;}
}}
    

//Encontrar el espacio vacio

while(Tok[ROWS-decrement][Column-1] == Player1 || Tok[ROWS-decrement][Column-1] == Player2){
    decrement++;    
}
Tok[ROWS-decrement][Column-1] = Player;

}

