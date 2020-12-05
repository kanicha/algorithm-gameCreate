// Sakamaki Daiki
#include <Siv3D.hpp>
#include "Title.h"

/// <summary>
/// 初期化用関数
/// </summary>
/// <param name="init"></param>
Title::Title(const InitData& init)
	: IScene(init)
{

}

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
	// Transition関数を使い変形
	 _exitbuttomTrance = Transition(0.4s, 0.2s);
}

/// <summary>
/// タイトル画面の内部処理
/// </summary>
void Title::Update()
{
	// startbuttonTrance変数にupdate関数を使い
	// マウスオーバー時の処理毎フレーム取得
	_startbuttomTrance.update(_startbuttom.mouseOver());
	_exitbuttomTrance.update(_exitbuttom.mouseOver());

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
		changeScene(SceneName::Game);
	}

	// Exitボタンが左クリックされたら
	if (_exitbuttom.leftClicked())
	{
		// ゲームを終了
		System::Exit();
	}
}

/// <summary>
/// タイトルシーン描画関数
/// </summary>
void Title::Draw() const
{
	// タイトル表示用変数
	const String titleName = U"フンコロガシくん、がんばる";
	// ゲームの中心取得
	const Vec2 center(Scene::Center().x, 120);
	// タイトル描画
	FontAsset(U"Title")(titleName).drawAt(center.movedBy(4, 6), ColorF(0.0, 0.5));
	FontAsset(U"Title")(titleName).drawAt(center);

	/*ボタン描画処理*/
	// スタートボタン枠組み描画処理
	_startbuttom.draw(ColorF(1.0, _startbuttomTrance.value())).drawFrame(2);
	// スタートボタン文字表示
	FontAsset(U"Menu")(U"はじめる").drawAt(_startbuttom.center(), ColorF(0.25));
	// Exitボタン枠組み描画処理
	_exitbuttom.draw(ColorF(1.0, _exitbuttomTrance.value())).drawFrame(2);
	// Exitボタン文字表示
	FontAsset(U"Menu")(U"やめる").drawAt(_exitbuttom.center(), ColorF(0.25));
	// 各ボタン配置
	Rect(0, 500, Scene::Width(), Scene::Height() - 500)
		.draw(Arg::top = ColorF(0.0, 0.0), Arg::bottom = ColorF(0.0, 0.5));

	// ハイスコア習得し、描画
	const int32 highScore = getData().highScore;
	FontAsset(U"Score")(U"スコア: {}"_fmt(highScore)).drawAt(Vec2(620, 550));
}
