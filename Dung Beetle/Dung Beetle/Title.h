// Sakamaki Daiki
#pragma once
#include <Siv3D.hpp>
#include "SceneMgr.h"

class Title : public MovedScene::Scene
{
private:
	// �{�^���`��p�ϐ�
	Rect _startbuttom;
	Rect _exitbuttom;
	// �{�^���ό`�p�ϐ�
	Transition _startbuttomTrance;
	Transition _exitbuttomTrance;

public:
	// �V�[�����ڗp������
	Title(const InitData& init);
	// �X�^�[�g�{�^���쐬
	Rect StartButtom();
	// Exit�{�^���쐬
	Rect ExitButtom();
	// �^�C�g���A�b�v�f�[�g�֐�(1f�Ăяo��)
	void Update();
	// �^�C�g���`��֐�
	void Draw() const;
};