// Sakamaki Daiki
#pragma once
#include "SceneMgr.h"

class Title : public MovedScene::Scene
{
private:
	/* 各ボタン処理 */
	// スタートボタン処理
	Rect _startbuttom = 
		// スタートボタンを画面の中央に配置
		_startbuttom = Rect(Arg::center =
		Scene::Center().movedBy(0, 0), 300, 60);
	// Transition関数を使い変形(?)
	Transition _startbuttomTrance = Transition(0.4s, 0.2s);

	// Exitボタン処理
	Rect _exitbuttom = 
		// Exitボタンを画面の中央配置
		_exitbuttom = Rect(Arg::center =
		Scene::Center().movedBy(0, 100), 300, 60);
	// Transition関数を使い変形
	Transition _exitbuttomTrance = Transition(0.4s, 0.2s);

public:
	// コンストラクタを使用しシーン推移用初期化
	Title(const InitData& init);
	// タイトルアップデート関数(1f呼び出し)
	void update() override;
	// タイトル描画関数
	void draw() const override;
};