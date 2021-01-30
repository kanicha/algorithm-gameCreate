// Sakamaki Daiki
#pragma once
#include "SceneMgr.h"

class Title : public MovedScene::Scene
{
private:
	/* �e�{�^������ */
	// �X�^�[�g�{�^������
	Rect _startbuttom = 
		// �X�^�[�g�{�^������ʂ̒����ɔz�u
		_startbuttom = Rect(Arg::center =
		Scene::Center().movedBy(0, 0), 300, 60);
	// Transition�֐����g���ό`(?)
	Transition _startbuttomTrance = Transition(0.4s, 0.2s);

	// Exit�{�^������
	Rect _exitbuttom = 
		// Exit�{�^������ʂ̒����z�u
		_exitbuttom = Rect(Arg::center =
		Scene::Center().movedBy(0, 100), 300, 60);
	// Transition�֐����g���ό`
	Transition _exitbuttomTrance = Transition(0.4s, 0.2s);

public:
	// �R���X�g���N�^���g�p���V�[�����ڗp������
	Title(const InitData& init);
	// �^�C�g���A�b�v�f�[�g�֐�(1f�Ăяo��)
	void update() override;
	// �^�C�g���`��֐�
	void draw() const override;
};