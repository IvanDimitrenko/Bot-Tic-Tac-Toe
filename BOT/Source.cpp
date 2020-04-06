#include<Windows.h>
#include<iostream>
#include<conio.h>
using namespace std;
const int n = 9; 
char arr[n] ={
' ',' ',' '
,' ',' ',' ',
' ',' ',' '};
enum ConsoleColor {
	Blue = 9, Red = 12, White = 15
};
void setColor(unsigned color) {
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE); SetConsoleTextAttribute(hConsole, color); 
}

//void Game_O(int turne);
//void Boot_X(int turne);
void Game_x(int turne, char walk, char game);
void Set_Board();
void Draw();
void Bot_O(int turne);
char Walk(int turne, char walk);
char CONTROL(int turne);
void new_game(int turne, char walk, char game);

///////////////////////////////////////////////////////////		Main
void main()
{
    char game = '!',walk  = 'X';
    int turne = 0;
    Game_x(turne, walk, game);
}
void Game_x(int turne, char walk, char game)
{
	while (game == '!')
	{
		Draw();

		Walk(turne, walk); turne++;
		if (turne >= 5) {
			game = CONTROL(turne);

			if (game == 'X')
			{
				cout << "X win!\n"; break;
			}
			if (game == 'O')
			{
				cout << "O win\n"; break;
			}
			if (game == '=')
			{
				cout << "Draw\n"; break;
			}
		}

		Bot_O(turne); turne++;
		if (turne >= 5)
		{game = CONTROL(turne);
			if (game == 'X')
			{cout << "X win!\n"; break;
			}
			if (game == 'O')
			{cout << "O win\n"; break;
			}
			if (game == '=')
			{cout << "Draw\n"; break;
			}

		}
	}
	Draw();
	Sleep(1000);
	return new_game(turne, walk,game);
	
}


void Bot_O(int turne)
{
#define PASIV
#define CENTRAL
#define VERTICAL_ATTACK
#define DIAGONAL_ATTACK
#define HORIZONTAL_ATTACK
#define VERTICAL_PROTECTION
#define DIAGONAL_PROTECTION
#define HORIZONTAL_PROTECTION

#ifdef CENTRAL
	if (arr[4] == ' ') // center
	{
		arr[4] = 'O'; return;
	}
	else if (turne == 1)
	{
		if (arr[0] == ' ') arr[0] = 'O'; return;
	}
#endif CENTRAL

#ifdef DIAGONAL_ATTACK
	if (arr[0] == arr[4] && arr[4] == 'O' && arr[8] == ' ')
	{
		arr[8] = 'O'; return;
	}
	else if (arr[2] == arr[4] && arr[2] == 'O' && arr[6] == ' ')// right
	{
		arr[6] = 'O'; return;
	}
	else if (arr[8] == arr[4] && arr[4] == 'O' && arr[0] == ' ')
	{
		arr[0] = 'O'; return;
	}
	else if (arr[6] == arr[4] && arr[4] == 'O' && arr[2] == ' ')// left
	{
		arr[2] = 'O'; return;
	}


#endif //DIAGONAL_ATTACK

#ifdef VERTICAL_ATTACK
	for (int i = 0; i < 3; i++) // vertical attack
	{
		if (arr[i] == arr[i + 3] && arr[i] == 'O' && arr[i + 6] == ' ')
		{
			arr[i + 6] = 'O'; return;
		}
		if (arr[i] == arr[i + 6] && arr[i] == 'O' && arr[i + 3] == ' ')
		{
			arr[i + 3] = 'O'; return;
		}
		if (arr[i + 3] == arr[i + 6] && arr[i + 3] == 'O' && arr[i] == ' ')
		{
			arr[i] = 'O'; return;
		}
	}
#endif //VERTICAL_ATTACK

#ifdef HORIZONTAL_ATTACK
	for (int i = 0; i < 9; i += 3)		// horizontal protection 
	{
		if (arr[i] == 'O' && arr[i] == arr[i + 1] && arr[i + 2] == ' ')
		{
			arr[i + 2] = 'O'; return;
		}
		else if (arr[i + 1] == 'O' && arr[i + 2] == arr[i + 1] && arr[i] == ' ')
		{
			arr[i] = 'O'; return;
		}
		else if ( arr[i] == 'O' && arr[i] == arr[i + 2] && arr[i + 1] == ' ')
		{
			arr[i + 1] = 'O'; return;
		}
	}
#endif //HORIZONTAL_ATTACK

#ifdef VERTICAL_PROTECTION
	for (int i = 0; i < 3; i++) //vertical protection
	{
		if (arr[i] == arr[i + 3] && arr[i] == 'X' && arr[i + 6] == ' ')
		{
			arr[i + 6] = 'O'; return;
		}
		else if (arr[i + 3] == arr[i + 6] && arr[i + 3] == 'X' && arr[i] == ' ')
		{
			arr[i] = 'O'; return;
		}
		else if (arr[i] == arr[i + 6] && arr[i] == 'X' && arr[i + 3] == ' ')
		{
			arr[i + 3] = 'O'; return;
		}
	}
#endif //VERTICAL_PROTECTION

#ifdef HORIZONTAL_PROTECTION
	for (int i = 0; i < 9; i += 3)		// horizontal protection 
	{
		if (arr[i] == 'X' && arr[i] == arr[i + 1] && arr[i + 2] == ' ')
		{
			arr[i + 2] = 'O'; return;
		}
		else if (arr[i + 1] == 'X' && arr[i + 2] == arr[i + 1] && arr[i] == ' ')
		{
			arr[i] = 'O'; return;
		}
		else if (arr[i + 1] == ' ' && arr[i] == arr[i + 2] && arr[i] == 'X')
		{
			arr[i + 1] = 'O'; return;
		}
	}
#endif //HORIZONTAL_PROTECTION

#ifdef DIAGONAL_PROTECTION

	if (arr[0] == arr[4] && arr[4] == 'X' && arr[8] == ' ')// right
	{
		arr[8] = 'O'; return;
	}
	else if (arr[2] == arr[4] && arr[2] == 'X' && arr[6] == ' ') 
	{
		arr[6] = 'O'; return;
	}
	else if (arr[8] == arr[4] && arr[4] == 'X' && arr[0] == ' ') // left
	{
		arr[0] = 'O'; return;
	}
	else if (arr[6] == arr[4] && arr[4] == 'X' && arr[2] == ' ')
	{
		arr[2] = 'O'; return;
	}

#endif // DIAGONAL_PROTECTION

#ifdef PASIV
	for (int i = 0; i < 9; i++)		// horizontal protection 
	{
		if (arr[i] == ' ')
		{
			arr[i] = 'O'; return;
		}
	}
#endif // PASIV

}
char CONTROL(int turne)
{
	int wins[][3] = { {0,1,2},{3,4,5},{6,7,8},{0,3,6},{1,4,7},{2,5,8},{0,4,8},{2,4,6} };
	for (int i = 0; i < 8; i++)
	{ 
		int count_x = 0, count_o = 0;

	   for (int j = 0; j < 3; j++)
      {
	 	   if (arr[wins[i][j]] == 'X') count_x++;// counter X

		   else if (arr[wins[i][j]] == 'O')  count_o++; // counter O

		   else break;
	  }
       if (count_x == 3) return 'X';	// victory sign X
	   else if (count_o == 3) return 'O'; // victory sign O
	}
	  if (turne == 10) return '='; // Draw

	return '!';
}
char Walk(int turne, char walk)
{
//	turne % 2 == 0 ? walk = 'X' : walk = 'O';
	cout << endl << "Turn " << walk << endl;
	cout << "turne " << turne << endl;
	char play = _getch();
	switch (play)
	{
	case '7': arr[0] == ' ' ? arr[0] = walk : Walk(turne, walk); break;
	case '8': arr[1] == ' ' ? arr[1] = walk : Walk(turne, walk); break;
	case '9': arr[2] == ' ' ? arr[2] = walk : Walk(turne, walk); break;
	case '4': arr[3] == ' ' ? arr[3] = walk : Walk(turne, walk); break;
	case '5': arr[4] == ' ' ? arr[4] = walk : Walk(turne, walk); break;
	case '6': arr[5] == ' ' ? arr[5] = walk : Walk(turne, walk); break;
	case '1': arr[6] == ' ' ? arr[6] = walk : Walk(turne, walk); break;
	case '2': arr[7] == ' ' ? arr[7] = walk : Walk(turne, walk); break;
	case '3': arr[8] == ' ' ? arr[8] = walk : Walk(turne, walk); break;
	default:
		return Walk(turne,walk);
	}
	system("cls");
	return 0;
}
void Draw()
{
	for (int i = 0; i < n; i++)
	{
	    if (arr[i] == 'X')
			setColor(Red);
		else if (arr[i] == 'O') // цвет для знаков
			setColor(Blue);

		cout <<" "<<arr[i]; 

		setColor(White);

		if (i == 2 || i == 5)
			cout << "\n---+---+---\n";
		// вывод поля
		else if (i != 8)	
			cout << " |";		
	}
}
void Set_Board()
{
	for (int i = 0; i < n; i++)
		arr[i] = ' ';
}

void new_game(int turne, char walk, char game)
{
	game = '!';
	walk = 'X';
	turne = 0;
	Set_Board();
	system("cls");
	Game_x(turne, walk, game);
}

































