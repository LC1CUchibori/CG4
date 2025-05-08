#pragma once

#include <KamataEngine.h>

// エフェクト
class Effect
{
public:

	void Initialize(KamataEngine::Model* model,KamataEngine::Vector3 postion,KamataEngine::Vector3 velocity);

	void Update();

	void Draw(KamataEngine::Camera* camera);
private:
	// ワールド変換データ
	KamataEngine::WorldTransform worldTransform_;
	// モデル
	KamataEngine::Model* model_ = nullptr;
};

