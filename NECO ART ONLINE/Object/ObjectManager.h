#pragma once
#include <memory>
#include <list>
#include "../Game.h"

class ObjectBase;

class ObjectManager
{
public:
	ObjectManager();
	virtual ~ObjectManager();

	void Update();
	void Draw();
};

