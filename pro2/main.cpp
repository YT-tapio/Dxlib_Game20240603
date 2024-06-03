#include "DxLib.h"//Dxライブラリーをインクルード（読み込み）
#include<ctime>

using namespace std;

int WinMain(HINSTANCE, HINSTANCE, LPSTR, int)//Windowsのメインで動かす
{
	//基本設計
	ChangeWindowMode(TRUE);//Windowsの画面をアクティブにする
	DxLib_Init();//DxLibの初期化
	SetDrawScreen(DX_SCREEN_BACK);//画面の背景は黒
	SetGraphMode(800, 600, 32);//画面の大きさ
	//DxLibの初期化処理
	if (DxLib_Init() == -1)
	{
		//エラーが起きたら直ちに終了
		return -1;
	}
	//円の初期位置
	int circleX = 320;
	int circleY = 240;
	int circle2Y, circle2X;

	circle2Y = 0;
	//ゲームループ
	while (ProcessMessage() == 0 && CheckHitKey(KEY_INPUT_ESCAPE) == 0)
	{

		//画面の初期化
		ClearDrawScreen();
		//画面に円を描画させる

		srand((unsigned)time(0));
		int i;
		i = (rand() % 799) + 1;
		circle2X = i;

		DrawCircle(circleX, circleY, 30, GetColor(0, 0, 255), TRUE);
		DrawCircle(circle2X, circle2Y, 30, GetColor(0, 255, 0), TRUE);

		if (circle2Y >= 600)
		{
			circle2Y = 0;
			srand((unsigned)time(0));
			int i;
			i = (rand() % 799) + 1;
			DrawCircle(circle2X, circle2Y, 30, GetColor(0, 255, 0), TRUE);
		}
		//円のX座標に動きをつける
		circle2Y += 2;
		//裏画面の内容を表画面に反映させる
		if (CheckHitKey(KEY_INPUT_UP))//上入力
		{
			if (CheckHitKey(KEY_INPUT_RIGHT))
			{
				circleY += 2;
				circleX -= 2;
			}
			circleY -= 4;
		}
		if (CheckHitKey(KEY_INPUT_DOWN))//下入力
		{
			circleY += 4;
		}
		if (CheckHitKey(KEY_INPUT_LEFT))//左入力
		{
			circleX -= 4;
		}
		if (CheckHitKey(KEY_INPUT_RIGHT))//右入力
		{
			circleX += 4;
		}
		if(CheckHitKey(KEY_INPUT_SPACE))//スペース入力
		{
			circleX = 320;
			circleY = 240;
		}
		ScreenFlip();

	}

	//画面に点を描画させてね（X座標、Ｙ座標、点の色指定）
	DrawPixel(320, 240, GetColor(255, 0, 0));
	//Dxlib使用の終了処理
	DxLib_End();
	//ソースの終了
	return 0;
}