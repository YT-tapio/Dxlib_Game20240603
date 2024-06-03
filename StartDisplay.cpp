#include"DxLib.h"
#include<math.h>
#include<stdio.h>

//�ϐ�
#define SCREEN_X 800
#define SCREEN_Y 600
#define START_STRING_X 230
#define START_STRING_Y 520

//�t���[���J�E���g
double frameCount = 0;
//�f���^����
int prevCount, nowCount;

//�摜�o���h���ϐ�
int startScreenImage;

//�A���t�@�l
int alpha;

//���C���֐�
int WINAPI WinMain(HINSTANCE hinstance, HINSTANCE hPrevlnstance, LPSTR lpCmddLine, int nCmdShow)
{
    //------------------//
    // ��{�݌v
    //------------------//
    ChangeWindowMode(TRUE);//Windous�̉�ʂ��A�N�e�B�u�ɂ���
    DxLib_Init();//DxLib�̏�����
    SetMainWindowText("�^�C�~���O�Q�[��");
    SetDrawScreen(DX_SCREEN_BACK);//�w�i�̉�ʂ͍�
    SetGraphMode(800, 600, 32);//��ʂ̑傫�� 

    //DxLib�̏���������
    if (DxLib_Init() == -1)
    {
        //�G���[���N�����璼���ɏI��
        return -1;
    }

    //�摜�Ƀ�������ǉ�
    startScreenImage = LoadGraph("image/tittle01.png");

    //�����̐F
    int stringColor = GetColor(255, 99, 153);

    prevCount = GetNowCount();

    //-----------------//
    // �Q�[�����[�v
    //-----------------//

    while (ProcessMessage() == 0 && CheckHitKey(KEY_INPUT_ESCAPE) == 0 && ClearDrawScreen() == 0)
    {
        //���Ԏw��
        nowCount = GetNowCount();

        //�f���^�^�C��
        double deltaTime = (nowCount - prevCount) / 1000.0;

        //�t���[���J�E���g�ɒǉ�
        frameCount += deltaTime * 80;

        //�摜�̕`��
        DrawExtendGraph(0, 0, SCREEN_X, SCREEN_Y, startScreenImage, TRUE);
        //�A���t�@�l���w��
        alpha = (int)(255 * (0.5 * (1 + sin(frameCount * 0.05))));

        //�`�惂�[�h���u�����h���[�h�ɐݒ�
        SetDrawBlendMode(DX_BLENDMODE_ALPHA, alpha);
        SetFontSize(30);
        DrawFormatString(START_STRING_X, START_STRING_Y, stringColor, "Press Enter to Start");
        //�`�惂�[�h��߂�
        SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);


        prevCount = nowCount;

    }

    //Dxlib�I������
    DxLib_End();

    return 0;

}