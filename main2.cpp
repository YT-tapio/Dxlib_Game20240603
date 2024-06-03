#include "DxLib.h"//Dxライブラリーをインクルード（読み込み）

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
	//文字の初期値
	int stringX = 0, stringY = 0;
	int stringX2 = 0, stringY2 = 55;
	int StringColor2 = GetColor(255, 0, 0);
	//文字の色指定
	int StringColor = GetColor(255, 255, 255);
	//マウスの初期値
	int mouseX = 0, mouseY = 0;
	
	//ゲームループ
	while (ProcessMessage() == 0 && CheckHitKey(KEY_INPUT_ESCAPE) == 0)
	{

		//画面の初期化
		ClearDrawScreen();
		//文字の大きさの表示
		SetFontSize(64);
		//画面に文字表示
		//DrawString(10, 25, "Hello World!!", StringColor);
		//DrawFormatString(stringX, stringY, StringColor, "X:%d Y:%d", circleX, circleY);
		//画面に円を描画させる
		DrawCircle(circleX, circleY, 30, GetColor(0, 0, 255), TRUE);

		GetMousePoint(&mouseX, &mouseY);
		DrawFormatString(stringX, stringY, StringColor, "X:%d Y:%d", mouseX, mouseY);
		//円のX座標に動きをつける
		//circle += 2
		//裏画面の内容を表画面に反映させる
		//circleX = mouseX;
		//circleY = mouseY;
		//もしマウスがクリックされたら
		if ((GetMouseInput() & MOUSE_INPUT_LEFT))
		{
			SetFontSize(30);
			DrawString(stringX2, stringY2, "Hit!", StringColor2);
		}
		if (CheckHitKey(KEY_INPUT_UP))//上入力
		{
			if (circleY <= 40)
			{
				circleY += 3;
			}
			else
			{
				circleY -= 3;
			}
		}
		if (CheckHitKey(KEY_INPUT_DOWN))//下入力
		{
			if (circleY >= 560)
			{
				circleY -= 3;
			}
			else
			{
				circleY += 3;
			}
		}
		if (CheckHitKey(KEY_INPUT_LEFT))//左入力
		{
			if (circleX <= 40)
			{
				circleX += 3;
			}
			else
			{
				circleX -= 3;
			}
		}
		if (CheckHitKey(KEY_INPUT_RIGHT))//右入力
		{
			if (circleX >= 760)
			{
				circleX -= 3;
			}
			else
			{
				circleX += 3;
			}
		}
		if (CheckHitKey(KEY_INPUT_SPACE))//スペース入力
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