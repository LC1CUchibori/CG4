#include "GameScene.h"

using namespace KamataEngine;

GameScene::GameScene()
{
}

GameScene::~GameScene()
{
	delete model_;

	Model2::StaticFinalize();
}

void GameScene::Initialize()
{
	// Model2の初期化
	Model2::StaticInitialize();

	// 3Dモデルの生成
	model_ = Model::Create();

	worldTransform_.Initialize();

	stage = new Stage;
	stage->Initialize();

	player_->Initialize();

	 // カメラの初期化
	camera_.Initialize();
}

void GameScene::Update()
{

	stage->Update();

	player_->Update();
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

	player_->Draw();
	/// <summary>
	/// ここに3Dオブジェクトの描画処理を追加できる
	/// </summary>

	// 3Dオブジェクト描画後処理
	Model::PostDraw();
#pragma endregion


	// 3Dモデル描画前処理
	Model2::PreDraw(dxCommn->GetCommandList());

	// パーティクルの描画

	// 3Dモデル描画後処理
	Model2::PostDraw();
}
