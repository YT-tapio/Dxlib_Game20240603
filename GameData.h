#pragma once
/*
�f�[�^�̍\���ƃO���[�o���ϐ��錾
�錾�}��
*/
#include "DxLib.h"
#define _USE_MATH_DEFINES
#include <math.h>
#include <stdio.h>
#include <Windows.h>

//�萔
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

//�ϐ�
typedef struct circle
{
    int posX;
    int posY;
    int radius;
    double area;
}circle;

//�Q�[���t���O
extern bool enterPressedLastFrame;     //�G���^�[�L�[�������ꂽ���ǂ����̃t���O
extern bool gameStartFlag;             //�Q�[���J�n�t���O
extern bool circleGenerationFlag;       //�~�̐����t���O
extern bool gameEndFlag;                //�Q�[���I���t���O
extern bool enterPressAllowed;           //�G���^�[�L�[��������Ă��邩������

//�Q�[���J�E���g
extern int enterPressCount;
//�\���̂�ϐ��ɂ���
extern circle Circle;
//�~�̍ő�ʐ�
extern double circleAreaMax;
//�~�̖ʐϊ���
extern double circlePorpotion;

//�t���[���J�E���g
extern double frameCount;

//�f���^����
//�J�E���g�O
extern int prevCount;
//�J�E���g��
extern int nowCout;

//�摜�n���h���ϐ�
extern int startScreenTmage;

//�A���t�@�l
extern int alpha;