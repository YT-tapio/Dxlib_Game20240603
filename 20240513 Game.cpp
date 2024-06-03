#include"DxLib.h"
#define _USE_MATH_DEFINES
#include<math.h>
#include<stdio.h>

//�萔
#define CIRCLE_POS_X 400
#define CIRCLE_POS_Y 300
#define CIRCLE_RADIUS_START 10
#define CIRCLE_RADIUS_MAX 200


//�ϐ�
typedef struct circle
{
    int posX;
    int posY;
    int radius;
    double area;
}circle;

//�Q�[���t���O
bool enterPreasedLastFrame = false;      //�G���^�[�L�[�������ꂽ���ǂ����̃t���O
bool gameStartFlog = false;              //�Q�[���J�n�t���O
bool circleGenerationFlag = true;        //�~�̐����t���O
bool gameEndFlag = true;                 //�Q�[���I���t���O


//�Q�[���J�E���g
int enterPressCount;
//�\���̂�ϐ��ɂ���
circle Circle;
//�~�̍ő�ʐ�
double circleAreaMax = M_PI * CIRCLE_RADIUS_MAX * CIRCLE_RADIUS_MAX;


//���C���֐�
int WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{

    ChangeWindowMode(TRUE);
    DxLib_Init();
    SetDrawScreen(DX_SCREEN_BACK);
    SetGraphMode(800, 600, 32);
    
    if (DxLib_Init() == -1)
    {
        //�G���[���N�����璼���ɏI��
        return -1;
    }

    //
    Circle.posX = CIRCLE_POS_X;
    Circle.posY = CIRCLE_POS_Y;
    Circle.radius = CIRCLE_RADIUS_START;

    //�~�̏����ʒu
    Circle.posX = 320;
    Circle.posY = 240;

    //�Q�[���X�^�[�g


        //�Q�[�����[�v
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
                //��ʂ̏�����
                ClearDrawScreen();


                //��ʂɉ~��`�悳����
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
    //��{�ݒ�
    //-------------------//
    /*ChangeWindowMode(TRUE);
    DxLib_Init();
    SetDrawScreen(DX_SCREEN_BACK);
    SetGraphMode(800, 600, 32);

    if (DxLib_Init() == -1)
    {
        //�G���[���N�����璼���ɏI��
        return -1;
    }

    int CircleColor = GetColor(128, 128, 128);
    //�~�̕`��
    Circle.posX = CIRCLE_POS_X;
    Circle.posY = CIRCLE_POS_Y;
    Circle.radius = CIRCLE_RADIUS_START;

    //-------------------//
    //�Q�[�����[�v
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

        //�~�̕ω�������
        if (gameStartFlog)
        {
            //�傫������
            if (circleGenerationFlag)
            {
                //���a��5�����₷
                Circle.radius += 5;
            }
        }

        //�~�̕`��
        DrawCircle(Circle.posX,Circle.posY,Circle.radius,CircleColor);


        //
        ScreenFlip();

    }
    */
    //
    DxLib_End();

    return 0;
}
