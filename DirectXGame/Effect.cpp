#include "Effect.h"

using namespace KamataEngine;

void Effect::Initialize(Model* model,Vector3 scale, Vector3 rotation)
{
	// NULLポインタチェック
	assert(model);

	model_ = model;

	scale_ = scale;

	rotation_ = rotation;

	worldTransform_.rotation_.z +=180.0f; 

	worldTransform_.Initialize();
}

void Effect::Update()
{
	worldTransform_.UpdateMatrix();
}

void Effect::Draw(Camera* camera)
{
	model_->Draw(worldTransform_, *camera);
}
