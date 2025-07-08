#pragma once
#include "KamataEngine.h"
#include <cstdint>

class Player
{
public:
	Player();
	~Player();

	void Initialize(Model* model, Camera*camera);

	void Update();

	void Draw(Camera*camera);
private:
	KamataEngine::Model* model_ = nullptr;
	KamataEngine::WorldTransform worldTransform_;

	// プレイヤーテクスチャハンドル
	uint32_t playerTextureHandle_ = 0;

	// カメラ
	KamataEngine::Camera camera_;

	KamataEngine::Vector3 position_ = {0.0f, 0.0f, 0.0f};
};

