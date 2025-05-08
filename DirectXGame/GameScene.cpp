#include "GameScene.h"
#include <random>

using namespace KamataEngine;

std::random_device seedGenerator;
std::mt19937 randomEngine(seedGenerator());
std::uniform_real_distribution<float> distribution(-1.0f, 1.0f);


GameScene::GameScene()
{
}

GameScene::~GameScene()
{
	delete effect_;
	delete effectModel_;
}

void GameScene::Initialize()
{
	effectModel_ = Model::Create();

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
	Model::PreDraw(dxCommn->GetCommandList());

	// パーティクルの描画
	effect_->Draw(&camera_);

	// 3Dモデル描画後処理
	Model::PostDraw();
}
