#include <Siv3D.hpp>
#include "Title.h"

Rect Title::StartButtom()
{
	// スタートボタンを画面の中央に配置
	_startbuttom = Rect(Arg::center =
		Scene::Center().movedBy(0, 0), 300, 60);
	// Transition関数を使い変形(?)
	_startbuttomTrance = Transition(0.4s, 0.2s);
}

Rect Title::ExitButtom()
{
	// Exitボタンを画面の中央配置
	_exitbuttom = Rect(Arg::center =
		Scene::Center().movedBy(0, 100), 300, 60);
	// Transition関数を使い変形(?)
	 _exitbuttomTrasnce = Transition(0.4s, 0.2s);
}

/// <summary>
/// タイトル画面の内部処理
/// </summary>
void Title::Update()
{
	// startbuttonTrance変数にupdate関数を使い
	// マウスオーバー時の処理毎フレーム取得
	_startbuttomTrance.update(_startbuttom.mouseOver());
	_exitbuttomTrasnce.update(_exitbuttom.mouseOver());

	// スタートボタン or Exitボタンにマウスが重ねられた時
	if (_startbuttom.mouseOver() || _exitbuttom.mouseOver())
	{
		// カーソルの形を手の形に変更
		Cursor::RequestStyle(CursorStyle::Hand);
	}

	// スタートボタンが左クリックされた時
	if (_startbuttom.leftClicked())
	{
		// ゲームシーン推移
	}

	if (_exitbuttom.leftClicked())
	{
		// ゲームを終了
		System::Exit();
	}
}

void Title::Draw()
{

}
