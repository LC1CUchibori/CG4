#include "Effect.h"
#include <algorithm>
#include <random>

using namespace KamataEngine;


void Effect::Initialize(Model* model,Vector3 scale, Vector3 rotation,Vector3 position)
{
	// NULLポインタチェック
	assert(model);

	model_ = model;

	originalScale_ = scale; 

	originalPositionX_ = position.x;

	worldTransform_.scale_ = { scale.x * 0.1f, scale.y * 0.1f, scale.z * 0.1f };

	worldTransform_.rotation_ = rotation;
	worldTransform_.translation_ = position;

	objectColor_.Initialize();
	color_ = {1, 1, 1, 1};

	worldTransform_.Initialize();
}

void Effect::Update()
{

	// 終了なら何もしない
	if (IsFinished_) {
		return;
	}

	// カウンターを1フレーム分の時間減らす
	counter_ += 1.0f / 60.0f;

	// 終了時間の上限に達したら
	if (counter_ >= kDuration) {
		counter_ = kDuration;
		// 終了扱いにする
		IsFinished_ = true;
	}

	float t = counter_ / kDuration;

	// 大きくする
	worldTransform_.scale_.x = originalScale_.x * (0.1f + 0.9f * t);
	worldTransform_.scale_.y = originalScale_.y * (0.1f + 0.9f * t);
	worldTransform_.scale_.z = originalScale_.z * (0.1f + 0.9f * t);

	worldTransform_.translation_.y += t * 0.5f; // 上昇

	// 回転処理
	float rotationSpeed = 15.0f; // 1度/フレーム
	worldTransform_.rotation_.z -= rotationSpeed * (3.14159265f / 180.0f); 

	// 色のランダム
	color_.x = std::clamp(t * 2.0f, 1.0f, 1.0f); 
	color_.y = std::clamp(t * 2.0f, 0.0f, 1.0f); 
	color_.z = std::clamp(t * 4.0f - 1.0f, 0.0f, 1.0f); 

	// フラッシュ色
	if (t < 0.2f) {
		color_ = {1, 1, 1, 1}; // 白
	} else {
		color_ = {1, 0, 0, 1.0f - t}; // 赤 → フェードアウト
	}
	
	// 左右移動（揺れ）
	float amplitude = 1.0f; // 揺れの幅
	float frequency = 5.0f; // 揺れの速さ
	// 左右に動く
	worldTransform_.translation_.x = originalPositionX_ + amplitude * std::sin(counter_ * frequency * 2.0f * 3.14159265f);

	// 色設定
	objectColor_.SetColor(color_);

	// フェード処理
	color_.w = std::clamp(1.0f - counter_ / kDuration, 0.0f, 1.0f);

	worldTransform_.UpdateMatrix();
}

void Effect::Draw(Camera* camera)
{
	model_->Draw(worldTransform_, *camera,&objectColor_);
}
