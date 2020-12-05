// Sakamaki Daiki
#pragma once
#include <Siv3D.hpp>
#include "SceneMgr.h"

class Title : public MovedScene::Scene
{
private:
	// ボタン描画用変数
	Rect _startbuttom;
	Rect _exitbuttom;
	// ボタン変形用変数
	Transition _startbuttomTrance;
	Transition _exitbuttomTrance;

public:
	// シーン推移用初期化
	Title(const InitData& init);
	// スタートボタン作成
	Rect StartButtom();
	// Exitボタン作成
	Rect ExitButtom();
	// タイトルアップデート関数(1f呼び出し)
	void Update();
	// タイトル描画関数
	void Draw() const;
};