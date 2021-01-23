#include "Game.h"

Game::Game(const InitData& init)
	: IScene(init)
{

}

void Game::update()
{
	// ボタン処理
}

void Game::draw() const
{
	// プレイヤー自機表示
	PlayerDraw();
	// エネミー描画処理
	EnemyDraw();
}

void Game::PlayerDraw() const
{
	const Texture playerImage(U"image/hunkorogashi.png");
	playerImage.drawAt(300, 300);
}

void Game::EnemyDraw() const
{
	const Texture enemyImage(U"image/k0073_1.png");
	enemyImage.drawAt(270, 300);
}
