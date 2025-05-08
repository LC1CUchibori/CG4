#pragma once

#include <KamataEngine.h>

// エフェクト
class Effect
{
public:

	void Initialize(KamataEngine::Model* model,KamataEngine::Vector3 scale,KamataEngine::Vector3 rotation);

	void Update();

	void Draw(KamataEngine::Camera* camera);
private:
	// ワールド変換データ
	KamataEngine::WorldTransform worldTransform_;
	// モデル
	KamataEngine::Model* model_ = nullptr;

	// 大きさ
	KamataEngine::Vector3 scale_;
	// 回転
	KamataEngine::Vector3 rotation_;
};

