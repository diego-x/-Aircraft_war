#pragma once
#include "GameObject.h"
#include "resource.h"
class Guanka :
	public CGameObject
{
public:
	int number=1;
	Guanka()
	{

	}
	~Guanka(){}
	void setguan() { number++; }
	int getguan()
	{
		return number;
	}
}
