// Sakamaki Daiki
#pragma once
#include <Siv3D.hpp>

/// <summary>
/// シーン名前管理関数
/// </summary>
enum class SceneName
{
	Title,
	Game
};

/// <summary>
/// ゲームデータ管理関数
/// </summary>
struct HighScore
{
	// ハイスコア保存用変数
	int32 highScore = 0;
};

// シーン推移用クラス
using MovedScene = SceneManager<SceneName, HighScore>;