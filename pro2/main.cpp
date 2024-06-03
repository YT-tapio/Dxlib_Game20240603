#include "DxLib.h"//Dx���C�u�����[���C���N���[�h�i�ǂݍ��݁j
#include<ctime>

using namespace std;

int WinMain(HINSTANCE, HINSTANCE, LPSTR, int)//Windows�̃��C���œ�����
{
	//��{�݌v
	ChangeWindowMode(TRUE);//Windows�̉�ʂ��A�N�e�B�u�ɂ���
	DxLib_Init();//DxLib�̏�����
	SetDrawScreen(DX_SCREEN_BACK);//��ʂ̔w�i�͍�
	SetGraphMode(800, 600, 32);//��ʂ̑傫��
	//DxLib�̏���������
	if (DxLib_Init() == -1)
	{
		//�G���[���N�����璼���ɏI��
		return -1;
	}
	//�~�̏����ʒu
	int circleX = 320;
	int circleY = 240;
	int circle2Y, circle2X;

	circle2Y = 0;
	//�Q�[�����[�v
	while (ProcessMessage() == 0 && CheckHitKey(KEY_INPUT_ESCAPE) == 0)
	{

		//��ʂ̏�����
		ClearDrawScreen();
		//��ʂɉ~��`�悳����

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
		//�~��X���W�ɓ���������
		circle2Y += 2;
		//����ʂ̓��e��\��ʂɔ��f������
		if (CheckHitKey(KEY_INPUT_UP))//�����
		{
			if (CheckHitKey(KEY_INPUT_RIGHT))
			{
				circleY += 2;
				circleX -= 2;
			}
			circleY -= 4;
		}
		if (CheckHitKey(KEY_INPUT_DOWN))//������
		{
			circleY += 4;
		}
		if (CheckHitKey(KEY_INPUT_LEFT))//������
		{
			circleX -= 4;
		}
		if (CheckHitKey(KEY_INPUT_RIGHT))//�E����
		{
			circleX += 4;
		}
		if(CheckHitKey(KEY_INPUT_SPACE))//�X�y�[�X����
		{
			circleX = 320;
			circleY = 240;
		}
		ScreenFlip();

	}

	//��ʂɓ_��`�悳���ĂˁiX���W�A�x���W�A�_�̐F�w��j
	DrawPixel(320, 240, GetColor(255, 0, 0));
	//Dxlib�g�p�̏I������
	DxLib_End();
	//�\�[�X�̏I��
	return 0;
}