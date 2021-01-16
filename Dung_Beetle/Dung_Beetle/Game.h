#pragma once
#include "SceneMgr.h"

class Game : public MovedScene::Scene
{
	// 次回
	// Gameシーン作成
private:

public:
	// コンストラクタを使用しシーン推移用初期化
	Game(const InitData& init);
	// タイトルアップデート関数(1f呼び出し)
	void update() override;
	// タイトル描画関数
	void draw() const override;
};

