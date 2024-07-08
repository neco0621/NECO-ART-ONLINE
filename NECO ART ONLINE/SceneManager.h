#pragma once
#include <memory>
#include <list>

class Input;
class Scene;
/// <summary>
/// �e�V�[���̑J�ڂƑ{�����R���g���[������N���X
/// </summary>
class SceneManager
{
private:
	//�A�X�^���X�N���O�����Ƃ͂ł��Ȃ�
	//�O���Ă��܂��Ǝ��̂�����Ă��܂�
	//�ꏊ���Œ艻����A�؂�ւ����ł��Ȃ�
	std::list<std::shared_ptr<Scene>>m_scenes;
public:
	~SceneManager();

	void Init();
	/// <summary>
	/// �����Ă���V�[����Update�֐����Ăяo��
	/// </summary>
	/// <param name="input">���̓N���X</param>
	void Update(Input& input);
	/// <summary>
	/// �����Ă���V�[���̕`��Draw�֐��ŌĂяo��
	/// </summary>
	void Draw();

	/// <summary>
	/// ���ݐ擪�Ŏ��s���̃V�[���������Ŏw�肳�ꂽ�V�[���ɐ؂�ւ���
	/// </summary>
	/// <param name="nextScene">���̃V�[��</param>
	void ChangeScene(std::shared_ptr<Scene> nextScene);
	/// <summary>
	/// ���݂̃V�[���̏�ɏ�����܂�
	/// </summary>
	/// <param name="nextScene">��ɏ���������V�[��</param>
	void PushScene(std::shared_ptr<Scene> nextScene);
	/// <summary>
	/// ���݂̐擪�V�[���Ƀ|�b�v���܂�
	/// </summary>
	void PopScene();
};