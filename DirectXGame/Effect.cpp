#include "Effect.h"

using namespace KamataEngine;

void Effect::Initialize(Model* model,Vector3 postion,Vector3 velocity)
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

void Effect::Draw(Camera* camera)
{
	model_->Draw(worldTransform_, *camera);
}
