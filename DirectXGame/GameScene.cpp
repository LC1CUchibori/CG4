#include "GameScene.h"

using namespace KamataEngine;

GameScene::GameScene()
{
}

GameScene::~GameScene()
{
	delete effect_;
	delete effectModel_;
	delete model_;

	Model2::StaticFinalize();
}

void GameScene::Initialize()
{
	// Model2の初期化
	Model2::StaticInitialize();

	textureHandle_ = TextureManager::Load("uvChecker.png");

	effectModel_ = Model2::CreateRing(5);
	effectModel_->SetTextureHandle(textureHandle_);

	// エフェクトの生成
	effect_ = new Effect();
	// パーティクルの初期化
	effect_->Initialize(effectModel_);

	// 3Dモデルの生成
	model_ = Model::Create();

	playerTextureHandle_ = TextureManager::Load("BlackORE.png");

	worldTransform_.Initialize();

	stage = new Stage;
	stage->Initialize();

	position_ = {0.0f, 0.0f, 0.0f};
	worldTransform_.translation_ = position_;
	worldTransform_.Initialize();

	 // カメラの初期化
	camera_.Initialize();
}

void GameScene::Update()
{
	effect_->Update();

	stage->Update();

	// プレイヤー移動入力処理
	const float speed = 0.2f;

	if (Input::GetInstance()->PushKey(DIK_LEFT)) {
		position_.x -= speed;
	}
	if (Input::GetInstance()->PushKey(DIK_RIGHT)) {
		position_.x += speed;
	}
	if (Input::GetInstance()->PushKey(DIK_UP)) {
		position_.y += speed;
	}
	if (Input::GetInstance()->PushKey(DIK_DOWN)) {
		position_.y -= speed;
	}
}

void GameScene::Draw()
{
	// DirectXCommon インスタンスの取得
	DirectXCommon* dxCommn = DirectXCommon::GetInstance();

#pragma region 背景スプライト描画
	// 背景スプライト描画前処理
	Sprite::PreDraw(dxCommn->GetCommandList());

	/// <summary>
	/// ここに背景スプライトの描画処理を追加できる
	/// </summary>
	stage->Draw();

	// スプライト描画後処理
	Sprite::PostDraw();
#pragma endregion

#pragma region 3Dオブジェクト描画
	dxCommn->ClearDepthBuffer();
	// 3Dオブジェクト描画前処理
	Model::PreDraw(dxCommn->GetCommandList());

	model_->Draw(worldTransform_, camera_, playerTextureHandle_);

	/// <summary>
	/// ここに3Dオブジェクトの描画処理を追加できる
	/// </summary>

	// 3Dオブジェクト描画後処理
	Model::PostDraw();
#pragma endregion


	// 3Dモデル描画前処理
	Model2::PreDraw(dxCommn->GetCommandList());

	// パーティクルの描画
	effect_->Draw(&camera_,textureHandle_);

	// 3Dモデル描画後処理
	Model2::PostDraw();
}
