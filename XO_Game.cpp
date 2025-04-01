#include <iostream>
using namespace std;

//This function is responsible for drawing the boundries of the Game
void DrawBorders(char A[3][3])
{
	//Drawing 7 Lines
	for (int i = 0;i < 7;i++)
	{
		//this is for drawing -------------
		if (i % 2 == 0)
		{
			//
			for (int i = 0;i < 13;i++)
			{
				cout << "-";
			}
		}
		else
		{
			//this is for drawing |   |   |   |
			for (int j = 0;j < 4;j++)
			{
				if (A[i / 2][j] != ' ' && j < 3)
				{
					cout << "| " << A[i / 2][j] << " ";
				}
				else //this is for drawing the last | on the right
				{
					cout << "|   ";
				}
			}

		}
		cout << endl;
	}
}

char CheckWinner(char A[3][3])
{
	//Check Diagonal
	if (A[0][0] != ' ' && A[0][0] == A[1][1] && A[1][1] == A[2][2])
		return A[0][0];

	//check Diagonal
	if (A[0][2] != ' ' && A[0][2] == A[1][1] && A[1][1] == A[2][0])
		return A[0][2];

	//check Horizontal
	for (int i = 0;i < 3;i++)
	{
		if (A[i][0] != ' ' && A[i][0] == A[i][1] && A[i][1] == A[i][2])
			return A[i][0];
	}

	//check Vertical
	for (int i = 0;i < 3;i++)
	{
		if (A[0][i] != ' ' && A[0][i] == A[1][i] && A[1][i] == A[2][i])
			return A[0][i];
	}

	//no winner
	return ' ';
}

void SelectIndices(int Place, int& x, int& y)
{
	switch (Place)
	{
	case 1:
		x = 0;
		y = 0;
		break;
	case 2:
		x = 0;
		y = 1;
		break;
	case 3:
		x = 0;
		y = 2;
		break;
	case 4:
		x = 1;
		y = 0;
		break;
	case 5:
		x = 1;
		y = 1;
		break;
	case 6:
		x = 1;
		y = 2;
		break;
	case 7:
		x = 2;
		y = 0;
		break;
	case 8:
		x = 2;
		y = 1;
		break;
	case 9:
		x = 2;
		y = 2;
		break;
	default:
		x = 0;
		y = 0;
		break;
	}
}


void PlayGame()
{
	char board[3][3];
	for (int i = 0;i < 3;i++)
	{
		for (int j = 0;j < 3;j++)
		{
			board[i][j] = ' ';
		}
	}
	DrawBorders(board);

	char GameOver = ' ';
	bool isX = true;
	int PlayCount = 0;
	do
	{
		int x = 0, y = 0;
		int Place = 0;
		cout << "Please Choose Wich block? from 1-9 ? ";
		cin >> Place;
		SelectIndices(Place, x, y);

		while (board[x][y] != ' ')
		{
			cout << "This already filled choose another one.\n";
			cin >> x >> y;
		}


		if (isX)
		{
			board[x][y] = 'X';
		}
		else
		{
			board[x][y] = 'Y';
		}

		DrawBorders(board);
		PlayCount++;
		GameOver = CheckWinner(board);
		if (GameOver == ' ' && PlayCount == 9)
		{
			cout << "\nGame Over No one won.\n";
			break;
		}

		isX = !isX;
	} while (GameOver == ' ');


	if (GameOver != ' ')
	{
		cout << GameOver << " won.";
	}
}


int main()
{

	PlayGame();


	return 0;
}

