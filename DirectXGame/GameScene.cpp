#include "GameScene.h"

using namespace KamataEngine;

GameScene::GameScene()
{
}

GameScene::~GameScene()
{
	delete effect_;
	delete effectModel_;

	Model2::StaticFinalize();
}

void GameScene::Initialize()
{
	// Model2の初期化
	Model2::StaticInitialize();

	textureHandle_ = TextureManager::Load("uvChecker.png");

	effectModel_ = Model2::CreateSquare();
	effectModel_->SetTextureHandle(textureHandle_);

	// エフェクトの生成
	effect_ = new Effect();
	// パーティクルの初期化
	effect_->Initialize(effectModel_);


	 // カメラの初期化
	camera_.Initialize();
}

void GameScene::Update()
{
	effect_->Update();
}

void GameScene::Draw()
{
	// DirectXCommon インスタンスの取得
	DirectXCommon* dxCommn = DirectXCommon::GetInstance();

	// 3Dモデル描画前処理
	Model2::PreDraw(dxCommn->GetCommandList());

	// パーティクルの描画
	effect_->Draw(&camera_,textureHandle_);

	// 3Dモデル描画後処理
	Model2::PostDraw();
}
