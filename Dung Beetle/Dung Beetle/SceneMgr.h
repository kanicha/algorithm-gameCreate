#pragma once
#include <Siv3D.hpp>

/// <summary>
/// シーン推移関数
/// </summary>
class SceneMgr
{
public:
	// シーン推移用変数
	using MovedScene = SceneManager<SceneName, HighScore>;
};

/// <summary>
/// ゲームデータ管理関数
/// </summary>
struct HighScore
{
public:
	// ハイスコア保存用変数
	int32 highScore;
};

/// <summary>
/// シーン名前管理関数
/// </summary>
enum class SceneName
{
	Title,
	Game
};