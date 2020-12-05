// Sakamaki Daiki
#pragma once
#include <Siv3D.hpp>

// シーン推移用クラス
using MovedScene = SceneManager<SceneName, HighScore>;

/// <summary>
/// ゲームデータ管理関数
/// </summary>
struct HighScore
{
public:
	// ハイスコア保存用変数
	int32 highScore = 0;
};

/// <summary>
/// シーン名前管理関数
/// </summary>
enum class SceneName
{
	Title,
	Game
};