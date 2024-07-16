#include "ObjectBase.h"

ObjectBase::ObjectBase() :
	m_modelHandle(-1)
{
	m_info.pos = VGet(0.0f, 0.0f, 0.0f);
	m_info.vec = VGet(0.0f, 0.0f, 0.0f);
	m_info.rot = VGet(0.0f, 0.0f, 0.0f);
	m_info.isExist = true;
}

ObjectBase::~ObjectBase()
{
}
