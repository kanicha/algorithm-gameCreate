#include "Game.h"

Game::Game(const InitData& init)
	: IScene(init)
{
	// �e�摜���
	playerImage = Texture(U"image/hunkorogashi.png");
	enemyImage = Texture(U"image/Enemy1.png");
	backGroundImage = Texture(U"image/haikei-aozora.png");
	moveSpeed = 4;
	pos = Vec2(300, 300);
}

void Game::update()
{
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
	if (KeyUp.pressed())
	{
		// �W�����v

	}
}
