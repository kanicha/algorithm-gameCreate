// Sakamaki Daiki
#pragma once
#include <Siv3D.hpp>

// �V�[�����ڗp�N���X
using MovedScene = SceneManager<SceneName, HighScore>;

/// <summary>
/// �Q�[���f�[�^�Ǘ��֐�
/// </summary>
struct HighScore
{
public:
	// �n�C�X�R�A�ۑ��p�ϐ�
	int32 highScore = 0;
};

/// <summary>
/// �V�[�����O�Ǘ��֐�
/// </summary>
enum class SceneName
{
	Title,
	Game
};