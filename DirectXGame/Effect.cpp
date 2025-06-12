#include "Effect.h"

using namespace KamataEngine;

void Effect::Initialize(Model2* model)
{
	// NULLポインタチェック
	assert(model);

	model_ = model;

	worldTransform_.rotation_.z =-45.0f; 

	worldTransform_.Initialize();
}

void Effect::Update()
{
	// 行列を定数バッファに転送
	worldTransform_.TransferMatrix();
}

void Effect::Draw(Camera* camera,uint32_t textureHandle)
{
	model_->Draw(worldTransform_, *camera,textureHandle);
}
