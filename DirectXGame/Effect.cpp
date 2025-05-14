#include "Effect.h"
#include <algorithm>

using namespace KamataEngine;

void Effect::Initialize(Model* model,Vector3 scale, Vector3 rotation,Vector3 position)
{
	// NULLポインタチェック
	assert(model);

	model_ = model;

	worldTransform_.scale_ = scale;
	worldTransform_.rotation_ = rotation;
	worldTransform_.translation_ = position;

	objectColor_.Initialize();
	color_ = { 0,0,0,0 };


	worldTransform_.Initialize();
}

void Effect::Update()
{
	//	終了ならなにもしない
	if (IsFinished_) {
		return;
	}

	// カウンターを1フレーム分の秒数を縮める
	if (counter_ >= kDuration) {
		counter_ = kDuration;
		// 終了扱いになる
		IsFinished_ = true;
	}


	objectColor_.SetColor(color_);

	color_.w = std::clamp(1.0f - counter_ / kDuration, 0.0f, 1.0f);

	worldTransform_.UpdateMatrix();
}

void Effect::Draw(Camera* camera)
{
	model_->Draw(worldTransform_, *camera);
}
