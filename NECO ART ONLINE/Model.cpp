#include "Model.h"

Model::Model(const char* fileName)
{
}

Model::~Model()
{
}

void Model::Update()
{
}

void Model::Draw()
{
}

void Model::SetPos(VECTOR pos)
{
}

void Model::SetScale(VECTOR scale)
{
}

void Model::SetRot(VECTOR rot)
{
}

void Model::SetAnimation(int animNo, bool isLoop, bool isForceChange)
{
}

void Model::ChangeAnimation(int animNo, bool isLoop, bool isForceChange, int ChangeFrame)
{
}

bool Model::IsAnimEnd()
{
	return false;
}

void Model::ClearAnimData(AnimData& anim)
{
}
