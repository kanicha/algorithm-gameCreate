// Sakamaki Daiki
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
	blockImage = Texture(U"image/Block.png");

	moveSpeed = 4;
	jumpPower = 5;
	pos = Vec2(30, 515);
}

/// <summary>
/// アップデート関数
/// </summary>
void Game::update()
{
	// ゲーム開始からの時間毎フレーム増加
	gameScore++;

	// ボタン処理
	PlayerInput();
}

/// <summary>
/// 描画関数
/// </summary>
void Game::draw() const
{
	// バックグラウンド画像配置
	backGroundImage.draw(-50, -50);
	// ブロック描画
	Blockdraw();
	// プレイヤー自機表示
	playerImage.drawAt(pos);
	// エネミー描画処理
	Enemydraw();
	// スコア表示の枠
	Rect(0, 0, 1000, 60).draw(ColorF(0.0, 0.0, 0.0, 0.3));
	// 現在のスコア表示
	FontAsset(U"Score")(U"現在のスコア: {}"_fmt(gameScore)).drawAt(Vec2(400, 30));
}

/// <summary>
/// ブロック描画関数
/// </summary>
void Game::Blockdraw() const
{
	// リスト等で管理したほうがよさそうだけれどリストわからなかったです。。。
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
/// エネミー描画関数
/// </summary>
void Game::Enemydraw() const
{
	enemyImage.drawAt(500, 400);
	enemyImage.drawAt(400, 340);
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
			pos.y *= 0.8f;
		}
	}

}

/// <summary>
/// ゲームオーバー処理関数
/// </summary>
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
