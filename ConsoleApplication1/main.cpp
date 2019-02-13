// ConsoleApplication1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>
#include <ctime>
#include <Windows.h>

bool is_digit(const char *S) { // return true if simbol is digit
	const char *temp = "0123456789-+";
	unsigned point_count = 0;

	for (int i = 0; i < strlen(S); i++) {
		if ((i > 0) && (S[i] == '+' || S[i] == '-')) return false;
		if (S[i] == '.') {
			point_count++;
			if (point_count > 1) return false;
		}
		if (!strchr(temp, S[i])) return false;
	}
	return true;
}

int main()
{
	using namespace std;
	srand(time(NULL));
	const int N = 256;
	bool work = true, end, checkX = true, checkY = true, checkS = true;
	int x=50, y=10, checkx = 0, checky = 0, finScore = 10, checks=0, wd1 = 0, wd2 = 0, wd3 = 0;
	char punkt, S[N] = {};
	Field field;
	Ball ball;
	Gamer gamer0;
	Gamer gamer1;
	Judge judge;
	void *handle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO structCursorInfo;
	GetConsoleCursorInfo(handle, &structCursorInfo);
	structCursorInfo.bVisible = FALSE;
	SetConsoleCursorInfo(handle, &structCursorInfo);
	cout << "Menu" << endl;
	cout << "0 - Print menu" << endl;
	cout << "1 - Print instruction" << endl;
	cout << "2 - Change proportions of gaming field" << endl;
	cout << "3 - Change final score" << endl;
	cout << "4 - Start game" << endl;
	cout << "5 - Exit" << endl;
	while (work)
	{
		cout << "Select the menu item" << endl;
		cin >> punkt;
		cin.get();
		switch (punkt)
		{
		case '0':
			cout << "Menu" << endl;
			cout << "0 - Print menu" << endl;
			cout << "1 - Print instruction" << endl;
			cout << "2 - Change proportions of gaming field" << endl;
			cout << "3 - Change final score" << endl;
			cout << "4 - Start game" << endl;
			cout << "5 - Exit" << endl;
			break;
		case '1':
			cout << "Welcome to game pong." << endl;
			cout << "Two players play in this game." << endl;
			cout << "The aim of the game is to score the goal to the gate of another player." << endl;
			cout << "One of the players win when his score reaches final score." << endl;
			cout << "Default final score is 10. You can change it by selecting menu item number 3" << endl;
			cout << "Players can move their paddle to prevent goal of another player." << endl;
			cout << "Left player can move his paddle up by pressing 'W' and down by pressing 'S'." << endl;
			cout << "Right player can move his paddle up by pressing 'U' and down by pressing 'J'." << endl;
			cout << "To start game press any button except 'B'" << endl;
			cout << "To quit game press 'B'." << endl;
			cout << "You can change proportion of gaming  field by selecting menu item number 2." << endl;
			cout << "Recomended width of gaming field is more than 20 and less than 100" << endl;
			cout << "Recomended length of gaming field is more than 6 and less than 20" << endl;
			break;
		case '2':
			cout << "Recomended width of gaming field is more than 20 and less than 100" << endl;
			cout << "Recomended length of gaming field is more than 6 and less than 20" << endl;
			while (checkX)
			{
				if (wd1 == 20) checkX = false;
				cout << "Enter width of gaming field" <<endl;
				cin.getline(S, N);
				while (!is_digit(S))
				{
					cout << "Enter number" << endl;
					cin.getline(S, N);
				}
				checkx = atoi(S);
				if (checkx < 5) cout << "Enter another width of gaming field"<<endl;
				else checkX = false;
				wd1++;
			}
			if (wd1 < 20)
			{
				x = checkx;
				wd1 = 0;
			}
			else cout << "Width didn't change" << endl;
			while (checkY)
			{
				if (wd2 == 20) checkY = false;
				cout << "Enter length of gaming field"<<endl;
				cin.getline(S, N);
				while (!is_digit(S))
				{
					cout << "Enter number" << endl;
					cin.getline(S, N);
				}
				checky = atoi(S);
				if (checky < 4) cout << "Enter another length of gaming field"<<endl;
				else checkY = false;
				wd2++;
			}
			if (wd2 < 20)
			{
				y = checky;
				wd2 = 0;
			}
			else cout << "Width didn't change" << endl;
			checkX = true;
			checkY = true;
			break;
		case '3':
			while (checkS)
			{
				cout << "Enter final score" << endl;
				cin.getline(S, N);
				while (!is_digit(S))
				{
					cout << "Enter number" << endl;
					cin.getline(S, N);
				}
				checks = atoi(S);
				if (checks < 1) cout << "Enter another final score" << endl;
				else checkS = false;
			}
			finScore = checks;
			checkS = true;
			break;
		case '4':
			cout << "To move left paddle UP use 'W' and DOWN use 'S'" << endl;
			cout << "To move right paddle UP use 'U' and DOWN use 'J'" << endl;
			cout << "To quit game press 'B'" << endl;
			Sleep(2000);
			field = Field(x, y);
			ball = Ball(field.getWidth(), field.getLength());
			gamer0 = Gamer(field.getWidth(), field.getLength(), 0);
			gamer1 = Gamer(field.getWidth(), field.getLength(), 1);
			judge = Judge(&gamer0, &gamer1, &ball, &field, finScore);
			end = judge.getEnd();
			ShowCursor(false);
			while (!end)
			{
				
				judge.Input();
				judge.changeDir();
				ball.Move(judge.getCurDir());
				if (judge.getLose())
				{
					ball.Reset();
					gamer0.Reset();
					gamer1.Reset();
				}
				field.print_Field(ball.get_posX(), ball.get_posY(), gamer0.get_Y(), gamer1.get_Y(), judge.getScoreG0(), judge.getScoreG1());
				Sleep(100);
				judge.winner();
				end = judge.getEnd();
			}
			ShowCursor(true);
			cout << "Menu" << endl;
			cout << "0 - Print menu" << endl;
			cout << "1 - Print instruction" << endl;
			cout << "2 - Change proportions of gaming field" << endl;
			cout << "3 - Change final score" << endl;
			cout << "4 - Start game" << endl;
			cout << "5 - Exit" << endl;
			break;
		case '5':
			work = false;
			cout << "Good game. GG." << endl;
			break;
		default:
			cout << "This menu item doesn't exist. Please select another menu item." << endl;
			break;
		}
	}

	
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
