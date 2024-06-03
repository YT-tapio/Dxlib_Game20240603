#include "DxLib.h"//Dx���C�u�����[���C���N���[�h�i�ǂݍ��݁j

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
	//�����̏����l
	int stringX = 0, stringY = 0;
	int stringX2 = 0, stringY2 = 55;
	int StringColor2 = GetColor(255, 0, 0);
	//�����̐F�w��
	int StringColor = GetColor(255, 255, 255);
	//�}�E�X�̏����l
	int mouseX = 0, mouseY = 0;
	
	//�Q�[�����[�v
	while (ProcessMessage() == 0 && CheckHitKey(KEY_INPUT_ESCAPE) == 0)
	{

		//��ʂ̏�����
		ClearDrawScreen();
		//�����̑傫���̕\��
		SetFontSize(64);
		//��ʂɕ����\��
		//DrawString(10, 25, "Hello World!!", StringColor);
		//DrawFormatString(stringX, stringY, StringColor, "X:%d Y:%d", circleX, circleY);
		//��ʂɉ~��`�悳����
		DrawCircle(circleX, circleY, 30, GetColor(0, 0, 255), TRUE);

		GetMousePoint(&mouseX, &mouseY);
		DrawFormatString(stringX, stringY, StringColor, "X:%d Y:%d", mouseX, mouseY);
		//�~��X���W�ɓ���������
		//circle += 2
		//����ʂ̓��e��\��ʂɔ��f������
		//circleX = mouseX;
		//circleY = mouseY;
		//�����}�E�X���N���b�N���ꂽ��
		if ((GetMouseInput() & MOUSE_INPUT_LEFT))
		{
			SetFontSize(30);
			DrawString(stringX2, stringY2, "Hit!", StringColor2);
		}
		if (CheckHitKey(KEY_INPUT_UP))//�����
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
		if (CheckHitKey(KEY_INPUT_DOWN))//������
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
		if (CheckHitKey(KEY_INPUT_LEFT))//������
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
		if (CheckHitKey(KEY_INPUT_RIGHT))//�E����
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
		if (CheckHitKey(KEY_INPUT_SPACE))//�X�y�[�X����
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