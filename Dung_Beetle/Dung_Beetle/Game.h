#pragma once
#include "SceneMgr.h"

class Game : public MovedScene::Scene
{
	// ����
	// Game�V�[���쐬�A�t���[�Y������
private:

public:
	// �R���X�g���N�^���g�p���V�[�����ڗp������
	Game(const InitData & init);
	// �^�C�g���A�b�v�f�[�g�֐�(1f�Ăяo��)
	void update() override;
	// �^�C�g���`��֐�
	void draw() const override;
	// �v���C���[�`��֐�
	void PlayerDraw() const;
	// �G�l�~�[�`��֐�
	void EnemyDraw() const;
};

