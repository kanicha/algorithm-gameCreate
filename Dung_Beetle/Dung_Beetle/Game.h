// Sakamaki Daiki
#pragma once
#include "SceneMgr.h"

class Game : public MovedScene::Scene
{
	// ����
	// ���ԂŃX�R�A�����A�W�����v�����A�G�����_���o�����炢
private:
	// �X�R�A�ϐ�
	mutable int gameScore;
	// �X�R�A�̘g�g��
	Rect scoreWindow;
	// �Q�[���I���N���X
	mutable bool gameEndFlag;
	// bool�^�ł����l�̕ύX���\��mutable Texture�^��錾
	mutable Texture playerImage;
	mutable Texture enemyImage;
	mutable Texture backGroundImage;
	mutable Texture blockImage;
	// �ړ����x
	mutable double moveSpeed;
	// �W�����v��
	mutable double jumpPower;
	// �v���C���[�|�W�V����
	mutable Vec2 pos;


public:
	// �R���X�g���N�^���g�p���V�[�����ڗp������
	Game(const InitData & init);
	// �^�C�g���A�b�v�f�[�g�֐�(1f�Ăяo��)
	void update() override;
	// �^�C�g���`��֐�
	void draw() const override;
	// �u���b�N�`��֐�
	void Blockdraw() const;
	// �G�l�~�[�`��֐�
	void Enemydraw() const;
	// �v���C���[���͌n�֐�
	void PlayerInput() const;
	// �Q�[���I�[�o�[�֐�
	void GameOver() const;
};

