#pragma once

#include <KamataEngine.h>
#include "Model2.h"

// エフェクト
class Effect
{
public:

	void Initialize(KamataEngine::Model2* model);

	void Update();

	void Draw(KamataEngine::Camera* camera);
private:
	// ワールド変換データ
	KamataEngine::WorldTransform worldTransform_;
	// モデル
	KamataEngine::Model2* model_ = nullptr;
};

