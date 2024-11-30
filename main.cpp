#include <iostream>
#include <iomanip>
#include <string>
using namespace  std;

const int COLS = 7;
const int ROWS = 6;
string Player1 = " X ", Player2 = " O ", Player;
bool winner = false, Lleno2 = false;;

void DisplayBoard(string [][COLS],int ROWS);
void Token(string [][COLS],int ROWS,string);
void PlayerinTurn(string, string);
bool CheckColumnFull(string [][COLS], int ROWS, int );


int main()
{

// Juego Board
char opcion;

string Gamearray[ROWS][COLS] =    {{" - ", " - ", " - ", " - ", " - ", " - ", " - "}, 
                                {" - ", " - ", " - ", " - ", " - ", " - ", " - "}, 
                                {" - ", " - ", " - ", " - ", " - ", " - ", " - "},
                                { " - ", " - ", " - ", " - ", " - ", " - ", " - "},
                                { " - ", " - ", " - ", " - ", " - ", " - ", " - "},
                                { " - ", " - ", " - ", " - ", " - ", " - ", " - "}};

do {
 
   cout << "\n\t\tConnect Four!\n";
   cout << "\n\t\tA.) Jugar.";
   cout << "\n\t\tB.) Como jugar.";
   cout << "\n\t\tC.) Salir";
   cout << "\n\t\tOprima opcion: ";
   cin >> opcion;
   switch(opcion){
    case 'a':
    case 'A': // Secuencia de el juego
                if(winner == true){
                for(int i = 0; i < ROWS; i++)
                    for(int j = 0; j < COLS; j++){
                Gamearray[i][j] = " - ";
                }
                winner = false;}
                while(winner == false && Lleno2 == false){
                DisplayBoard(Gamearray, ROWS);
                PlayerinTurn(Player1, Player2);
                Token(Gamearray, ROWS, Player);
                
                }
                break;
    case 'b':
    case 'B': cout << "\n\t\tEl primero que conecte la misma letra horizontalmente, verticalmente y/o diagonalmente, gana el juego.\n";
                break;
    case 'c':
    case 'C': return 0;}
}while(opcion != 'C' || opcion != 'c');

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
bool Lleno = true;
//Input del Usuario y verificar si esta lleno
cout << " Jugador " << Player;
cout << "Entra columna (1-7)(-1): ";
cin >> Column;

if(Column == -1){
    winner = true;
    return;}

while(Column < 1 || Column > 7){
    cout << "Las columnas son de 1 a 7: ";
    cin >> Column;    
  
}
// Si da falso(Da falso es porque hay un espacio vacio), sale del ciclo while 
Lleno = CheckColumnFull( Tok, ROWS, Column);

//Si no hay espacio en row 0, empate

if(Lleno == true){
    for(int j = 0; j < COLS; j++){
            if(Tok[0][j] == Player1 || Tok[0][j] == Player2){
            Lleno2 = true;
            }
            else {
            Lleno2 = false;
            break;}
    }
}
if(Lleno2 == true){
    cout << "\n\t\tEmpate!\n\n";
    return;
}

// Si da falso(Da falso es porque hay un espacio vacio), sale del ciclo while 
// funcion LlenarEspacioVacio()
while(Lleno == true){
    DisplayBoard(Tok, ROWS);
    cout << "La columna que has ingresado esta llena. Jugador" << Player << " Entre otra columna.";
    cin >> Column;
    for(int i = 1; i <= ROWS; i++){
    if (Tok[ROWS-i][Column-1]== Player1 || Tok[ROWS-i][Column-1]== Player2)
    Lleno = true;
    else {
    Lleno = false;
    break;}
}}
    

//Encontrar el espacio vacio

while(Tok[ROWS-decrement][Column-1] == Player1 || Tok[ROWS-decrement][Column-1] == Player2){
    decrement++;    
}
Tok[ROWS-decrement][Column-1] = Player;
}


void PlayerinTurn(string Player1, string Player2){
    static int number = 0;
    if(number % 2 == 0)
    Player = Player1;
    else 
    Player = Player2;
    number++;

}

bool CheckColumnFull(string Tok[][COLS], int ROWS, int Column){

bool Lleno;

for(int i = 1; i <= ROWS; i++){
    if (Tok[ROWS-i][Column-1]== Player1 || Tok[ROWS-i][Column-1]== Player2)
    Lleno = true;
    else {
    Lleno = false;
    break;}
    }
    return Lleno;
    }