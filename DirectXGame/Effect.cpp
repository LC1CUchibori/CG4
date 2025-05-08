#include "Effect.h"

using namespace KamataEngine;

void Effect::Initialize(Model* model)
{
	// NULLポインタチェック
	assert(model);

	model_ = model;

	worldTransform_.Initialize();
}

void Effect::Update()
{
	// 行列を定数バッファに転送
	worldTransform_.TransferMatrix();
}

void Effect::Draw()
{
}
