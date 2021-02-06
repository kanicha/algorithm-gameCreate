#include "Game.h"

Game::Game(const InitData& init)
	: IScene(init)
{
	/* 変数初期化 & 代入 */
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
	// ゲーム開始からの時間毎秒増加
	gameScore++;

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
	if (KeySpace.pressed())
	{
		// ジャンプ
		pos.y -= jumpPower;
	}
	else
	{
		// ジャンプ中にキーを離したら
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
		// ゲームオーバーの文字
		// タイトル画面に戻す
		// 最終スコアが今までのスコアより大きかったらスコア更新
		getData().highScore = Max(getData().highScore, gameScore);
	}



}
