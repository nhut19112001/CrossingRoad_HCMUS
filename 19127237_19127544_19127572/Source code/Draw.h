#pragma once
#include"Common.h"
#include"Graphic.h"
#define BoardX 10
#define BoardY 5
#define BoardHeight 35
#define BoardWidth 100
#define line1 6
#define line2 11
#define line3 16
#define line4 21
#define line5 26
#define Max_Car 5
#define Max_CarLength 15
#define Max_Speed 200
#define Line 5
#define ScoreX 120
#define ScoreY 13
#define Level1 400
#define Level2 300
#define Level3 200



// RULE
void Rule();

//Vẽ vùng chơi game
void DrawBoard(int x, int y, int height, int width);

//Vẽ Xe 
void DrawCar(int x,int y);

//Xóa xe Trước
void EraseCarFrist(int x, int y);

//Xóa xe sau
void EraseCarLast(int x, int y);

//Vẽ người
void Sticker(int x, int y);

//Xóa người
void EraseSticker(int x,int y);

//IN Người ở vị trí
void DrawSticker(const POINT& p);

//Vẽ xe cứu thương
void DrawAmbulance(int x, int y);

//Xóa xe cứu thương
void EraseAmbulance(int x, int y);

//Vẽ bảng điểm
void DrawScoreBoard(int x,int y,int height,int width);

//VẼ 100 Điểm:
void D100(int x,int y);

//Vẽ 300 Điểm
void D300(int x, int y);

//Vẽ 200 Điểm
void D200(int x, int y);

void D0(int x, int y);