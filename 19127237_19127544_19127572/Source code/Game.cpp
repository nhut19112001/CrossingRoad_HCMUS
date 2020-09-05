#include"Game.h"

POINT Y;//Người qua đường
POINT* X;
int Speedup = 0;//Biến sử dụng để thay đổi tốc độ xe
int MOVE;//Biến Xác định hướng di chuyển
int Speed = 1;//Level Game
bool STATE;
int check = 1;
int score = 0;
string NAME;
POINT A = { 0,0 };
POINT B = { 1,0 };


void ResetData()
{
	A = { 1,0 };
	B = { 0,0 };
	NAME = "\0";
	MOVE = 'D';
	Speed = 1;
	check = 1;
	Y = { BoardX + 5,BoardY + BoardHeight - 4 };
	if (X == NULL)
	{
		X = new POINT[Max_Car];
	}
	int line = BoardY + line1;
	X[0].x = BoardX + 5;
	X[0].y = line;
	X[1].x = BoardX + BoardWidth - 15 - 10;
	X[1].y = line + 5;
	X[2].x = BoardX + 2 * Max_CarLength-7;
	X[2].y = line + 5 +5;
	X[3].x= BoardX + 8;
	X[3].y = line+15;
	X[4].x = BoardX + BoardWidth - 15 - 10;
	X[4].y = line + 20;
	score = 0;
}

void InputName()
{
	system("cls");
	HienTroChuot();
	for (int i = 0; i < 40; i++)
	{
		GotoXY(65 + i, 19); cout << char(220);
	}
	for (int i = 0; i < 40; i++)
	{
		GotoXY(65 + i, 21); cout << char(220);
	}
	GotoXY(65, 20); cout << "ENTER YOUR NAME: "; getline(cin, NAME);
	AnTroChuot();
}

void GabageCollect()
{
	if (X != NULL)
	{
		delete[]X;
		X = NULL;
	}

}

void StartGame()
{
	system("cls");
	ResetData();
	InputName();
	DrawBoard(BoardX, BoardY, BoardHeight, BoardWidth);
	DrawScoreBoard(BoardX + BoardWidth + 6, BoardY,40,20 );
	GotoXY(ScoreX, ScoreY - 3); cout << "YOUR NAME: " << NAME;
	STATE = true;
}

//Hàm Thoát Game
void ExitGame()
{
	system("cls");
	GabageCollect();
	exit(0);
}


void PauseGame(HANDLE t)
{
	SuspendThread(t);
}

void ProcessDead()
{
	STATE = 0;
	BeforeDead();
	system("cls");
	Dead();
	SetColor(Cyan);
	GotoXY(74, 36); cout << "PRESS Y TO PLAY AGAIN";
	GotoXY(74, 37); cout << "PRESS ENTER TO EXIT";
	if (score == 0)
		D0(70, 30);
	if (score == 100)
		D100(70,30);
	if (score == 200)
		D200(70,30);
	if (score == 300)
		D300(70,30);
}

void ProcessFinish(POINT& p) 
{
	Speed == Max_Speed ? Speed = 1 : Speed=Speed-100;
	p = { BoardX+5,BoardY+BoardHeight-4 };
	MOVE = 'D'; 
	check++;
	score += 100;
		
}

void Win() {
	system("cls");
	STATE = 0;
	PlaySound(TEXT("Win.wav"), NULL, SND_ASYNC);
	for (int j = 0; j < 2; j++)
	{
		for (int i = 9; i < 12; i++)
		{
			GotoXY(40, 15);  SetColor(i); cout << "   :::    :::    ::::::::      :::     :::     :::       :::  ::::::::::   :::::      :::";
			GotoXY(40, 16); SetColor(i); cout << "  :+:    :+:   :+:      :+:   :+:     :+:     :+:       :+:     :+:       :+:+:      :+: ";
			GotoXY(40, 17); SetColor(i); cout << "  +:+  +:+    +:+      +:+   +:+     +:+     +:+       +:+     +:+       :+:+:+    +:+   ";
			GotoXY(40, 18); SetColor(i); cout << "  +#++:      +#+      +:+   +#+     +:+     +#+  +:+  +#+     +#+       +#+  +:+  +#+    ";
			GotoXY(40, 19); SetColor(i); cout << "  +#+       +#+      +#+   +#+     +#+     +#+ +#+#+ +#+     +#+      +#+    +#+ #+#     ";
			GotoXY(40, 20); SetColor(i); cout << " #+#       #+#      #+#   #+#     #+#      #+#+# #+#+#      #+#      #+#     #+#+#       ";
			GotoXY(40, 21); SetColor(i); cout << "###         ########       ########         ###   ###   ########### ###      ####        ";
			Sleep(200);
		}
	}
	D300(70, 30);
	GotoXY(74, 36); cout << "PRESS Y TO PLAY AGAIN";
	GotoXY(74, 37); cout << "PRESS ENTER TO EXIT";
}

bool IsImpact(const POINT& p,int d)
{

	if ( d == BoardY + BoardHeight - 4) return false;
	for (int i = 0; i < Max_Car; i++)
	{
		if ((p.x == X[i].x || p.x == X[i].x + Max_CarLength-1 || p.x > X[i].x && p.x < X[i].x + Max_CarLength-1)&& (p.y==X[i].y)) return true;
	}
	if (p.x== A.x && p.y==A.y )
		return true;
	if (p.x == B.x && p.y == B.y)
		return true;
	return false;
}


void MoveCars() 
{
	for (int i = 1; i < Max_Car; i += 2)
		{
		Speedup = 0;
		do {
			Speedup++;
			if (X[i].x == BoardX + BoardWidth - Max_CarLength - 5)
			{
				EraseCarLast(BoardX + BoardWidth -2*Max_CarLength-5 , X[i].y);
				X[i].x = BoardX + 5;
			}
			else
				X[i].x++;
				// Kiểm tra xem xe có đụng màn hình khong
		} while (Speedup < Speed);
	}
	for (int i = 0; i < Max_Car; i += 2)
	{
		Speedup = 0;
		do {
			Speedup++;
			if(X[i].x == BoardX+4) 
			{
				EraseCarFrist(BoardX+4,X[i].y);
				X[i].x = BoardX + BoardWidth - Max_CarLength - 5;
			}
			else
				X[i].x--;
		} while (Speedup < Speed);
	}

}




void MoveRight()
{
	
	if (Y.x > (BoardX + 1)&& Y.x < (BoardX + BoardWidth - 1))
	{
		EraseSticker(Y.x, Y.y);
		Y.x = Y.x + 6;
		DrawSticker(Y);
	}
}

void MoveLeft()
{
	
	if (Y.x > (BoardX + 1) && Y.x < (BoardX + BoardWidth - 1))
	{
		EraseSticker(Y.x, Y.y);
		Y.x = Y.x - 6;
		DrawSticker(Y);
	}
}

void MoveDown()
{
	
	if (Y.y > (BoardY + 1) && Y.y < (BoardY + BoardHeight - 3))
	{
		EraseSticker(Y.x, Y.y);
		Y.y = Y.y + 5;
		DrawSticker(Y);
	}
}

void MoveUp()
{
	
	if (Y.y > (BoardY + 1) && Y.y < (BoardY + BoardHeight - 3))
	{
		EraseSticker(Y.x, Y.y);
		Y.y = Y.y - 5;
		DrawSticker(Y);
	}
}

void SubThread()
{
	while (1)
	{
		if (STATE) //Nếu người vẫn còn sống
		{
			switch (MOVE) //Kiểm tra biến moving
			{
			case 'A':
				MoveLeft();
				break;
			case 'D':
				MoveRight();
				break;
			case 'W':
				MoveUp();
				break;
			case 'S':
				MoveDown();
				break;

			}
			MOVE = ' ';// Tạm khóa không cho di chuyển, chờ nhận phím từ hàm main
		}
		int l = 0;
		int c = 0;
		for (int i = 1; i < Max_Car; i += 2)
		{
			EraseCarFrist(X[i].x - 4, X[i].y);
			MoveCars();
			DrawCar(X[i].x, X[i].y);
		}
		for (int i = 0; i < Max_Car; i += 2)
		{
			EraseCarLast(X[i].x - 10, X[i].y);
			MoveCars();
			DrawCar(X[i].x, X[i].y);
		}
		if (score == 0)
		{
			D0(ScoreX, ScoreY);
		}
		if (IsImpact(Y, Y.y))
		{
			ProcessDead(); // Chet
			break;
		}

		if (Y.y > BoardY && Y.y < BoardY + line1)
		{
			if (check == 1)
			{
				A = Y;
			}
			if (check == 2)
				B = Y;
			if (check != 3)
			{
				ProcessFinish(Y);
			}
			else
			{
				Win();
				break;
			}
		}
		
		if (check == 1)
		{
			Sleep(Level1);
		}
		else if (check == 2)
		{
			Sleep(Level2);
		}
		else if (check == 3)
		{
			Sleep(Level3);
		}
		if (score == 100)
			D100(ScoreX, ScoreY);
		else if (score == 200)
			D200(ScoreX, ScoreY);
		else if (score == 300)
			D300(ScoreX, ScoreY);
	}
}

void About()
{
	system("cls");
	SetColor(LightGreen);
	GotoXY(15, 6);   cout << "           OOO  OOOO       OOOO       OOOO       OOOO    ";
	GotoXY(15, 7);   cout << "   OOOO     OOOO OOOO O   O OOO  O   O OOOO O   O OOOO O ";
	GotoXY(15, 8);   cout << "  O OOO  O   OO   OOOO   O   OOOO   OO  OOOO   OO  OOOO  ";
	GotoXY(15, 9);   cout << " O   OOOO    OO         OO    OO   OOOO       OOOO       ";
	GotoXY(15, 10);  cout << "OO           OO         OO    OO     OOO        OOO     ";
	GotoXY(15, 11);  cout << "OO           OO         OO    OO       OOO        OOO    ";
	GotoXY(15, 12);  cout << "OO           OO         OO    OO         OOO        OOO  ";
	GotoXY(15, 13);  cout << "OO           OO         OO    OO    OOOO OOO   OOOO  OO  ";
	GotoXY(15, 14);  cout << "OOO     O    OOO         OOOOOO    O OOOO O   O OOOO O   ";
	GotoXY(15, 15);  cout << " OOOOOOO      OOO         OOOO        OOOO       OOOO    ";
	GotoXY(15, 16);  cout << "  OOOOO                                                  ";
	SetColor(LightBlue);
	GotoXY(77, 6);   cout << "             O                                                            OO     ";
	GotoXY(77, 7);   cout << "     O     OO                                                              OO    ";
	GotoXY(77, 8);   cout << "    OO     OO                                                              OO    ";
	GotoXY(77, 9);   cout << "    OO     OO                                                              OO    ";
	GotoXY(77, 10);  cout << "  OOOOOOOO OO                     OOO  OOOO       OOOO                     OO    ";
	GotoXY(77, 11);  cout << " OOOOOOOO  OO  OOO      OOO        OOOO OOOO O   O OOO  O    OOOO      OOO OO    ";
	GotoXY(77, 12);  cout << "    OO     OO O OOO    O OOO        OO   OOOO   OO  OOOO    O OOO  O  OOOOOOOOO  ";
	GotoXY(77, 13);  cout << "    OO     OOO   OOO  O   OOO       OO         OO    OO    O   OOOO  OO   OOOO   ";
	GotoXY(77, 14);  cout << "    OO     OO     OO OO    OOO      OO         OO    OO   OO    OO   OO    OO    ";
	GotoXY(77, 15);  cout << "    OO     OO     OO OOOOOOOO       OO         OO    OO   OO    OO   OO    OO    ";
	GotoXY(77, 16);  cout << "    OO     OO     OO OOOOOOO        OO         OO    OO   OO    OO   OO    OO    ";
	GotoXY(77, 17);  cout << "    OO     OO     OO OO             OO         OO    OO   OO    OO   OO    OO    ";
	GotoXY(77, 18);  cout << "    OO     OO     OO OOOO    O      OOO         OOOOOO    OO    OO   OO    OO    ";
	GotoXY(77, 19);  cout << "     OO    OO     OO  OOOOOOO        OOO         OOOO      OOOOO OO   OOOOO      ";
	GotoXY(77, 20); ; cout << "            OO    OO   OOOOO                                OOO   OO   OOO       ";

	//Gioi thieu
	SetColor(Red);
	GotoXY(70, 25); cout << "GROUP 1 - K19HCMUS";
	GotoXY(70, 26); cout << "GROUP MEMBERS:";
	GotoXY(70, 27); cout << "TRUONG MINH NHUT - 19127237.";
	GotoXY(70, 28); cout << "NGUYEN HOAN HOAI TAM - 19127544.";
	GotoXY(70, 29); cout << "TRAN HOANG PHUONG THY -19127572.";
	GotoXY(70, 31); cout << "SUBJECT TEACHER: TRUONG TOAN THINH.";
	SetColor(White);
	GotoXY(70, 35); cout << "R -> RETURN TO MAIN MENU.";
	
}


void ScreenStartGame()
{
	//fullscreen();
	removeScrollBar();
	AnTroChuot();
	Begin();
	int temp,temp1,temp2;
	srand(time(NULL));
	temp1 = toupper(_getch());
	if (temp1 == 'T')
	{
		ResetData();
		LoadLoad();
		STATE = true;
	}
	else if (temp1 == 'A')
	{
		About();
		system("Pause");
		ScreenStartGame();
	}
	else if(temp1=='S')
	{
		StartGame();
	}
	else if(temp1=='E')
	{

		ResetData();
		ExitGame();
	}
	thread t1(SubThread);
	while (1)
	{
		temp = toupper(_getch());
		if (STATE == 1)
		{
			if (temp == 'P')
			{
				PauseGame(t1.native_handle());
			}
			else if (temp == 'L')
			{
				PauseGame(t1.native_handle());
				Save();
				ScreenStartGame();
			}
			else
			{
				ResumeThread((HANDLE)t1.native_handle());
				if (temp == 'D' || temp == 'A' || temp == 'W' || temp == 'S')
				{
					MOVE = temp;
				}
			}
		}
		else
		{
			if (temp == 'Y')
			{
				ScreenStartGame();
			}
			else
			{
				ExitGame();
				return;
			}
		}
	}
}

void Save()
{
		string data;
		ofstream f1;
		ofstream f2;
		SetColor(Cyan);
		system("cls");
		for (int i = 0; i < 40; i++)
		{
			GotoXY(65 + i, 19); cout << char(220);
		}
		for (int i = 0; i < 40; i++)
		{
			GotoXY(65 + i, 21); cout << char(220);
		}
		GotoXY(65, 20); cout << "ENTER FLIE NAME: "; getline(cin, data);
		system("cls");
		GotoXY(65, 20);
		cout << " SAVE COMPLETE.";
		f1.open(data, ios::out);
		f2.open("Name.txt", ios::app);
		f2 << data << " " << endl;
		//thong tin
		f1 << NAME<<endl;
		f1 << Y.x << " " << Y.y << endl;
		for (int i = 0; i < Max_Car; i++)
			f1 << X[i].x << " ";
		f1 << endl;
		for (int i = 0; i < Max_Car; i++)
			f1 << X[i].y << " ";
		f1 << endl;
		f1 << STATE;
		f1 << endl;
		f1 << score;
		f1 << endl;
		f1 << check;
		f1 << endl;
		f1.close();
		f2.close();

}

void LoadGame(string data)
{
	ifstream f;
	f.open(data, ios::in);
	if (!f) {
		GotoXY(35, 46);
		cout << "\n FILE KHONG TON TAI!" << endl;
	}
	else
	{
		f >> NAME;
		f >> Y.x >> Y.y;
		for (int i = 0; i < Max_Car; i++)
			f >> X[i].x;
		for (int i = 0; i < Max_Car; i++)
			f >> X[i].y;
		f >> STATE;
		f >> score;
		f >> check;
	}
	f.close();
}

void ReadNameFile()
{
	SetColor(Cyan);
	GotoXY(60, 18);
	cout << "LIST FILE NAME";
	int i = 19;
	ifstream f;
	f.open("Name.txt", ios::in);
	while (!f.eof())
	{
		char s[30];
		f >> s;
		GotoXY(50, i);
		cout << s;
		i++;
	}
	f.close();
}

void LoadLoad()
{
	int n = 100;
	system("cls");
	ReadNameFile();
	char data[30];
	GotoXY(50, 32);
	HienTroChuot();
	cout << "ENTER FILE NAME: ";
	cin.getline(data, 30);
	LoadGame(data);
	DrawBoard(BoardX, BoardY, BoardHeight, BoardWidth);
	DrawScoreBoard(BoardX + BoardWidth + 6, BoardY, 40, 20);
	GotoXY(ScoreX, ScoreY - 3); cout << "YOUR NAME: " << NAME;
}
