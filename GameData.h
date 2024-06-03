#pragma once
/*
データの構造とグローバル変数宣言
宣言マン
*/
#include "DxLib.h"
#define _USE_MATH_DEFINES
#include <math.h>
#include <stdio.h>
#include <Windows.h>

//定数
#define SCREEN_X 800
#define SCREEN_Y 600
#define CIRCLE_POS_X 400
#define CIRCLE_POS_Y 300
#define CIRCLE_RADIUS_START 10
#define CIRCLE_RADIUS_MAX 200
#define RESULT_STRING_X 15
#define RESULT_STRING_Y 15
#define START_STRING_X 230
#define START_STRING_Y 520

//変数
typedef struct circle
{
    int posX;
    int posY;
    int radius;
    double area;
}circle;

//ゲームフラグ
extern bool enterPressedLastFrame;     //エンターキーが押されたかどうかのフラグ
extern bool gameStartFlag;             //ゲーム開始フラグ
extern bool circleGenerationFlag;       //円の生成フラグ
extern bool gameEndFlag;                //ゲーム終了フラグ
extern bool enterPressAllowed;           //エンターキーを押されているかを許可

//ゲームカウント
extern int enterPressCount;
//構造体を変数にする
extern circle Circle;
//円の最大面積
extern double circleAreaMax;
//円の面積割合
extern double circlePorpotion;

//フレームカウント
extern double frameCount;

//デルタ時間
//カウント前
extern int prevCount;
//カウント後
extern int nowCout;

//画像ハンドル変数
extern int startScreenTmage;

//アルファ値
extern int alpha;
