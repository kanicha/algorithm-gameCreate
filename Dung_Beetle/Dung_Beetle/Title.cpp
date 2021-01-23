// Sakamaki Daiki
#include "Title.h"

/// <summary>
/// �������p�֐�
/// </summary>
/// <param name="init"></param>
Title::Title(const InitData& init)
	: IScene(init)
{

}

/// <summary>
/// �^�C�g����ʂ̓�������
/// </summary>
void Title::update()
{
	// startbuttonTrance�ϐ���update�֐����g��
	// �}�E�X�I�[�o�[���̏������t���[���擾
	_startbuttomTrance.update(_startbuttom.mouseOver());
	_exitbuttomTrance.update(_exitbuttom.mouseOver());

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
		changeScene(SceneName::Game);
	}

	// Exit�{�^�������N���b�N���ꂽ��
	if (_exitbuttom.leftClicked())
	{
		// �Q�[�����I��
		System::Exit();
	}
}

/// <summary>
/// �^�C�g���V�[���`��֐�
/// </summary>
void Title::draw() const
{

	// �^�C�g���\���p�ϐ�
	const String titleName = U"�t���R���K�V����\n\t\t����΂�";
	// �Q�[���̒��S�擾
	const Vec2 center(Scene::Center().x, 120);
	// �^�C�g���`��
	FontAsset(U"Title")(titleName).drawAt(center.movedBy(4, 6), ColorF(0.0, 0.5));
	FontAsset(U"Title")(titleName).drawAt(center);

	/*�{�^���`�揈��*/
	// �X�^�[�g�{�^���g�g�ݕ`�揈��
	_startbuttom.draw(ColorF(1.0, _startbuttomTrance.value())).drawFrame(2);
	// Exit�{�^���g�g�ݕ`�揈��
	_exitbuttom.draw(ColorF(1.0, _exitbuttomTrance.value())).drawFrame(2);
	// �X�^�[�g�{�^�������\��
	FontAsset(U"Menu")(U"�͂��߂�").drawAt(_startbuttom.center(), ColorF(0.25));
	// Exit�{�^�������\��
	FontAsset(U"Menu")(U"��߂�").drawAt(_exitbuttom.center(), ColorF(0.25));
	// �e�{�^���z�u
	Rect(0, 500, Scene::Width(), Scene::Height() - 500)
		.draw(Arg::top = ColorF(0.0, 0.0), Arg::bottom = ColorF(0.0, 0.5));

	/* �����`�揈�� */
	// �n�C�X�R�A�K�����A�`��
	const int32 highScore = getData().highScore;
	FontAsset(U"Score")(U"�X�R�A: {}"_fmt(highScore)).drawAt(Vec2(670, 570));

	// ��Җ��\��
	FontAsset(U"Score")(U"(c)2021 Sakamaki Daiki").drawAt(Vec2(215, 570));
}