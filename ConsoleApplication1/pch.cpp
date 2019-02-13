// pch.cpp: исходный файл, соответствующий предкомпилированному заголовку; нужен для компиляции

#include "pch.h"
#include <iostream>
#include <conio.h>
using namespace std;
// В целом этот файл можно пропустить, но не удаляйте его, если вы используете предкомпилированные заголовки.

Field::Field()
{
	width = 0;
	length = 0;
}

Field::Field(int x, int y)
{
	width = x;
	length = y;
	
}

void Field::print_Field(int coor_x, int coor_y, int g1_y,  int g2_y, int scoreG1, int scoreG2)
{
	system("cls");
	for (int i = 0; i < length + 2; i++)
	{
		for (int j = 0; j < width + 2; j++)
		{
			if (i == 0 || i == length + 1)
			{
				cout << "\xDB";
			}
			else if (j == 0 || j == width + 1) cout << "\xDB";
			else
			{
				if (i == g1_y + 1 && j == 1) cout << "\xBA";
				else if (i == g1_y + 2 && j == 1) cout << "\xBA";
				else if (i == g1_y + 3 && j == 1) cout << "\xBA";
				else if (i == g2_y + 1 && j == width) cout << "\xBA";
				else if (i == g2_y + 2 && j == width) cout << "\xBA";
				else if (i == g2_y + 3 && j == width) cout << "\xBA";
				else if (i == coor_y+1 && j == coor_x+1) cout << "0";
				else cout << " ";
			}
		}
		cout << endl;

	}
	cout << "Score left player " << scoreG1 << endl;
	cout << "Score rigt player " << scoreG2 << endl;
}

int Field::getWidth()
{
	return width;
}

int Field::getLength()
{
	return length;
}

Ball::Ball()
{
	posX = 0;
	posY = 0;
	startX = 0;
	startY = 0;
}

Ball::Ball(int width, int length)
{
	startX = width / 2;
	startY = length / 2;
	posX = startX;
	posY = startY;
}

void Ball::Move(int dir)
{
	switch (dir)
	{
	case STOP:
		posX = posX;
		posY = posY;
		break;
	case UPRIGHT:
		posX++;
		posY--;
		break;
	case UPLEFT:
			posX--;
			posY--;
			break;
	case DOWNLEFT:
		posX--;
		posY++;
		break;
	case DOWNRIGHT:
		posX++;
		posY++;
	}
}

int Ball::get_posX()
{
	return posX;
}

int Ball::get_posY()
{
	return posY;
}

void Ball::Reset()
{
	posX = startX;
	posY = startY;
}

Gamer::Gamer()
{
	startX = 0;
	startY = 0;
	X = startX;
	Y = startY;
}

Gamer::Gamer(int width, int length, int number)
{
	if (number == 0) startX = 0;
	else startX = width-1;
	startY = length / 2 - 1;
	X = startX;
	Y = startY;
}

void Gamer::MovePlayer(int dir)
{
	switch (dir)
	{
	case UP:
		Y--;
		break;
	case DOWN:
		Y++;
		break;
	case STOP:
		Y = Y;
		break;
	}
}

int Gamer::get_X()
{
	return X;
}

int Gamer::get_Y()
{
	return Y;
}

void Gamer::Reset()
{
	X = startX;
	Y = startY;
}

Judge::Judge()
{
	gamer0 = NULL;
	gamer1 = NULL;
	ball = NULL;
	field = NULL;
	currentDir = STOP;
	lose = false;
	end = false;
	scoreG0 = 0;
	scoreG1 = 0;
	finalScore = 10;
}

Judge::Judge(Gamer * G0, Gamer * G1, Ball * B, Field * F, int finScore)
{
	gamer0 = G0;
	gamer1 = G1;
	ball = B;
	field = F;
	currentDir = STOP;
	lose = false;
	end = false;
	scoreG0 = 0;
	scoreG1 = 0;
	finalScore = finScore;
}




void Judge::Input()
{
	int g0 = gamer0->get_Y();
	int g1 = gamer1->get_Y();
	char up0en = 'w', up0EN = 'W', up0ru = 'ц', up0RU = 'Ц', up1en = 'u', up1EN = 'U', up1ru = 'г', up1RU = 'Г';
	char down0en = 's', down0EN = 'S', down0ru = 'ы', down0RU = 'Ы', down1en = 'j', down1EN = 'J', down1ru = 'о', down1RU = 'О';
	if (_kbhit())
	{
		char current = _getch();
		if (current == 'b' || current == 'B'||current == 'и'||current=='И') end = true;
		else if (currentDir == STOP)
			{
			currentDir = randomDir();
			lose = false;
			}
		if (current == up0en || current == up0EN || current == up0ru || current == up0RU)
		{
			if (g0 > 0) gamer0->MovePlayer(UP);
		}
		if (current == up1en || current == up1EN || current == up1ru || current == up1RU)
		{
			if (g1 > 0) gamer1->MovePlayer(UP);
		}
		if (current == down0en || current == down0EN || current == down0ru || current == down0RU)
		{
			if (g0+3 <field->getLength()) gamer0->MovePlayer(DOWN);
		}
		if (current == down1en || current == down1EN || current == down1ru || current == down1RU)
		{
			if (g1+3 < field->getLength()) gamer1->MovePlayer(DOWN);
		}
	}
}

int Judge::randomDir()
{
	return rand()%3 +1;
}

void Judge::changeDir()
{
	int dir = 0;
	int X = ball->get_posX();
	int Y = ball->get_posY();
	bool c = false;
	if (X == 0)
	{
		scoreG1++;
		dir = STOP;
		lose = true;
		c = true;
	}
	if (X == field->getWidth() - 1)
	{
		scoreG0++;
		dir = STOP;
		lose = true;
		c = true;
	}
	else if (X == 1)
	{
		if (Y == gamer0->get_Y())
		{
			if (currentDir == DOWNLEFT) dir = UPRIGHT;
			else if (currentDir == UPLEFT) dir = UPRIGHT;
			if (Y == 0) dir = DOWNRIGHT;
			c = true;

		}
		if (Y == gamer0->get_Y()+1)
		{
			if (currentDir == DOWNLEFT) dir = DOWNRIGHT;
			else if (currentDir == UPLEFT) dir = UPRIGHT;
			c = true;
		}
		if (Y == gamer0->get_Y()+2)
		{
			if (currentDir == DOWNLEFT) dir = DOWNRIGHT;
			else if (currentDir == UPLEFT) dir = UPRIGHT;
			if (Y == field->getLength() - 1) dir = UPRIGHT;
			c = true;
			
		}
	}
	else if (X == field->getWidth() - 2)
	{
		if (Y == gamer1->get_Y())
		{
			if (currentDir == DOWNRIGHT) dir = UPLEFT;
			else if (currentDir == UPRIGHT) dir = UPLEFT;
			if (Y == 0) dir = DOWNLEFT;
			c = true;
		}
		if (Y == gamer1->get_Y() + 1)
		{
			if (currentDir == DOWNRIGHT) dir = DOWNLEFT;
			else if (currentDir == UPRIGHT) dir = UPLEFT;
			c = true;
		}
		if (Y == gamer1->get_Y() + 2)
		{
			if (currentDir == DOWNRIGHT) dir = DOWNLEFT;
			else if (currentDir == UPRIGHT) dir = UPLEFT;
			if (Y == field->getLength() - 1) dir = UPLEFT;
			c = true;
		}
	}
	if (Y == 0 && !c)
	{
		if (currentDir == UPLEFT) dir = DOWNLEFT;
		else if (currentDir == UPRIGHT) dir = DOWNRIGHT;
		c = true;
	}
	if (Y == field->getLength() - 1 && !c)
	{
		if (currentDir == DOWNLEFT) dir = UPLEFT;
		else if (currentDir == DOWNRIGHT) dir = UPRIGHT;
		c = true;
	}
	if (c) currentDir = dir;
}

void Judge::winner()
{
	if (scoreG0 == finalScore)
	{
		end = true;
		cout << endl;
		cout << "Left player won!!!" << endl;
		cout << endl;
	}
	if (scoreG1 == finalScore)
	{
		end = true;
		cout << endl;
		cout << "Right player won!!!" << endl;
		cout << endl;
	}
}

int Judge::getCurDir()
{
	return currentDir;
}

int Judge::getScoreG0()
{
	return scoreG0;
}

int Judge::getScoreG1()
{
	return scoreG1;
}

bool Judge::getLose()
{
	return lose;
}

bool Judge::getEnd()
{
	return end;
}


