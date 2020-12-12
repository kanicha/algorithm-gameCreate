// Sakamaki Daiki
#pragma once
#include <Siv3D.hpp>

/// <summary>
/// �V�[�����O�Ǘ��֐�
/// </summary>
enum class SceneName
{
	Title,
	Game
};

/// <summary>
/// �Q�[���f�[�^�Ǘ��֐�
/// </summary>
struct HighScore
{
	// �n�C�X�R�A�ۑ��p�ϐ�
	int32 highScore = 0;
};

// �V�[�����ڗp�N���X
using MovedScene = SceneManager<SceneName, HighScore>;