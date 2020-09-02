#pragma once
#include <windows.h>
#include<iostream>
#include<time.h>
#include<thread>
#include<conio.h>
#include<string>
#include<fstream>
#include<MMSystem.h>
using namespace std;
#define Black          0
#define Blue           1
#define Green          2
#define Cyan           3
#define Red            4
#define Magenta        5
#define Brown          6
#define LightGray      7
#define DarkGray       8
#define LightBlue      9
#define LightGreen    10
#define LightCyan     11
#define LightRed      12
#define Ligh Magenta  13
#define Yellow        14
#define White         15

//Hàm cố định kích cỡ khung cmd
void FixConsoleWindow();

// Hàm thay đổi kích cỡ của khung cmd với tham số truyền vào là chiều cao, chiều rộng.
void resizeConsole(int , int);

//Hàm thay đổi màu chữ
void SetColor(int);

//Hàm thay đổi màu nền 
void ClearConsoleToColors(int ForgC, int BackC);

// Hàm dịch chuyển con trỏ đến tọa độ x, y.
void GotoXY(int , int );

// Hàm xóa màn hình.
void XoaManHinh();

//Xóa cuộn chuột
void removeScrollBar();

// Hàm full màn hình
void fullscreen(); 

//ẨN trỏ chuột
void AnTroChuot(); 

//Hiện trỏ chuột
void HienTroChuot();
