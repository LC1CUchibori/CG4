#pragma once

#include <KamataEngine.h>

// エフェクト
class Effect
{
public:

	void Initialize(KamataEngine::Model* model);

	void Update();

	void Draw();
private:
	// ワールド変換データ
	KamataEngine::WorldTransform worldTransform_;
	// モデル
	KamataEngine::Model* model_ = nullptr;
};

