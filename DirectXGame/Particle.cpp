#include "Particle.h"

using namespace KamataEngine;

void Particle::Initialize(Model*model)
{
	assert(model);

	model_ = model;

	worldTransform_.Initialize();
}

void Particle::Update()
{
	worldTransform_.TransferMatrix();
}

void Particle::Draw(Camera*camera)
{
	// 3Dモデルを作成
	model_->Draw(worldTransform_, *camera);
}
