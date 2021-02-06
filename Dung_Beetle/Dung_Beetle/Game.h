#pragma once
#include "SceneMgr.h"

class Game : public MovedScene::Scene
{
	// 次回
	// 時間でスコア増加、ジャンプ処理、敵ランダム出現くらい
private:
	// スコア変数
	mutable int gameScore;
	// ゲーム終了クラス
	mutable bool gameEndFlag;
	// bool型でも数値の変更が可能なmutable Texture型を宣言
	mutable Texture playerImage;
	mutable Texture enemyImage;
	mutable Texture backGroundImage;
	// 移動速度
	double moveSpeed;
	// ジャンプ力
	double jumpPower;
	// プレイヤーポジション
	mutable Vec2 pos;


public:
	// コンストラクタを使用しシーン推移用初期化
	Game(const InitData & init);
	// タイトルアップデート関数(1f呼び出し)
	void update() override;
	// タイトル描画関数
	void draw() const override;
	// プレイヤー入力系関数
	void PlayerInput() const;
	// ゲームオーバー関数
	void GameOver() const;
};

