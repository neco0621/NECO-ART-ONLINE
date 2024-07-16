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
	if (m_scenes.empty()) {//ƒŠƒXƒg‚ª‹ó‚Á‚Û‚¾‚Á‚½‚ç“ü‚ê‘Ö‚¦‚é‚Ì‚Å‚Í‚È‚­
		m_scenes.push_back(nextScene);//––”ö‚É’Ç‰Á‚·‚é
	}
	else {
		m_scenes.back() = nextScene;//‚·‚Å‚É1‚ÂˆÈã‚ ‚Á‚½‚ç––”ö‚Ì‚à‚Ì‚ğ“ü‚ê‘Ö‚¦‚é
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
