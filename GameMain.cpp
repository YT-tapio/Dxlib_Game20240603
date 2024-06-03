/*

*/

#include"GameData.h"
#include"GameFunction.h"

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
    //---------------------------//
    // ��{�ݒ�
    //---------------------------//
    ChangeWindowMode(TRUE);//Windows�̉�ʂ��A�N�e�B�u�ɂ���
    DxLib_Init();//DxLib�̏�����
    SetMainWindowText("�^�C�~���O�Q�[��");
    SetDrawScreen(DX_SCREEN_BACK);//��ʂ̔w�i�͍�
    SetGraphMode(SCREEN_X, SCREEN_Y, 32);//��ʂ̑傫��

    //�~�̑傫���̎w��
    Circle.posX = CIRCLE_POS_X;
    Circle.posY = CIRCLE_POS_Y;
    Circle.radius = CIRCLE_RADIUS_START;

    //�摜�n���h���ϐ�
    int startScreenImage;
    //�摜���������ɒǉ�
    startScreenImage = LoadGraph("image/tittle01.png");

    //DxLib�̏���������
    if (DxLib_Init() == -1)
    {
        //�G���[���N�����璼���ɏI��
        return -1;
    }

    //�t���[���J�E���g�̏�����
    nowCout = prevCount = GetNowCount();
    //--------------------//
    // �Q�[�����[�v
    //--------------------//

    while (ProcessMessage() == 0 && CheckHitKey(KEY_INPUT_ESCAPE) == 0 && ClearDrawScreen() == 0)
    {
        //���Ԃ��Ǘ�
        nowCout = GetNowCount();

        //�f���^�^�C������
        double deltaTime = (nowCout - prevCount) / 1000.0f;

        //�G���^�[�L�[�������ꂽ�����L������
        enterPressedLastFrame = CheckHitKey(KEY_INPUT_RETURN);

        //�G���^�[�L�[�������ꂽ�񐔂ŕύX����
        //0��(�X�^�[�g��ʂ̕\��)
        if (!gameStartFlag && !gameEndFlag)
        {
            //�X�^�[�g��ʊ֐����Ăяo��
            StartScreen(deltaTime,startScreenImage);
        }
        //1�񂩂�3��(�Q�[�����)
        else if(gameStartFlag && !gameEndFlag)
        {
            //�Q�[����ʊ֐����Ăяo��
            GameProcessing(deltaTime);
        }
        //3��ȍ~(���U���g���)
        else if (gameEndFlag)
        {
            ResultScreen();
        }

        //���������t���[���̎���
        prevCount = nowCout;

    }

    //Dxlib�I������
    DxLib_End();

    return 0;
}