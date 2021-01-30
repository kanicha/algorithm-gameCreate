#pragma once
#include "SceneMgr.h"

class Game : public MovedScene::Scene
{
	// ����
	// ���ԂŃX�R�A�����A�W�����v�����A�G�����_���o�����炢
private:
	// bool�^�ł����l�̕ύX���\��mutable Texture�^��錾
	mutable Texture playerImage;
	mutable Texture enemyImage;
	mutable Texture backGroundImage;
	// �ړ����x
	double moveSpeed;
	// �v���C���[�|�W�V����
	mutable Vec2 pos;

public:
	// �R���X�g���N�^���g�p���V�[�����ڗp������
	Game(const InitData & init);
	// �^�C�g���A�b�v�f�[�g�֐�(1f�Ăяo��)
	void update() override;
	// �^�C�g���`��֐�
	void draw() const override;
	// �v���C���[���͌n�֐�
	void PlayerInput() const;
};

