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
	
    // ランダムに色を選択（赤・青・黄・紫）
    int colorIndex = rand() % 6;
    switch (colorIndex) {
    case 0: color_ = {1, 0, 0, 1}; break; // 赤
    case 1: color_ = {0, 0, 1, 1}; break; // 青
    case 2: color_ = {1, 1, 0, 1}; break; // 黄
    case 3: color_ = {1, 0, 1, 1}; break; // 紫
    case 4: color_ = {1, 0.5f, 0.75f, 1}; break;// ピンク
    case 5: color_ = {1, 1, 1, 1}; break;       // 白
    }


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

    color_.w = std::clamp(1.0f - counter_ / kDuration, 0.0f, 1.0f);
    objectColor_.SetColor(color_);

    worldTransform_.UpdateMatrix();
}

void Effect::Draw(Camera* camera)
{
	model_->Draw(worldTransform_, *camera,&objectColor_);
}
