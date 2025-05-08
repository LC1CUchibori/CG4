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
}

void Effect::Draw()
{
}
