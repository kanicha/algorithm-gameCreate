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

	moveSpeed = 4;
	jumpPower = 5;
	pos = Vec2(200, 200);
}

void Game::update()
{
	// �Q�[���J�n����̎��Ԗ��b����
	gameScore++;

	// �{�^������
	PlayerInput();
}

void Game::draw() const
{
	// �o�b�N�O���E���h�摜�z�u
	backGroundImage.draw(-50, -50);
	// �v���C���[���@�\��
	playerImage.drawAt(pos);
	// �G�l�~�[�`�揈��
	enemyImage.drawAt(300, 100);
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
			pos.y *= 0.9f;
		}
	}

}

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
