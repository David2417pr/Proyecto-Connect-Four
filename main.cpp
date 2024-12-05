#include <iostream> 
#include <iomanip> 
#include <string> 
#include <limits> 
using namespace  std; 

 
//Inicializar variables constantes

const int COLS = 7; 
const int ROWS = 6; 

//Inicializar variables de jugadores
string Player1 = " X ", Player2 = " O ", Player; 

//Inicializar variables booleanas para identificar condiciones de ganar y empate

bool winner = false, Draw = false; 

//Prototipos

void Play(string [][COLS],int ROWS); 
void DisplayBoard(string [][COLS],int ROWS); 
void Token(string [][COLS],int ROWS,string); 
void PlayerInTurn(string, string); 
bool CheckColumnFull(string [][COLS], int ROWS, int ); 
bool CheckRow0Full (string [][COLS],int ROWS, int , bool ); 
void CheckWinHorizontal(string [][COLS], int); 
void CheckWinVertical(string [][COLS], int); 
void CheckWinDiagonal1(string [][COLS], int); 
void CheckWinDiagonal2(string [][COLS], int); 

int main() { 
 
char opcion; 

// Juego Board
string Gamearray[ROWS][COLS] =    {{" - ", " - ", " - ", " - ", " - ", " - ", " - "},  

                                {" - ", " - ", " - ", " - ", " - ", " - ", " - "},  

                                {" - ", " - ", " - ", " - ", " - ", " - ", " - "}, 

                                { " - ", " - ", " - ", " - ", " - ", " - ", " - "}, 

                                { " - ", " - ", " - ", " - ", " - ", " - ", " - "}, 

                                { " - ", " - ", " - ", " - ", " - ", " - ", " - "}}; 

 do { 
   cout << "\n\n\t\tConnect Four!\n"; 
   cout << "\n\t\tA.) Jugar."; 
   cout << "\n\t\tB.) Como jugar."; 
   cout << "\n\t\tC.) Salir."; 
   cout << "\n\t\tOprima opcion: "; 
   cin >> opcion; 
   switch(opcion){ 
    case 'a':  // Secuencia de el juego 
    case 'A':   Play(Gamearray, ROWS); 
                break; 
    case 'b': 
    case 'B': cout << "\n\t\tEl primero que conecte la misma letra horizontalmente, verticalmente o diagonalmente gana el juego.\n"; 
                break; 
    case 'c': 
    case 'C': return 0; 
    default: cout << "\n\t\t*Opcion invalida!!!!! Ingrese opcion(A, B ó C)*\n";} 
}while(opcion != 'C' || opcion != 'c'); 
} 

void Play(string Gamearray[][COLS],int ROWS){ 
        
        if(winner == true || Draw == true){ 
                for(int i = 0; i < ROWS; i++) 
                    for(int j = 0; j < COLS; j++){ 
                Gamearray[i][j] = " - "; 
                } 
                winner = false; 
                Draw = false;} 

                while(winner == false && Draw == false){ 
                DisplayBoard(Gamearray, ROWS); 
                PlayerInTurn(Player1, Player2); 
                Token(Gamearray, ROWS, Player); 
                CheckWinHorizontal(Gamearray, ROWS); 
                CheckWinVertical(Gamearray, ROWS); 
                CheckWinDiagonal1(Gamearray, ROWS); 
                CheckWinDiagonal2(Gamearray, ROWS); 
                } 

 

} 

void DisplayBoard(string Gamearray[][COLS], int ROWS){ 

cout << "\n 1   2   3   4   5   6   7"; 

for(int i = 0; i < ROWS; i++){ 
    cout << "\n"; 
    for(int j = 0; j < COLS; j++) 
        cout << Gamearray[i][j] << "|";    
}} 

// COls = 7, Rows = 6 
void Token(string Gamearray[][COLS],int ROWS, string Player){ 

int Column, decrement = 1; 
bool Lleno = true; 

//Input del Usuario y verificar si esta lleno 

cout << " Jugador " << Player; 
cout << "Entra columna (1-7)(Para salir de el juego oprima '-1'): "; 
cin >> Column; 
if(Column == -1){ 
    winner = true; 
    return;} 

while(Column < 1 || Column > 7){ 

    DisplayBoard(Gamearray, ROWS); 
    if(cin.fail()) { 
        cin.clear(); 
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
        continue; 
    } 

    cout << "Las columnas son de 1 a 7: "; 
    cout << " Jugador " << Player; 
    cout << "Entra columna (1-7)(Para salir de el juego oprima '-1'): "; 
    cin >> Column; 
    if(Column == -1){ 
    winner = true; 
    return;}     
} 

// Si da falso(Da falso es porque hay un espacio vacio), sale del ciclo while  
Lleno = CheckColumnFull( Gamearray, ROWS, Column); 

//Si no hay espacio en row 0, empate 
if(Lleno == true) 
CheckRow0Full (Gamearray, ROWS, Column, Lleno);  

if(Draw == true) 
    return; 
 
// Si da falso(Da falso es porque hay un espacio vacio), sale del ciclo while  

while(Lleno == true){ 
    DisplayBoard(Gamearray, ROWS); 
    cout << "La columna que has ingresado esta llena. Jugador" << Player << " Entre otra columna."; 
    cin >> Column; 
        if(cin.fail()) { 
        cin.clear(); 
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
        continue; 
    } 

    if(Column == -1){ 
    winner = true; 
    return;} 

while(Column < 1 || Column > 7){ 

    DisplayBoard(Gamearray, ROWS); 
    cout << "Las columnas son de 1 a 7: "; 
    cout << " Jugador " << Player; 
    cout << "Entra columna (1-7)(Para salir de el juego oprima '-1'): "; 
    cin >> Column;     
        if(cin.fail()) { 
        cin.clear(); 
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
        continue; 
    } 
    if(Column == -1){ 
    winner = true; 
    return;} 
} 
Lleno = CheckColumnFull( Gamearray, ROWS, Column); 
} 

//Encontrar el espacio vacio y llenarlo 
// To do: funcion LlenarEspacioVacio() 
while(Gamearray[ROWS-decrement][Column-1] == Player1 || Gamearray[ROWS-decrement][Column-1] == Player2){ 
    decrement++;     
} 

Gamearray[ROWS-decrement][Column-1] = Player; 

} 

void PlayerInTurn(string Player1, string Player2){ 

    static int number = 0; 

    if(number % 2 == 0) 
    Player = Player1; 
    else  
    Player = Player2; 
    number++;
} 

bool CheckColumnFull(string Gamearray[][COLS], int ROWS, int Column){ 

bool Lleno; 

for(int i = 1; i <= ROWS; i++){ 

    if (Gamearray[ROWS-i][Column-1]== Player1 || Gamearray[ROWS-i][Column-1]== Player2) 
    Lleno = true; 
    else { 
    Lleno = false; 
    break;} 
    } 
    return Lleno; 
    } 

 

bool CheckRow0Full (string Gamearray[][COLS],int ROWS, int Column, bool Lleno){ 

    if(Lleno == true){ 
        for(int j = 0; j < COLS; j++){ 
                if(Gamearray[0][j] == Player1 || Gamearray[0][j] == Player2){ 
                Draw = true; 
                } 
                else { 
                Draw = false; 
                break;} 
        } 
    } 

    if(Draw == true){ 
        cout << "\n\t\tEmpate!\n\n"; 
        return Lleno; 
    } 
    else { 
    Lleno = false; 
    return Lleno; 
    } 
    } 

 
void CheckWinHorizontal(string Gamearray[][COLS], int ROWS){ 

for(int i = 0; i < ROWS; i++){ 
    for(int j = 0; j < COLS; j++){ 
      if(Gamearray[i][j] == Player1 && Gamearray[i][j+1] == Player1 && Gamearray[i][j+2] == Player1 && Gamearray[i][j+3] == Player1){ 
        
        winner = true; 
        Player = Player1; 
        DisplayBoard(Gamearray, ROWS); 
        cout <<"\n\n\t\t" <<  Player << " Wins!!"; 
        return; 
    } 
    else if(Gamearray[i][j] == Player2 && Gamearray[i][j+1] == Player2 && Gamearray[i][j+2] == Player2 && Gamearray[i][j+3] == Player2){ 
        winner = true; 
        Player = Player2; 
        DisplayBoard(Gamearray, ROWS); 
        cout <<"\n\n\t\t" <<  Player << " Wins!!"; 
        return; 
    } 
    } 
} } 

 void CheckWinVertical(string Gamearray[][COLS], int ROWS){ 

for(int i = 0; i < ROWS; i++){ 
    for(int j = 0; j < COLS; j++){ 
        if(Gamearray[i][j] == Player1 && Gamearray[i-1][j] == Player1 && Gamearray[i-2][j] == Player1 && Gamearray[i-3][j] == Player1){ 
        winner = true; 
        Player = Player1; 
        DisplayBoard(Gamearray, ROWS); 
        cout <<"\n\n\t\t" <<  Player << " Wins!!"; 
        return; 
    } 
    else if(Gamearray[i][j] == Player2 && Gamearray[i-1][j] == Player2 && Gamearray[i-2][j] == Player2 && Gamearray[i-3][j] == Player2){ 

        winner = true; 
        Player = Player2; 
        DisplayBoard(Gamearray, ROWS); 
        cout <<"\n\n\t\t" <<  Player << " Wins!!"; 
        return; 
} } } } 

     

void CheckWinDiagonal1(string Gamearray[][COLS],int ROWS){ 

    for(int i = 0; i < ROWS; i++){ 
        for(int j = 0; j < COLS; j++){ 
            if(Gamearray[i][j] == Player1 && Gamearray[i-1][j+1] == Player1 && Gamearray[i-2][j+2] == Player1 && Gamearray[i-3][j+3] == Player1){ 

        winner = true; 
        Player = Player1; 
        DisplayBoard(Gamearray, ROWS); 
        cout <<"\n\n\t\t" <<  Player << " Wins!!"; 
        return; 
    } 

    else if(Gamearray[i][j] == Player2 && Gamearray[i-1][j+1] == Player2 && Gamearray[i-2][j+2] == Player2 && Gamearray[i-3][j+3] == Player2){ 
        
        winner = true; 
        Player = Player2; 
        DisplayBoard(Gamearray, ROWS); 
        cout <<"\n\n\t\t" <<  Player << " Wins!!"; 
        return; 
    } } } } 

 

void CheckWinDiagonal2(string Gamearray[][COLS],int ROWS){ 
       for(int i = 0; i < ROWS; i++){ 
            for(int j = 0; j < COLS; j++){ 
      if(Gamearray[i][j] == Player1 && Gamearray[i-1][j-1] == Player1 && Gamearray[i-2][j-2] == Player1 && Gamearray[i-3][j-3] == Player1){ 
        winner = true; 
        Player = Player1; 
        DisplayBoard(Gamearray, ROWS); 
        cout <<"\n\n\t\t" <<  Player << " Wins!!"; 
        return; 
    } 

    else if(Gamearray[i][j] == Player2 && Gamearray[i-1][j-1] == Player2 && Gamearray[i-2][j-2] == Player2 && Gamearray[i-3][j-3] == Player2){ 
        
        winner = true; 
       Player = Player2; 
        DisplayBoard(Gamearray, ROWS); 
        cout <<"\n\n\t\t" <<  Player << " Wins!!"; 
        return; 
    } }}} 