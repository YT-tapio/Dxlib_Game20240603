/*
�O���[�o���ϐ��̏�����
*/

#include"GameData.h"

//�O���[�o���ϐ��̒�`
//�ϐ��̏��������s���Ă���
// �������}��
//�Q�[���t���O
bool enterPressedLastFrame = false;     //�G���^�[�L�[�������ꂽ���ǂ����̃t���O
bool gameStartFlag = false;             //�Q�[���J�n�t���O
bool circleGenerationFlag = true;       //�~�̐����t���O
bool gameEndFlag = false;                //�Q�[���I���t���O
bool enterPressAllowed = true;           //�G���^�[�L�[��������Ă��邩������

//�Q�[���J�E���g
int enterPressCount = 0;
//�\���̂�ϐ��ɂ���
circle Circle;

//�~�̍ő�ʐ�
double circleAreaMax = M_PI*CIRCLE_RADIUS_MAX*CIRCLE_RADIUS_MAX;
//�~�̖ʐϊ���
double circlePorpotion = 0.0f;

//�t���[���J�E���g
double frameCount = 0;

//�f���^����
//�J�E���g�O
int prevCount = 0;
//�J�E���g��
int nowCout = 0;

//�摜�n���h���ϐ�
int statScreenImage;
//�A���t�@�l
int alpha;