#pragma once
#include"Common.h"
#include"Graphic.h"
#include"Draw.h"



//Khởi tạo lúc đầu
void ResetData();

//HÀm nhập tên
void InputName();

//HÀm dọn rác
void GabageCollect();

//Hàm mở đầu game
void StartGame();

//Hàm Thoát Game
void ExitGame();

//Hàm Tạm dừng game
void PauseGame(HANDLE t);

//Kiểm tra còn sống hay ko
void ProcessDead();

//Hàm xử lý khi chiến thắng
void ProcessFinish(POINT& p);

//Hàm chiến thắng
void Win();

//HÀm kiểm tra va chạm
bool IsImpact(const POINT& p, int d);

//Hàm kiểm tra va chạm với người
bool IsImpactP(const POINT& p);

//Hàm di chuyển xe
void MoveCars();

//ĐI qua trái
void MoveLeft();

//Đi qua phải
void MoveRight();

//Đi xuống
void MoveDown();

//Đi lên 
void MoveUp();

void SubThread();

// Gioi thieu
void About();

//Man Hinh chinh
void ScreenStartGame();

//Load game
void LoadGame(string data);

//Save
void Save();

//Đọc tên file
void ReadNameFile();

//HÀm hướng dẫn load
void LoadLoad();



