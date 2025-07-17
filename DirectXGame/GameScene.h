#pragma once
#include "KamataEngine.h"
#include "Effect.h"
#include "Model2.h"
#include "Stage.h"
#include "Player.h"
#include "Graph.h"

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

	void Number();

private:
	KamataEngine::Model* model_ = nullptr;
	KamataEngine::WorldTransform worldTransform_;

	// エフェクト
	Effect* effect_ = nullptr;

	// カメラ
	KamataEngine::Camera camera_;

	// エフェクトモデル描画
	KamataEngine::Model2* effectModel_ = nullptr;

	uint32_t textureHandle_ = 0;

	Player* player_ = nullptr;
	KamataEngine::Model* playerModel_ = nullptr;

	// プレイヤーテクスチャハンドル
	uint32_t playerTextureHandle_ = 0;

	Stage* stage = nullptr;

	Graph* RedGraph_ = nullptr;
	Graph* GreenGraph_ = nullptr;
	KamataEngine::Sprite* sprite_ = nullptr;

	float hp_ = 100.0f;
	bool isDamageActive_ = false; 

	KamataEngine::Vector2 size_ = { 32.0f,64.0f };
	KamataEngine::Sprite* numberSprite_[5]{};
	uint32_t numberTextureHandle_ = 0;
};

