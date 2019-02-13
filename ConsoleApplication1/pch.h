// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.

#ifndef PCH_H
#define PCH_H

// TODO: add headers that you want to pre-compile here
enum Direction
{
	STOP, UPRIGHT, DOWNRIGHT, UPLEFT, DOWNLEFT, UP, DOWN //enum for directions
};
class Field //gaming field 
{
	int width; // width of field
	int length; // length 
public:
	Field();//default consructor for class Field
	Field(int x, int y); // constructor for class Field, x is width of Field, y is length of Field
	void print_Field(int coor_x, int coor_y, int g1_y, int g2_y,int scoreG1, int scoreG2); // function for drawing field, ball(coor_x, coor_y), players (g#_y) and their scores(scoreG#)
	int getWidth(); //get width of the field
	int getLength();//get length of the field
};
class Ball
{
	int posX, posY; // position of ball
	int startX, startY; //start position of the ball
public:
	Ball(); //default constructor for class Ball
	Ball(int width, int length); //constructor for class Ball, width is width of gaming field, length is length  of gaming field
	void Move(int dir);//function to move ball in different directions
	int get_posX();//get X coordinate for ball
	int get_posY();//get Y coordinate for ball
	void Reset();//set ball in start position
};
class Gamer
{
	int X,Y;// coordinates of gamer
	int startX, startY;// start coordinates of gamer
public:
	Gamer();//default constructor for class Gamer
	Gamer(int width, int length, int number); //construtor for class gamer, width is width of gaming field, length is length  of gaming field, number of gamer, 0 is left gamer
	void MovePlayer(int dir);// move olayer up or down
	int get_X();// get X coordinate of gamer
	int get_Y();// get Y coordinate of gamer
	void Reset();// set gamer is default position

};
class Judge
{
	int scoreG0, scoreG1, finalScore; //scores of gamers and final score
	Gamer * gamer0;//pointer on left gamer
	Gamer * gamer1;//pointer on right gamer
	Ball * ball;//pointer on ball
	Field * field;//pointer on field
	int currentDir;//current direction of the ball
	bool lose, end;//lose is true when one of players scores goal, end is true when score reaches final score
public:
	Judge();//default constructor for class Judge
	Judge(Gamer * G0, Gamer * G1, Ball * B, Field * F, int finScore);//constructor for class Judge, G0, G1, B, F are pointers on players, ball and field, finScore is final score
	void Input();//function to get commands from players
	int randomDir();//return random dir for ball, it can be UPRIGHT, DOWNRIGHT, UPLEFT, DOWNLEFT
	void changeDir();//function controls deflection of the ball from walls of gaming field and from paddles of players and scoring goals
	void winner();//function checks equality fianal score and scores of players and detects winner
	int getCurDir();//return current direction of the ball
	int getScoreG0();//return current score of left player
	int getScoreG1();//retrurn current score of right player
	bool getLose();//returm lose
	bool getEnd();//return end

};
#endif //PCH_H
