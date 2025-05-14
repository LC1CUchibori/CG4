#include "Effect.h"

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
	objectColor_.SetColor(color_);

	worldTransform_.UpdateMatrix();
}

void Effect::Draw(Camera* camera)
{
	model_->Draw(worldTransform_, *camera);
}
