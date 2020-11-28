#include <Siv3D.hpp>
#include "Title.h"

Rect Title::StartButtom()
{
	// �X�^�[�g�{�^������ʂ̒����ɔz�u
	_startbuttom = Rect(Arg::center =
		Scene::Center().movedBy(0, 0), 300, 60);
	// Transition�֐����g���ό`(?)
	_startbuttomTrance = Transition(0.4s, 0.2s);
}

Rect Title::ExitButtom()
{
	// Exit�{�^������ʂ̒����z�u
	_exitbuttom = Rect(Arg::center =
		Scene::Center().movedBy(0, 100), 300, 60);
	// Transition�֐����g���ό`(?)
	 _exitbuttomTrasnce = Transition(0.4s, 0.2s);
}

/// <summary>
/// �^�C�g����ʂ̓�������
/// </summary>
void Title::Update()
{
	// startbuttonTrance�ϐ���update�֐����g��
	// �}�E�X�I�[�o�[���̏������t���[���擾
	_startbuttomTrance.update(_startbuttom.mouseOver());
	_exitbuttomTrasnce.update(_exitbuttom.mouseOver());

	// �X�^�[�g�{�^�� or Exit�{�^���Ƀ}�E�X���d�˂�ꂽ��
	if (_startbuttom.mouseOver() || _exitbuttom.mouseOver())
	{
		// �J�[�\���̌`����̌`�ɕύX
		Cursor::RequestStyle(CursorStyle::Hand);
	}

	// �X�^�[�g�{�^�������N���b�N���ꂽ��
	if (_startbuttom.leftClicked())
	{
		// �Q�[���V�[������
	}

	if (_exitbuttom.leftClicked())
	{
		// �Q�[�����I��
		System::Exit();
	}
}

void Title::Draw()
{

}
