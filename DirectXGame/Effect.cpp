#include "Effect.h"
#include <algorithm>

using namespace KamataEngine;

void Effect::Initialize(Model* model,Vector3 scale, Vector3 rotation,Vector3 position, Vector3 velocity)
{
	// NULLポインタチェック
	assert(model);

	model_ = model;

	worldTransform_.scale_ = scale;
	worldTransform_.rotation_ = rotation;
	worldTransform_.translation_ = position;

	velocity_ = velocity;

	objectColor_.Initialize();
	color_ = {1, 1, 1, 1};


	worldTransform_.Initialize();
}

void Effect::Update()
{

    if (IsFinished_) return;

    counter_ += 1.0f / 60.0f;

    if (counter_ >= kDuration) {
        counter_ = kDuration;
        IsFinished_ = true;
    }

    // 位置更新
    //worldTransform_.translation_.x += velocity_.x;
    worldTransform_.translation_.y += velocity_.y;
    worldTransform_.translation_.z += velocity_.z;

    // 重力効果（例）
   // velocity_.y -= 0.01f; // 下方向に少しずつ加速

    // サイズを徐々に小さく
    float scaleFactor = 1.0f - (counter_ / kDuration);
    worldTransform_.scale_.x *= scaleFactor;

    float t = counter_ / kDuration;  // 0.0 ～ 1.0 の進行度
    color_.x = 1.0f;                // R は常に最大
    color_.y = 1.0f - t;            // G は徐々に減る（黄色→赤）
    color_.z = 0.0f;                // B はゼロ
    color_.w = std::clamp(1.0f - t, 0.0f, 1.0f);  // アルファはフェードアウト

    objectColor_.SetColor(color_);

    worldTransform_.UpdateMatrix();
}

void Effect::Draw(Camera* camera)
{
	model_->Draw(worldTransform_, *camera,&objectColor_);
}
