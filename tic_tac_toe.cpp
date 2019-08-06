#include <iostream>
#include <vector>
#include <ctime>
#include <stdlib.h>
using namespace std;

//Functions
void interface(); 
void intro();
void player_move();
void computer_move();
void winner();
int win_check(); 
int ai_easy();
int ai_hard();
int two_in_line();

//Variables
char value[10] = {'1','2','3','4','5','6','7','8','9'};
int selected[2];
int turn = 0;
int player = 0;  // Decide whose turn
int gate = 1;
char p_mark,c_mark; 


int main() {
	char play_again = 'y';
	while (play_again == 'y' or play_again == 'Y')
	{
		for (int i = 0; i <= 9; i++)
		{
			value[i] = '1' + i;
		}
		turn = 0;
		gate = 1;
		intro();
		if (selected[1] == 1)
		{
			turn = 1;
			p_mark = 'X';
			c_mark = 'O';
		}
		else if (selected[1] == 2)
		{
			turn = 2;
			p_mark = 'O';
			c_mark = 'X';
		}
		do
		{
			interface();
			player = turn % 2;
			if (player == 1)
			{
				player_move();
				turn++;
			}
			else if (player == 0)
			{
				computer_move();
				turn++;
			}
			gate = win_check();
			if (gate == 0 or gate == -1) break;
		}while(gate == 1);
		gate = win_check();
		winner();	
		cout << "Continue? (Y/N) ";
		cin >> play_again;	
		while (play_again != 'y' and play_again != 'n' and play_again != 'Y' and play_again != 'N')
		{
			interface();
			cout << "Choose wisely! " << endl;
			cout << "Continue? (Y/N) ";
			cin >> play_again;
		}
	}
	system("cls");
	cout <<  "\n\n";
	cout << "====================================" << endl;
	cout << "             Bye - Bye" << endl;	
	cout << "====================================" << endl;	

	return 0;
}

void interface(){
	system("cls");
	cout << "   Tic Tac Toe   " << endl << endl;
	
	if (selected[0] == 1 and selected[1] == 1) 
	{	cout << "Player = X\nComputer = O" << endl;
		cout << "Difficulty: Easy" << endl << endl;
	}
	else if (selected[0] == 2 and selected[1] == 1)
	{	cout << "Player = X\nComputer = O" << endl; 
		cout << "Difficulty: Hard" << endl << endl;
	}
		
	else if (selected[0] == 1 and selected[1] == 2)
	{	cout << "Player = O\nComputer = X" << endl; 
		cout << "Difficulty: Easy" << endl << endl;
		
	}
	else if (selected[0] == 2 and selected[1] == 2)
	{
		cout << "Player = O\nComputer = X" << endl; 
		cout << "Difficulty: Hard" << endl << endl;
	}
		
		
	cout << "     |     |     " << endl;
	cout << "  " << value[0] << "  |  " << value[1] << "  |  " << value[2] << endl;
	cout << "-----------------" << endl;
	cout << "  " << value[3] << "  |  " << value[4] << "  |  " << value[5] << endl;
	cout << "-----------------" << endl;
	cout << "  " << value[6] << "  |  " << value[7] << "  |  " << value[8] << endl;
	cout << "     |     |     " << endl;
}

void intro()
{
	system("cls"); 
	cout <<  "\n\n";
	cout << "====================================" << endl;
	cout << "      Wlecome To Tic Tac Toe" << endl;	
	cout << "====================================" << endl;
	cout << "              " << "1. Easy" << endl;
	cout << "              " << "2. Hard" << endl << endl;
	cout << "Choose level: "; 
	cin >> selected[0];
	system("cls"); 
	// InputError voider begin
	while (!cin)
	{
		system("cls");
		cin.clear();
		cin.ignore(1, '\n');
		cout <<  "\n\n";
		cout << "====================================" << endl;
		cout << "      Wlecome To Tic Tac Toe" << endl;	
		cout << "====================================" << endl;
		cout << "              " << "1. Easy" << endl;
		cout << "              " << "2. Hard" << endl << endl;
		cout << "Choose wisely!" << endl;
		cout << "Choose level: "; 
		cin >> selected[0];	
	} 
	while (selected[0] != 1 and selected[0] != 2)
	{
		system("cls");
		cin.clear();
		cin.ignore(1, '\n');
		cout <<  "\n\n";
		cout << "====================================" << endl;
		cout << "      Wlecome To Tic Tac Toe" << endl;	
		cout << "====================================" << endl;
		cout << "              " << "1. Easy" << endl;
		cout << "              " << "2. Hard" << endl << endl;
		cout << "Choose wisely!" << endl;		
		cout << "Choose level: "; 
		cin >> selected[0];			
	}
	// InputError voider ends
	system("cls");
	cout <<  "\n\n";
	cout << "====================================" << endl;
	cout << "      Wlecome To Tic Tac Toe" << endl;	
	cout << "====================================" << endl;
	cout << "              " << "1. Player" << endl;
	cout << "              " << "2. Computer" << endl << endl;
	cout << "Who go first: ";
	cin >> selected[1];
	while (!cin)
	{
		system("cls");
		cin.clear();
		cin.ignore(1, '\n');		
		cout <<  "\n\n";
		cout << "====================================" << endl;
		cout << "      Wlecome To Tic Tac Toe" << endl;	
		cout << "====================================" << endl;
		cout << "              " << "1. Player" << endl;
		cout << "              " << "2. Computer" << endl << endl;
		cout << "Choose wisely!" << endl;
		cout << "Who go first: ";
		cin >> selected[1];		
	}
	while (selected[1] != 1 and selected[1] != 2)
	{
		system("cls");
		cin.clear();
		cin.ignore(1, '\n');		
		cout <<  "\n\n";
		cout << "====================================" << endl;
		cout << "      Wlecome To Tic Tac Toe" << endl;	
		cout << "====================================" << endl;
		cout << "              " << "1. Player" << endl;
		cout << "              " << "2. Computer" << endl << endl;
		cout << "Choose wisely!" << endl;
		cout << "Who go first: ";
		cin >> selected[1];			
	}
}

int win_check()
{
	if (value[0] == value[1] and value[1] == value[2]) return -1;
	else if (value[3] == value[4] and value[4] == value[5]) return -1;
	else if (value[6] == value[7] and value[7] == value[8]) return -1;
	else if (value[0] == value[3] and value[3] == value[6]) return -1;
	else if (value[1] == value[4] and value[4] == value[7]) return -1;
	else if (value[2] == value[5] and value[5] == value[8]) return -1;
	else if (value[0] == value[4] and value[4] == value[8]) return -1;
	else if (value[2] == value[4] and value[4] == value[6]) return -1;
	else if (value[0] != '1' and value[1] != '2' and value[2] != '3' and value[3] != '4' and
			 value[4] != '5' and value[5] != '6' and value[6] != '7' and value[7] != '8' and
			 value[8] != '9') return 0;
	else 
		return 1;	
}

void player_move()
{
	int p_move;
	cout << "Player's Turn:  ";
	cin >> p_move;
	
	// InputError voider begin
	while (!cin)
	{
		interface();
		cin.clear();
		cin.ignore(1000,'\n');
		cout << "Invalid Move  Choose Again" << endl;
		cout << "Player's Turn:  ";
		cin >> p_move;		
	}
	while (p_move < 1 or p_move > 9 or value[p_move-1] == 'X' or value[p_move-1] == 'O')
	{
		interface();
		cin.clear();
		cin.ignore(1000,'\n');
		cout << "Invalid Move  Choose Again" << endl;
		cout << "Player's Turn:  ";
		cin >> p_move;		
	}
	// InputError voider ends
	if (p_move == 1 and value[0] == '1') value[0] = p_mark;
	else if (p_move == 2 and value[1] == '2') value[1] = p_mark;
	else if (p_move == 3 and value[2] == '3') value[2] = p_mark;
	else if (p_move == 4 and value[3] == '4') value[3] = p_mark;
	else if (p_move == 5 and value[4] == '5') value[4] = p_mark;
	else if (p_move == 6 and value[5] == '6') value[5] = p_mark;
	else if (p_move == 7 and value[6] == '7') value[6] = p_mark;
	else if (p_move == 8 and value[7] == '8') value[7] = p_mark;
	else if (p_move == 9 and value[8] == '9') value[8] = p_mark;
	interface();
}
void computer_move()
{
	int c_move;
	if (selected[0] == 1)
	{
		c_move = ai_easy();
		value[c_move] = c_mark;
		interface();
	}
	else if (selected[0] == 2)
	{
		c_move = ai_hard();
		value[c_move] = c_mark;
		interface();
	}

}

void winner()
{
	if ( player == 1 and gate == -1)  // player win
	{
		cout <<  "\n\n";
		cout << "===================================" << endl;
		cout << "       Winner is Player"  << endl;
		cout << "===================================" << endl;
	}
	else if ( player == 0 and gate == -1)  // computer win
	{
		cout <<  "\n\n";
		cout << "===================================" << endl;
		cout << "       Winner is Computer"  << endl;
		cout << "===================================" << endl;
	}
	else if ( gate == 0 )
	{
		cout <<  "\n\n";
		cout << "====================================" << endl;
		cout << "              D r a w"  << endl;
		cout << "====================================" << endl;		
	}
}

int two_in_line()
{
	vector<char> mark;
	mark.push_back(c_mark);
	mark.push_back(p_mark);
	// when player and computer both have 2 in line
	// make sure computer will play the winning step first
	// instead of blocking player
	for (int i = 0; i <= 1; i++)
	{
		if ((value[1] == mark[i] and value[2] == mark[i] and value[0] == '1') or 
			(value[3] == mark[i] and value[6] == mark[i] and value[0] == '1') or 
			(value[4] == mark[i] and value[8] == mark[i] and value[0] == '1'))		return 0; 
		else if ((value[0] == mark[i] and value[2] == mark[i] and value[1] == '2') or 
			(value[4] == mark[i] and value[7] == mark[i] and value[1] == '2'))	return 1; 
		else if ((value[0] == mark[i] and value[1] == mark[i] and value[2] == '3') or 
			(value[4] == mark[i] and value[6] ==mark[i] and value[2] == '3') or 
			(value[5] == mark[i] and value[8] == mark[i] and value[2] == '3'))	return 2; 
		else if ((value[0] == mark[i] and value[6] == mark[i] and value[3] == '4') or 
			(value[4] == mark[i] and value[5] == mark[i] and value[3] == '4'))	return 3; 
		else if ((value[0] == mark[i] and value[8] == mark[i] and value[4] == '5') or 
			(value[2] == mark[i] and value[6] == mark[i] and value[4] == '5') or 
			(value[1] == mark[i] and value[7] == mark[i] and value[4] == '5') or 
			(value[3] == mark[i] and value[5] == mark[i]) and value[4] == '5')	return 4;
		else if ((value[3] == mark[i] and value[4] == mark[i] and value[5] == '6') or 
			(value[2] == mark[i] and value[8] == mark[i] and value[5] == '6'))	return 5;
		else if ((value[0] == mark[i] and value[3] == mark[i] and value[6] == '7') or 
			(value[7] == mark[i] and value[8] == mark[i] and value[6] == '7') or 
			(value[2] == mark[i] and value[4] == mark[i] and value[6] == '7'))	return 6;
		else if ((value[1] == mark[i] and value[4] == mark[i] and value[7] == '8') or 
			(value[6] == mark[i] and value[8] == mark[i] and value[7] == '8'))	return 7;	
		else if ((value[2] == mark[i] and value[5] == mark[i] and value[8] == '9') or 
			(value[0] == mark[i] and value[4] == mark[i] and value[8] == '9') or 
			(value[6] == mark[i] and value[7] == mark[i] and value[8] == '9'))	return 8;		
	}
	return -1;
}

int ai_easy() 
{
	int move;
	vector<int> count_blank;
	if (selected[1] == 2 and turn == 2)
	{
		move = 0;
		return move;
	}
	move = two_in_line();
	if (move != -1) return move;
	else 
	{
		//check blank
		count_blank.clear();
		for (int i = 0; i<= 8; i++)
		{
			if (value[i] != 'X' and value[i] != 'O')  count_blank.push_back(i);
		}
		//check end
		srand(time(NULL));
		move = count_blank[rand()%count_blank.size()];
	}
	return move; // return index of value[index]
}

int ai_hard()
{
	int move;
	vector<int> count_blank;
	// AI go first
	if (selected[1] == 2)
	{
		if (turn == 2) return 0;		// first step must go '1' 
		// second step of AI
		else if (turn == 4) 
		{
      if (value[4] == p_mark) return 7;
			else if (value[5] != '6' or value[7] != '8') return 4;
			else if (value[3] != '4') return 8;
			else if (value[1] != '2') return 3;
			else if (value[4] != '5')  return 8;
			else if (value[2] != '3' or value[6] != '7') return 8;
			else if (value[8] != '9') return 2; 
		}
		//X|O|X
		// | | 
		//=| |O And its rotation formate 
		else if (turn == 6)
		{
			if (value[0] == c_mark and value[2] == c_mark and value[1] == p_mark and value[8] == p_mark) return 6;
			else if (value[2] == c_mark and value[8] == c_mark and value[5] == p_mark and value[6] == p_mark) return 0;
			else if (value[6] == c_mark and value[8] == c_mark and value[0] == p_mark and value[7] == p_mark) return 2;	
			else if (value[0] == c_mark and value[6] == c_mark and value[2] == p_mark and value[3] == p_mark) return 9;		
			else if (value[0] == c_mark and value[2] == c_mark and value[1] == p_mark and value[6] == p_mark) return 9;	
			else if (value[6] == c_mark and value[8] == c_mark and value[2] == p_mark and value[7] == p_mark) return 0;	
			else if (value[0] == c_mark and value[6] == c_mark and value[3] == p_mark and value[8] == p_mark) return 2;	
			else if (value[2] == c_mark and value[8] == c_mark and value[0] == p_mark and value[5] == p_mark) return 6;		
		}		 
    else if (turn == 6){
      if (value[0] == c_mark and value[3] == c_mark and value[1] == p_mark and value[6] == p_mark) return 4;
    }
	} 
 	
 	// Player first
	else if (selected[1] == 1 and turn == 2)
	{
		if (value[1] != '2' or value[3] != '4') return 0; 
		else if (value[5] != '6' or value[7] != '8') return 8; 
		else if (value[4] != '5') return 8;
		else if (value[0] != '1' or value[2] != '3' or value[6] != '7' or value[8] != '9') return 4;
	}
	

	else if (selected[1] == 1 and turn == 4)
	{
		//O|X|  
		//X|=|  
		// | |    
		if ((value[0] == c_mark and value[1] == p_mark and value[3] == p_mark) or 
			(value[1] == p_mark and value[2] == c_mark and value[5] == p_mark) or
			(value[5] == p_mark and value[7] == p_mark and value[8] == c_mark) or
			(value[3] == p_mark and value[6] == c_mark and value[7] == p_mark)) return 4;
		// |X|O 
		//X|=|
		// | |
		else if ((value[1] == p_mark and value[3] == p_mark and value[2] == c_mark) or
				 (value[3] == p_mark and value[7] == p_mark and value[0] == c_mark) or
				 (value[5] == p_mark and value[7] == p_mark and value[6] == c_mark) or
				 (value[1] == p_mark and value[5] == p_mark and value[8] == c_mark) or
				 (value[1] == p_mark and value[3] == p_mark and value[6] == c_mark) or
				 (value[2] == p_mark and value[6] == p_mark and value[0] == c_mark) or
				 (value[5] == p_mark and value[7] == p_mark and value[2] == c_mark) or
				 (value[7] == p_mark and value[3] == p_mark and value[8] == c_mark)) return 4;		
		// | |X  // | |X
		// |=|   // |=|
		// |X|O  //O|X|
		else if ((value[2] == p_mark and value[7] == p_mark and (value[8] == c_mark or value[6] == c_mark)) or 
				 (value[3] == p_mark and value[8] == p_mark and (value[0] == c_mark or value[6] == c_mark)) or
				 (value[1] == p_mark and value[6] == p_mark and (value[0] == c_mark or value[2] == c_mark)) or
				 (value[0] == p_mark and value[5] == p_mark and (value[2] == c_mark or value[8] == c_mark)) or
				 (value[0] == p_mark and value[7] == p_mark and (value[8] == c_mark or value[6] == c_mark)) or
				 (value[2] == p_mark and value[3] == p_mark and (value[0] == c_mark or value[6] == c_mark)) or
				 (value[1] == p_mark and value[8] == p_mark and (value[0] == c_mark or value[2] == c_mark)) or
				 (value[5] == p_mark and value[6] == p_mark and (value[2] == c_mark or value[8] == c_mark))) return 4;
		
		//X|=|
		// |O|
		// | |X And Rotation
		else if ((value[0] == p_mark and value[4] == c_mark and value[8] == p_mark) or
				 (value[2] == p_mark and value[4] == c_mark and value[6] == p_mark)) return 1;
		// | |
		//X|O|
		//=| |X
		else if (value[3] == p_mark and value[4] == c_mark and value[8] == p_mark) return 6;
		else if (value[1] == p_mark and value[4] == c_mark and value[6] == p_mark) return 5;
		else if (value[0] == p_mark and value[4] == c_mark and value[5] == p_mark) return 7;
		else if (value[2] == p_mark and value[4] == c_mark and value[7] == p_mark) return 3;
		else if (value[4] == c_mark and value[5] == p_mark and value[6] == p_mark) return 1;
		else if (value[0] == p_mark and value[4] == c_mark and value[7] == p_mark) return 5;
		else if (value[2] == p_mark and value[3] == p_mark and value[4] == c_mark) return 7;
		else if (value[1] == p_mark and value[4] == c_mark and value[8] == p_mark) return 3;
	}

	else if (selected[1] == 1 and turn == 6)
	{
		//X|O|
		//=| |X
		// |X|O
		if (value[0] == p_mark and value[5] == p_mark and value[7] == p_mark and value[1] == c_mark and value[8] == c_mark) return 3;
		else if (value[2] == p_mark and value[3] == p_mark and value[7] == p_mark and value[5] == c_mark and value[6] == c_mark) return 1;	
		else if (value[1] == p_mark and value[3] == p_mark and value[8] == p_mark and value[0] == c_mark and value[7] == c_mark) return 5;
		else if (value[2] == p_mark and value[6] == p_mark and value[7] == p_mark and value[2] == c_mark and value[3] == c_mark) return 7;
		else if (value[2] == p_mark and value[3] == p_mark and value[7] == p_mark and value[1] == c_mark and value[6] == c_mark) return 5;	
		else if (value[1] == p_mark and value[3] == p_mark and value[8] == p_mark and value[0] == c_mark and value[5] == c_mark) return 7;
		else if (value[1] == p_mark and value[5] == p_mark and value[6] == p_mark and value[2] == c_mark and value[7] == c_mark) return 3;	
		else if (value[0] == p_mark and value[5] == p_mark and value[7] == p_mark and value[3] == c_mark and value[8] == c_mark) return 1;				
	}
	move = two_in_line();
	if (move != -1) return move;
	

	//check blank
	count_blank.clear();
	for (size_t i = 0; i<= 8; i++)
	{
		if (value[i] != 'X' and value[i] != 'O')  count_blank.push_back(i);
	}
	//check end
	srand(time(NULL));
	move = count_blank[rand()%count_blank.size()];
	return move;
}