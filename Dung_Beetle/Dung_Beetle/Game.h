#pragma once
#include "SceneMgr.h"

class Game : public MovedScene::Scene
{
	// ����
	// Game�V�[���쐬
private:

public:
	// �R���X�g���N�^���g�p���V�[�����ڗp������
	Game(const InitData& init);
	// �^�C�g���A�b�v�f�[�g�֐�(1f�Ăяo��)
	void update() override;
	// �^�C�g���`��֐�
	void draw() const override;
};

