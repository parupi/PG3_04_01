#pragma once
#include "Character/BaseCaracter.h"
#include <memory>
#include "Bullet.h"
#include <list>
class Player : public BaseCaracter
{
public:
	void Initialize() override;
	void Update(char keys[256], char preKeys[256]);
	void Update()override {};
	void Draw() override;
private:
	std::list<std::unique_ptr<Bullet>> bullets_;


};