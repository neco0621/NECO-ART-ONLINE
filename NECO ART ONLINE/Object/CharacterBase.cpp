#include "CharacterBase.h"

CharacterBase::CharacterBase() :
	m_statusData{}
{
}

CharacterBase::~CharacterBase()
{
}

void CharacterBase::HitAttack()
{
}

void CharacterBase::OnDamage(VECTOR targetPos, int damagePoint)
{
	m_isDamage = true;
	m_statusData.hp -= damagePoint;
}
