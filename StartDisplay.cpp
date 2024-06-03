#include"DxLib.h"
#include<math.h>
#include<stdio.h>

//変数
#define SCREEN_X 800
#define SCREEN_Y 600
#define START_STRING_X 230
#define START_STRING_Y 520

//フレームカウント
double frameCount = 0;
//デルタ時間
int prevCount, nowCount;

//画像バンドル変数
int startScreenImage;

//アルファ値
int alpha;

//メイン関数
int WINAPI WinMain(HINSTANCE hinstance, HINSTANCE hPrevlnstance, LPSTR lpCmddLine, int nCmdShow)
{
    //------------------//
    // 基本設計
    //------------------//
    ChangeWindowMode(TRUE);//Windousの画面をアクティブにする
    DxLib_Init();//DxLibの初期化
    SetMainWindowText("タイミングゲーム");
    SetDrawScreen(DX_SCREEN_BACK);//背景の画面は黒
    SetGraphMode(800, 600, 32);//画面の大きさ 

    //DxLibの初期化処理
    if (DxLib_Init() == -1)
    {
        //エラーが起きたら直ちに終了
        return -1;
    }

    //画像にメモリを追加
    startScreenImage = LoadGraph("image/tittle01.png");

    //文字の色
    int stringColor = GetColor(255, 99, 153);

    prevCount = GetNowCount();

    //-----------------//
    // ゲームループ
    //-----------------//

    while (ProcessMessage() == 0 && CheckHitKey(KEY_INPUT_ESCAPE) == 0 && ClearDrawScreen() == 0)
    {
        //時間指定
        nowCount = GetNowCount();

        //デルタタイム
        double deltaTime = (nowCount - prevCount) / 1000.0;

        //フレームカウントに追加
        frameCount += deltaTime * 80;

        //画像の描画
        DrawExtendGraph(0, 0, SCREEN_X, SCREEN_Y, startScreenImage, TRUE);
        //アルファ値を指定
        alpha = (int)(255 * (0.5 * (1 + sin(frameCount * 0.05))));

        //描画モードをブレンドモードに設定
        SetDrawBlendMode(DX_BLENDMODE_ALPHA, alpha);
        SetFontSize(30);
        DrawFormatString(START_STRING_X, START_STRING_Y, stringColor, "Press Enter to Start");
        //描画モードを戻す
        SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);


        prevCount = nowCount;

    }

    //Dxlib終了処理
    DxLib_End();

    return 0;

}