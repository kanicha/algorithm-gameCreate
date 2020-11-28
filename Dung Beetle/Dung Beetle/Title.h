#pragma once
#include <Siv3D.hpp>
#include "SceneMgr.h"

class Title 
{
private:
	// �{�^���`��p�ϐ�
	Rect _startbuttom;
	Rect _exitbuttom;
	// �{�^���ό`�p�ϐ�
	Transition _startbuttomTrance;
	Transition _exitbuttomTrasnce;

public:
	// �X�^�[�g�{�^���쐬
	Rect StartButtom();
	// Exit�{�^���쐬
	Rect ExitButtom();
	// �^�C�g���A�b�v�f�[�g�֐�(1f�Ăяo��)
	void Update();
	// �^�C�g���`��֐�
	void Draw();
};