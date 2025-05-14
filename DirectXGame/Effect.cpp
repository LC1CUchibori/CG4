#include "Effect.h"

using namespace KamataEngine;

void Effect::Initialize(Model* model,Vector3 scale, Vector3 rotation)
{
	// NULLポインタチェック
	assert(model);

	model_ = model;

	worldTransform_.scale_ = { scale.x * 1.0f, scale.y * 0.5f, scale.z };  // Y方向を潰す
	worldTransform_.rotation_ = { rotation.x, rotation.y, rotation.z + static_cast<float>(3.14159265f) / 4.0f };  // Z軸に45度回転追加
	worldTransform_.translation_ = { 0, 0, 0 };

	objectColor_.Initialize();
	color_ = { 0,0,0,0 };


	worldTransform_.Initialize();
}

void Effect::Update()
{
	objectColor_.SetColor(color_);

	worldTransform_.UpdateMatrix();
}

void Effect::Draw(Camera* camera)
{
	model_->Draw(worldTransform_, *camera);
}
