// Sakamaki Daiki
#include <Siv3D.hpp> // OpenSiv3D v0.4.2
#include "SceneMgr.h"
#include "Title.h"
#include "Game.h"

void Main()
{
	/* ウィンドウ処理関連 */
	// Esc押し込みウィンドウ削除制限
	System::SetTerminationTriggers(UserAction::CloseButtonClicked);
	// ウィンドウタイトル設定
	Window::SetTitle(U"フンコロガシくん、がんばる");
	// バックグラウンド背景追加
	Scene::SetBackground(Palette::Lightskyblue);

	// 表示用フォントを登録
	FontAsset::Register(U"Title", 70, Typeface::Regular);
	FontAsset::Register(U"Menu", 30, Typeface::Regular);
	FontAsset::Register(U"Score", 36, Typeface::Bold);

	/* シーン推移処理*/
	// オブジェクト化
	MovedScene manager;
	manager
		// シーンをクラスに追加
		.add<Title>(SceneName::Title)
		// ゲームシーン追加
		.add<Game>(SceneName::Game)
		// 画面フェード処理
		.setFadeColor(ColorF(1.0));

	while (System::Update())
	{
		// ManagerUpdateが実行できなかった時にBreak (エラー処理)
		if (!manager.update())
		{
			break;
		}
	}
}