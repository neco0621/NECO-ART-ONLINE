#include "SceneManager.h"
#include "Scene.h"

SceneManager::~SceneManager()
{
}

void SceneManager::Init()
{
	m_scenes.back()->Init();
}

void SceneManager::Update(Input& input)
{
	m_scenes.back()->Update(input);
}

void SceneManager::Draw()
{
	for (auto& scene : m_scenes) {
		scene->Draw();
	}
}

void SceneManager::ChangeScene(std::shared_ptr<Scene> nextScene)
{
	if (m_scenes.empty()) {//���X�g������ۂ����������ւ���̂ł͂Ȃ�
		m_scenes.push_back(nextScene);//�����ɒǉ�����
	}
	else {
		m_scenes.back() = nextScene;//���ł�1�ȏ゠�����疖���̂��̂����ւ���
	}

}

void SceneManager::PushScene(std::shared_ptr<Scene> scene)
{
	m_scenes.push_back(scene);
}

void SceneManager::PopScene()
{
	m_scenes.pop_back();
}
