#include "Particle.h"
#include <algorithm>

using namespace KamataEngine;
using namespace MathUtility;

void Particle::Initialize(Model*model,Vector3 position,Vector3 velocity)
{
	assert(model);

	model_ = model;

	velocity_ = velocity;

	// 色の設定
	objectColor_.Initialize();
	color_ = { 1,1,0,1 };

	// 大きさ
	worldTransform_.scale_ = { 0.2f,0.2f,0.2f };

	worldTransform_.translation_ = position;

	worldTransform_.Initialize();
}

void Particle::Update()
{
	// 色変更のオブジェクトに色の数値を設定する
	objectColor_.SetColor(color_);

	// 移動
	worldTransform_.translation_ += velocity_;

	// 終了なら何もしない
	if (isFinished_) {
		return;
	}

	// カウンターを1フレーム分の時間減らす
	counter_ += 1.0f / 60.0f;

	// 終了時間の上限に達したら
	if (counter_ >= kDuration) {
		counter_ = kDuration;
		// 終了扱いにする
		isFinished_ = true;
	}

	// フェード処理
	color_.w = std::clamp(1.0f - counter_ / kDuration, 0.0f, 1.0f);

	// 行列の更新
	worldTransform_.UpdateMatrix();
}

void Particle::Draw(Camera*camera)
{
	// 3Dモデルを作成
	model_->Draw(worldTransform_, *camera,&objectColor_);
}
