#include "Game.h"

Game::Game(const InitData& init)
	: IScene(init)
{
	// 各画像代入
	playerImage = Texture(U"image/hunkorogashi.png");
	enemyImage = Texture(U"image/Enemy1.png");
	backGroundImage = Texture(U"image/haikei-aozora.png");
	moveSpeed = 4;
	pos = Vec2(300, 300);
}

void Game::update()
{
	// ボタン処理
	PlayerInput();
}

void Game::draw() const
{
	// バックグラウンド画像配置
	backGroundImage.draw(-50, -50);
	// プレイヤー自機表示
	playerImage.drawAt(pos);
	// エネミー描画処理
	enemyImage.drawAt(300, 100);
}

/// <summary>
/// プレイヤー入力関数
/// </summary>
void Game::PlayerInput() const
{
	if (KeyLeft.pressed())
	{
		// 右へ移動
		pos.x -= moveSpeed;
	}
	if (KeyRight.pressed())
	{
		// 左へ移動
		pos.x += moveSpeed;
	}
	if (KeyUp.pressed())
	{
		// ジャンプ

	}
}
