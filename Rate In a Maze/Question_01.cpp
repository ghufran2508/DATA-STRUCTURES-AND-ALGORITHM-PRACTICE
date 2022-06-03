#include<iostream>
#include<fstream>
#include"stack_point.h"

using namespace std;


char** initialize_board(int * size, int* start_i, int* start_j, int* end_i, int* end_j)
{
	ifstream input;
	input.open("in.txt");

	if (input.fail())
	{
		cout << "Game does not exist!!!" << endl;
		exit(0);
	}
	else
	{
		char** board;

		input >> *size;
		input >> *start_i >> *start_j;
		input >> *end_i >> *end_j;

		board = new char* [*size];
		for (int i = 0; i < *size; i++)
			board[i] = new char[*size];

		for (int i = 0; i < *size; i++)
		{
			for (int j = 0; j < *size; j++)
			{
				input >> board[i][j];
			}
		}

		board[*start_i][*start_j] = 'm';
		board[*end_i][*end_j] = 'c';

		return board;
	}
}

void delete_game(char**& board, int size)
{
	for (int i = 0; i < size; i++)
		delete board[i];

	delete[]board;
}

bool alread_check(stack check, int x, int y)
{
	while (!check.isEmpty())
	{
		point* temp = check.pop();
		if (temp->getx() == x && temp->gety() == y)
			return true;
	}
	return false;
}

bool way_out(char** board, int size, int position_i, int position_j, stack& checks)
{
	if ((position_i < 0 || position_i >= size) || (position_j < 0 || position_j >= size))
	{
		return false;
	}
	if (board[position_i][position_j] == '1')
	{
		return false;
	}
	stack temp = checks;


	if (alread_check(temp, position_i, position_j))
		return false;


	checks.push(position_i, position_j);
	if (board[position_i][position_j] == 'c')
	{
		return true;
	}
	if (board[position_i][position_j] == '0' || board[position_i][position_j] == 'm')
	{
		if (way_out(board, size, position_i + 1, position_j, checks))
		{
			return true;
		}
		if (way_out(board, size, position_i, position_j + 1, checks))
		{
			return true;
		}
		if (way_out(board, size, position_i, position_j - 1, checks))
		{
			return true;
		}
		if (way_out(board, size, position_i - 1, position_j,checks))
		{
			return true;
		}
	}
	checks.pop();
	return false;
}

void trace(char**& board, stack& moves)
{
	stack rev;
	while (!moves.isEmpty())
	{
		point* temp = moves.pop();
		rev.push(temp->getx(), temp->gety());
		
		board[temp->getx()][temp->gety()] = '*';
	}

	while (!rev.isEmpty())
	{
		point* temp = rev.pop();
		cout << "(" << temp->getx() << "," << temp->gety() << ") ";
	}
	cout << endl;
}

void show(char**& board, stack moves, int size, int start_i, int start_j, int end_i, int end_j)
{
	cout << size << endl;
	cout << start_i << " " << start_j << endl;
	cout << end_i << " " << end_j << endl;
	trace(board, moves);
	cout << endl;

	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			cout << board[i][j] << " ";
		}
		cout << endl;
	}
}

void save_game(char** board, stack& path, int size, int start_i, int start_j, int end_i, int end_j)
{
	ofstream output;
	output.open("out.txt");

	if (output.fail())
	{
		cout << "Game cannot be saved!!!" << endl;
		exit(0);
	}
	else
	{
		output << size << endl;
		output << start_i << " " << start_j << endl;
		output << end_i << " " << end_j << endl;

		stack temp;
		point* temp_p;
		while (!path.isEmpty())
		{
			temp_p = path.pop();

			temp.push(temp_p->getx(), temp_p->gety());
		}

		while (!temp.isEmpty())
		{
			temp_p = temp.pop();

			output << "(" << temp_p->getx() << "," << temp_p->gety() << ")";
		}

		output << endl;
		for (int i = 0; i < size; i++)
		{
			for (int j = 0; j < size; j++)
			{
				output << board[i][j] << " ";
			}
			output << endl;
		}
	}
}

int main()
{
	int size,start_i,start_j,end_i,end_j;
	char** game_board = initialize_board(&size,&start_i,&start_j,&end_i,&end_j);
	stack checks;

	if (way_out(game_board, size, start_i, start_j, checks))
	{
		show(game_board, checks, size, start_i, start_j, end_i, end_j);
		cout << "WOOOOOWWW!!!!" << endl;
	}
	else
	{
		cout << "GOOD try!!!" << endl;
	}
	
	save_game(game_board, checks, size, start_i, start_j, end_i, end_j);

	delete_game(game_board, size);

	return 0;
}