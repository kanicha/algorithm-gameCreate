#pragma once
#include <Siv3D.hpp>

/// <summary>
/// �V�[�����ڊ֐�
/// </summary>
class SceneMgr
{
public:
	// �V�[�����ڗp�ϐ�
	using MovedScene = SceneManager<SceneName, HighScore>;
};

/// <summary>
/// �Q�[���f�[�^�Ǘ��֐�
/// </summary>
struct HighScore
{
public:
	// �n�C�X�R�A�ۑ��p�ϐ�
	int32 highScore;
};

/// <summary>
/// �V�[�����O�Ǘ��֐�
/// </summary>
enum class SceneName
{
	Title,
	Game
};