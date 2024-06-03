#include"DxLib.h"
#define _USE_MATH_DEFINES
#include<math.h>
#include<stdio.h>

//定数
#define CIRCLE_POS_X 400
#define CIRCLE_POS_Y 300
#define CIRCLE_RADIUS_START 10
#define CIRCLE_RADIUS_MAX 200


//変数
typedef struct circle
{
    int posX;
    int posY;
    int radius;
    double area;
}circle;

//ゲームフラグ
bool enterPreasedLastFrame = false;      //エンターキーが押されたかどうかのフラグ
bool gameStartFlog = false;              //ゲーム開始フラグ
bool circleGenerationFlag = true;        //円の生成フラグ
bool gameEndFlag = true;                 //ゲーム終了フラグ


//ゲームカウント
int enterPressCount;
//構造体を変数にする
circle Circle;
//円の最大面積
double circleAreaMax = M_PI * CIRCLE_RADIUS_MAX * CIRCLE_RADIUS_MAX;


//メイン関数
int WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{

    ChangeWindowMode(TRUE);
    DxLib_Init();
    SetDrawScreen(DX_SCREEN_BACK);
    SetGraphMode(800, 600, 32);
    
    if (DxLib_Init() == -1)
    {
        //エラーが起きたら直ちに終了
        return -1;
    }

    //
    Circle.posX = CIRCLE_POS_X;
    Circle.posY = CIRCLE_POS_Y;
    Circle.radius = CIRCLE_RADIUS_START;

    //円の初期位置
    Circle.posX = 320;
    Circle.posY = 240;

    //ゲームスタート


        //ゲームループ
        while (ProcessMessage() == 0 && CheckHitKey(KEY_INPUT_ESCAPE) == 0)
        {


            if (CheckHitKey(KEY_INPUT_RETURN))
            {
                gameStartFlog = !gameStartFlog;
            }

            enterPreasedLastFrame = CheckHitKey(KEY_INPUT_RETURN);

            if (Check)
            {

            }

            if (gameStartFlog)
            {

                if (CheckHitKey(KEY_INPUT_RETURN))
                {
                    gameStartFlog = gameStartFlog;
                }
                //画面の初期化
                ClearDrawScreen();


                //画面に円を描画させる
                DrawCircle(Circle.posX, Circle.posY, Circle.radius, GetColor(0, 0, 255), TRUE);

                if (circleGenerationFlag == false)
                {
                    Circle.radius -= 3;
                    if (Circle.radius <= 10)
                    {
                        circleGenerationFlag = !circleGenerationFlag;
                    }
                }
                else
                {
                    Circle.radius += 3;
                    if (Circle.radius >= 200)
                    {
                        circleGenerationFlag = !circleGenerationFlag;
                    }
                }
            }



            Circle.area = Circle.radius * Circle.radius * 3.14;

            ScreenFlip();
        }
       

    //-----------------------------------------------------------------------------------------------------------------------------------------------------------------//

    //-------------------//
    //基本設定
    //-------------------//
    /*ChangeWindowMode(TRUE);
    DxLib_Init();
    SetDrawScreen(DX_SCREEN_BACK);
    SetGraphMode(800, 600, 32);

    if (DxLib_Init() == -1)
    {
        //エラーが起きたら直ちに終了
        return -1;
    }

    int CircleColor = GetColor(128, 128, 128);
    //円の描画
    Circle.posX = CIRCLE_POS_X;
    Circle.posY = CIRCLE_POS_Y;
    Circle.radius = CIRCLE_RADIUS_START;

    //-------------------//
    //ゲームループ
    //-------------------//

    while (ProcessMessage() == 0 && CheckHitKey(KEY_INPUT_ESCAPE) == 0 && ClearDrawScreen() == 0)
    {
        //
        ClearDrawScreen();


        if (CheckHitKey(KEY_INPUT_RETURN) && !enterPreasedLastFrame)
        {
            gameStartFlog = !gameStartFlog;
        }
        //
        enterPreasedLastFrame = CheckHitKey(KEY_INPUT_RETURN);

        //円の変化をつける
        if (gameStartFlog)
        {
            //大きくする
            if (circleGenerationFlag)
            {
                //半径を5ずつ増やす
                Circle.radius += 5;
            }
        }

        //円の描画
        DrawCircle(Circle.posX,Circle.posY,Circle.radius,CircleColor);


        //
        ScreenFlip();

    }
    */
    //
    DxLib_End();

    return 0;
}
