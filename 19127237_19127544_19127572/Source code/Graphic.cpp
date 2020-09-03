#include"Graphic.h"







void Begin() {
	system("cls");
	PlaySound(TEXT("Begin.wav"), NULL, SND_ASYNC);
	SetColor(7);
	for (int j = 0; j < 2; j++)
	{
		for (int i = 9; i < 13; i++)
		{
			GotoXY(15, 6); SetColor(i);  cout << "           OOO  OOOO       OOOO       OOOO       OOOO    ";
			GotoXY(15, 7); SetColor(i);  cout << "   OOOO     OOOO OOOO O   O OOO  O   O OOOO O   O OOOO O ";
			GotoXY(15, 8); SetColor(i);  cout << "  O OOO  O   OO   OOOO   O   OOOO   OO  OOOO   OO  OOOO  ";
			GotoXY(15, 9); SetColor(i);  cout << " O   OOOO    OO         OO    OO   OOOO       OOOO       ";
			GotoXY(15, 10); SetColor(i); cout << "OO           OO         OO    OO     OOO        OOO     ";
			GotoXY(15, 11); SetColor(i); cout << "OO           OO         OO    OO       OOO        OOO    ";
			GotoXY(15, 12); SetColor(i); cout << "OO           OO         OO    OO         OOO        OOO  ";
			GotoXY(15, 13); SetColor(i); cout << "OO           OO         OO    OO    OOOO OOO   OOOO  OO  ";
			GotoXY(15, 14); SetColor(i); cout << "OOO     O    OOO         OOOOOO    O OOOO O   O OOOO O   ";
			GotoXY(15, 15); SetColor(i); cout << " OOOOOOO      OOO         OOOO        OOOO       OOOO    ";
			GotoXY(15, 16); SetColor(i); cout << "  OOOOO                                                  ";

			GotoXY(77, 6); SetColor(i);  cout << "             O                                                            OO     ";
			GotoXY(77, 7); SetColor(i);  cout << "     O     OO                                                              OO    ";
			GotoXY(77, 8); SetColor(i);  cout << "    OO     OO                                                              OO    ";
			GotoXY(77, 9); SetColor(i);  cout << "    OO     OO                                                              OO    ";
			GotoXY(77, 10); SetColor(i); cout << "  OOOOOOOO OO                     OOO  OOOO       OOOO                     OO    ";
			GotoXY(77, 11); SetColor(i); cout << " OOOOOOOO  OO  OOO      OOO        OOOO OOOO O   O OOO  O    OOOO      OOO OO    ";
			GotoXY(77, 12); SetColor(i); cout << "    OO     OO O OOO    O OOO        OO   OOOO   OO  OOOO    O OOO  O  OOOOOOOOO  ";
			GotoXY(77, 13); SetColor(i); cout << "    OO     OOO   OOO  O   OOO       OO         OO    OO    O   OOOO  OO   OOOO   ";
			GotoXY(77, 14); SetColor(i); cout << "    OO     OO     OO OO    OOO      OO         OO    OO   OO    OO   OO    OO    ";
			GotoXY(77, 15); SetColor(i); cout << "    OO     OO     OO OOOOOOOO       OO         OO    OO   OO    OO   OO    OO    ";
			GotoXY(77, 16); SetColor(i); cout << "    OO     OO     OO OOOOOOO        OO         OO    OO   OO    OO   OO    OO    ";
			GotoXY(77, 17); SetColor(i); cout << "    OO     OO     OO OO             OO         OO    OO   OO    OO   OO    OO    ";
			GotoXY(77, 18); SetColor(i); cout << "    OO     OO     OO OOOO    O      OOO         OOOOOO    OO    OO   OO    OO    ";
			GotoXY(77, 19); SetColor(i); cout << "     OO    OO     OO  OOOOOOO        OOO         OOOO      OOOOO OO   OOOOO      ";
			GotoXY(77, 20); SetColor(i); cout << "            OO    OO   OOOOO                                OOO   OO   OOO       ";
			GotoXY(70, 24); SetColor(i - 2);
			cout << "-WELCOME TO CROSS THE ROAD-";
			GotoXY(74, 26); SetColor(i - 2);
			cout << "Press S to PLAY. ";
			GotoXY(74, 27); SetColor(i - 2);
			cout << "Press T to LOAD GAME. ";
			GotoXY(74, 28); SetColor(i-2);
			cout << "Press A to ABOUT. ";
			GotoXY(74, 29); SetColor(i - 2);
			cout << "Press E TO EXIT GAME. ";
			Sleep(100);
		}SetColor(LightGreen);
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
		GotoXY(70, 24); SetColor(Red);
		cout << "-WELCOME TO CROSS THE ROAD-";
		SetColor(White);
		GotoXY(74, 26); 
		cout << "Press S To PLAY. ";
		GotoXY(74, 27); 
		cout << "Press T to LOAD GAME. ";
		GotoXY(74, 28); 
		cout << "Press A to ABOUT. ";
		GotoXY(74, 29); 
		cout << "Press E to EXIT GAME. ";
		SetColor(White);
	}
}
		

void Dead() {
	PlaySound(TEXT("Lose.wav"), NULL, SND_ASYNC);
	for (int j = 0; j < 2; j++)
	{
		for (int i = 9; i < 12; i++)
		{
			GotoXY(40, 15);  SetColor(i); cout << "   :::    :::    ::::::::      :::     :::        :::::::::  ::::::::::     :::     ::::::::: ";
			GotoXY(40, 16); SetColor(i); cout << "  :+:    :+:   :+:      :+:   :+:     :+:        :+:    :+: :+:          :+: :+:   :+:    :+: ";
			GotoXY(40, 17); SetColor(i); cout << "  +:+  +:+    +:+      +:+   +:+     +:+        +:+    +:+ +:+         +:+   +:+  +:+    +:+  ";
			GotoXY(40, 18); SetColor(i); cout << "  +#++:      +#+      +:+   +#+     +:+        +#+    +:+ +#++:++#   +#++:++#++: +#+    +:+   ";
			GotoXY(40, 19); SetColor(i); cout << "  +#+       +#+      +#+   +#+     +#+        +#+    +#+ +#+        +#+     +#+ +#+    +#+    ";
			GotoXY(40, 20); SetColor(i); cout << " #+#       #+#      #+#   #+#     #+#        #+#    #+# #+#        #+#     #+# #+#    #+#     ";
			GotoXY(40, 21); SetColor(i); cout << "###         ########       ########         #########  ########## ###     ### #########       ";
			Sleep(100);
		}
	}
	
}

void BeforeDead()
{
	system("cls");
	PlaySound(TEXT("Ambulance.wav"), NULL, SND_ASYNC);
	SetColor(White);
	Sticker(65, 20);
	SetColor(Red);
	int n=0;
	while (n != 1)
	{
		for (int i = 1; i <= 70; i++)
		{
			DrawAmbulance(i, 16);
			EraseAmbulance(i - 1, 16);
			Sleep(100);
			if (i == 70) n = 1;
		}
	}
}

 