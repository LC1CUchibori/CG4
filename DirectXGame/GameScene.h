#pragma once
#include "KamataEngine.h"
#include "Effect.h"
#include "Model2.h"

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

	// エフェクト
	Effect* effect_ = nullptr;

	// カメラ
	KamataEngine::Camera camera_;

	// エフェクトモデル描画
	KamataEngine::Model2* effectModel_ = nullptr;


	uint32_t textureHandle_ = 0;

	// プレイヤーテクスチャハンドル
	uint32_t playerTextureHandle_ = 0;
};

