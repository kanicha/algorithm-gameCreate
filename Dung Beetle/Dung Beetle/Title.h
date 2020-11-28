#pragma once
#include <Siv3D.hpp>
#include "SceneMgr.h"

class Title 
{
private:
	// ボタン描画用変数
	Rect _startbuttom;
	Rect _exitbuttom;
	// ボタン変形用変数
	Transition _startbuttomTrance;
	Transition _exitbuttomTrasnce;

public:
	// スタートボタン作成
	Rect StartButtom();
	// Exitボタン作成
	Rect ExitButtom();
	// タイトルアップデート関数(1f呼び出し)
	void Update();
	// タイトル描画関数
	void Draw();
};