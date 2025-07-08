#pragma once
#include "KamataEngine.h"
#include "Effect.h"
#include "Model2.h"
#include "Stage.h"
#include "Player.h"

class GameScene
{
public:
	GameScene();

	~GameScene();

	// 初期化
	void Initialize();

	// 更新
	void Update();

	// 描画
	void Draw();

private:
	KamataEngine::Model* model_ = nullptr;
	KamataEngine::WorldTransform worldTransform_;

	// カメラ
	KamataEngine::Camera camera_;

	uint32_t textureHandle_ = 0;

	Stage* stage = nullptr;

	Player* player_ = nullptr;
};

