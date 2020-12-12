// Sakamaki Daiki
#include <Siv3D.hpp> // OpenSiv3D v0.4.2
#include "SceneMgr.h"
#include "Title.h"

void Main()
{

	// 次回 虚無出現なおす

	/* ウィンドウ処理関連 */
	// Esc押し込みウィンドウ削除制限
	System::SetTerminationTriggers(UserAction::CloseButtonClicked);
	// ウィンドウタイトル設定
	Window::SetTitle(U"フンコロガシくん、がんばる");
	// ウィンドウを手動変更処理
	Window::SetStyle(WindowStyle::Sizable);

	// 表示用フォントを登録
	FontAsset::Register(U"Title", 120, Typeface::Regular);
	FontAsset::Register(U"Menu", 30, Typeface::Regular);
	FontAsset::Register(U"Score", 36, Typeface::Bold);

	/* シーン推移処理*/
	// オブジェクト化
	MovedScene manager;
	manager
		// シーンをクラスに追加
		.add<Title>(SceneName::Title)
		// ゲームシーン追加

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