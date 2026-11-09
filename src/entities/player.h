#pragma once
#include "entity.h"
#include "world/map.h"

class Player : public Entity
{
private:
	int currentLife;
	int maxLife;
	int score;
	float speed;
	Vector2 spawnPoint;
	Color color;

public:
	Player(Rectangle playerHitbox);
	void TakeHit();
	void Update(const Maps& map);
	int GetLife() const;
	int GetScore() const;
	void AddLife();
	void AddScore(int bonusScore);
	void MultiplyScore(float scoreMultiplier);
	void Draw() const override;

};