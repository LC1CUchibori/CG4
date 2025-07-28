#include "Enemy.h"

Enemy::Enemy()
{
}

Enemy::~Enemy()
{
}

void Enemy::Initialize(KamataEngine::Model* model, uint32_t textureHandle, KamataEngine::Camera* camera)
{
	// NULLポインタチェック
	assert(model);

	model_ = model;
	textureHandle_ = textureHandle;
	camera_ = camera;

	// ランダムなY位置（例：-10.0〜10.0）、右端から出現（例：X=50.0）
	float randomY = -10.0f + static_cast<float>(rand()) / RAND_MAX * 20.0f;
	position_ = { 50.0f, randomY, 0.0f };

	// ランダムなスピード（例：0.05〜0.15）
	speed_ = 0.05f + static_cast<float>(rand()) / RAND_MAX * 0.1f;

	position_ = { 0.0f, -10.0f, 30.0f };

	worldTransform_.Initialize();

	worldTransform_.translation_ = position_;
	worldTransform_.UpdateMatrix();
	// 行列を定数バッファに転送
	worldTransform_.TransferMatrix();
}

void Enemy::Update()
{
	// 左に移動
	position_.x -= speed_; 


	worldTransform_.translation_ = position_;
	worldTransform_.UpdateMatrix();
	// 行列を定数バッファに転送
	worldTransform_.TransferMatrix();
}

void Enemy::Draw(KamataEngine::Camera* camera, uint32_t textureHandle)
{
	model_->Draw(worldTransform_, *camera, textureHandle);
}