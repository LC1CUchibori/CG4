#include "GameScene.h"

using namespace KamataEngine;

GameScene::GameScene()
{
}

GameScene::~GameScene()
{
	// 3Dモデルデータの解放
	delete modelParticle_;
	// パーティクルの解放
	delete particle_;
}

void GameScene::Initialize()
{
	// 3Dモデルデータの生成
	modelParticle_ = Model::CreateSphere(4, 4);

	// カメラの初期化
	camera_.Initialize();

	// パーティクルの生成
	particle_ = new Particle();
	// パーティクルの初期化
	particle_->Initialize(modelParticle_);
}

void GameScene::Update()
{
	// パーティクルの更新
	particle_->Update();
}

void GameScene::Draw()
{
	// DirectXCommon インスタンスの取得
	DirectXCommon* dxCommn = DirectXCommon::GetInstance();

	// 3Dモデル描画前処理
	Model::PreDraw(dxCommn->GetCommandList());
	
	// パーティクルの描画
	particle_->Draw(&camera_);

	// 3Dモデル描画後処理
	Model::PostDraw();
}
