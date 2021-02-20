// Sakamaki Daiki
#include "Game.h"

Game::Game(const InitData& init)
	: IScene(init)
{
	/* �ϐ������� & ��� */
	gameScore = 0;
	gameEndFlag = false;

	playerImage = Texture(U"image/hunkorogashi.png");
	enemyImage = Texture(U"image/Enemy1.png");
	backGroundImage = Texture(U"image/haikei-aozora.png");
	blockImage = Texture(U"image/Block.png");

	moveSpeed = 4;
	jumpPower = 5;
	pos = Vec2(30, 515);
}

/// <summary>
/// �A�b�v�f�[�g�֐�
/// </summary>
void Game::update()
{
	// �Q�[���J�n����̎��Ԗ��t���[������
	gameScore++;

	// �{�^������
	PlayerInput();
}

/// <summary>
/// �`��֐�
/// </summary>
void Game::draw() const
{
	// �o�b�N�O���E���h�摜�z�u
	backGroundImage.draw(-50, -50);
	// �u���b�N�`��
	Blockdraw();
	// �v���C���[���@�\��
	playerImage.drawAt(pos);
	// �G�l�~�[�`�揈��
	Enemydraw();
	// �X�R�A�\���̘g
	Rect(0, 0, 1000, 60).draw(ColorF(0.0, 0.0, 0.0, 0.3));
	// ���݂̃X�R�A�\��
	FontAsset(U"Score")(U"���݂̃X�R�A: {}"_fmt(gameScore)).drawAt(Vec2(400, 30));
}

/// <summary>
/// �u���b�N�`��֐�
/// </summary>
void Game::Blockdraw() const
{
	// ���X�g���ŊǗ������ق����悳����������ǃ��X�g�킩��Ȃ������ł��B�B�B
	blockImage.drawAt(30, 570);
	blockImage.drawAt(90, 570);
	blockImage.drawAt(150, 570);
	blockImage.drawAt(210, 570);
	blockImage.drawAt(270, 570);
	blockImage.drawAt(330, 570);
	blockImage.drawAt(390, 570);
	blockImage.drawAt(450, 570);
	blockImage.drawAt(510, 570);
	blockImage.drawAt(570, 570);
	blockImage.drawAt(630, 570);
	blockImage.drawAt(690, 570);
	blockImage.drawAt(750, 570);
	blockImage.drawAt(810, 570);
}

/// <summary>
/// �G�l�~�[�`��֐�
/// </summary>
void Game::Enemydraw() const
{
	enemyImage.drawAt(500, 400);
	enemyImage.drawAt(400, 340);
} 

/// <summary>
/// �v���C���[���͊֐�
/// </summary>
void Game::PlayerInput() const
{
	if (KeyLeft.pressed())
	{
		// �E�ֈړ�
		pos.x -= moveSpeed;
	}
	if (KeyRight.pressed())
	{
		// ���ֈړ�
		pos.x += moveSpeed;
	}
	if (KeySpace.pressed())
	{
		// �W�����v
		pos.y -= jumpPower;
	}
	else
	{
		// �W�����v���ɃL�[�𗣂�����
		if (pos.y < 0 && !KeySpace.pressed())
		{
			pos.y *= 0.8f;
		}
	}

}

/// <summary>
/// �Q�[���I�[�o�[�����֐�
/// </summary>
void Game::GameOver() const
{
	gameEndFlag = true;

	if (gameEndFlag == true)
	{
		// �Q�[���I�[�o�[�̕���
		// �^�C�g����ʂɖ߂�
		// �ŏI�X�R�A�����܂ł̃X�R�A���傫��������X�R�A�X�V
		getData().highScore = Max(getData().highScore, gameScore);
	}
}
