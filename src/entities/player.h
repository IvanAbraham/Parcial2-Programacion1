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
	float remainingTime;

public:
	Player(Rectangle playerHitbox, Texture2D sprite);
	void TakeHit();
	void Update(const Maps& map);
	int GetLife() const;
	int GetScore() const;
	void AddLife();
	void AddScore(int bonusScore);
	void MultiplyScore(float scoreMultiplier);
	void Draw() const override;
	float GetRemainingTime() const;
	bool IsAlive() const;
	bool IsTimeOver() const;
};