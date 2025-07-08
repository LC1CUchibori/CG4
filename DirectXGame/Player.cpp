#include "Player.h"

using namespace KamataEngine;


Player::Player()
{
}

Player::~Player()
{
}

void Player::Initialize(Model*model,Camera*camera)
{
	// NULLポインタチェック
	assert(model);

	model_ = model;
	camera_.Initialize();
	
	playerTextureHandle_ = TextureManager::Load("BlackORE.png");

	worldTransform_.Initialize();

	position_ = {0.0f, 0.0f, 0.0f};
	worldTransform_.translation_ = position_;
	worldTransform_.Initialize();
}

void Player::Update()
{
	// プレイヤー移動入力処理
	const float speed = 1.5f;

	if (Input::GetInstance()->PushKey(DIK_A)) {
		position_.x -= speed;
	}
	if (Input::GetInstance()->PushKey(DIK_D)) {
		position_.x += speed;
	}
	if (Input::GetInstance()->PushKey(DIK_W)) {
		position_.y += speed;
	}
	if (Input::GetInstance()->PushKey(DIK_S)) {
		position_.y -= speed;
	}

	worldTransform_.translation_ = position_;

	// 定数バッファに転送
	worldTransform_.TransferMatrix();
}

void Player::Draw(Camera*camera)
{
	model_->Draw(worldTransform_, camera_,playerTextureHandle_);
}
