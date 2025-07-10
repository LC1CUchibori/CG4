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
	delete player_;

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

	playerTextureHandle_ = TextureManager::Load("BlackORE.png");
	// 3Dモデルの生成
	playerModel_ = Model::Create();

	// プレイヤーの生成と初期化
	player_ = new Player();
	player_->Initialize(playerModel_,playerTextureHandle_,&camera_);

	stage = new Stage;
	stage->Initialize();

	// HPバーの生成と初期化
	RedGraph_ = new Graph();
	RedGraph_->Initialize();
	//  グラフ生成
	RedGraph_->SetSize({250.0f,50.0f});
	RedGraph_->SetColor({ 1.0f, 0.0f, 0.0f, 0.5f });
	RedGraph_->SetPosition({ 5.0f,5.0f });

	GreenGraph_ = new Graph();
	GreenGraph_->Initialize();
	GreenGraph_->SetSize({250.0f,50.0f});
	GreenGraph_->SetColor({ 0.0f, 1.0f, 0.0f, 0.5f });
	GreenGraph_->SetPosition({ 5.0f,5.0f });

	worldTransform_.Initialize();
	 // カメラの初期化
	camera_.Initialize();
}

void GameScene::Update()
{

	effect_->Update();

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
	
	// 背景の描画
	stage->Draw();

	// スプライト描画後処理
	Sprite::PostDraw();
#pragma endregion

#pragma region 3Dオブジェクト描画
	dxCommn->ClearDepthBuffer();
	// 3Dオブジェクト描画前処理
	Model::PreDraw(dxCommn->GetCommandList());

	/// <summary>
	/// ここに3Dオブジェクトの描画処理を追加できる
	/// </summary>
	
	// プレイヤーの描画
	player_->Draw(&camera_, playerTextureHandle_);

	// 3Dオブジェクト描画後処理
	Model::PostDraw();
#pragma endregion

#pragma region 前景スプライト描画
	// 前景スプライト描画前処理
	Sprite::PreDraw(dxCommn->GetCommandList());

	/// <summary>
	/// ここに前景スプライトの描画処理を追加できる
	/// </summary>

	// グラフの描画
	RedGraph_->Draw();
	GreenGraph_->Draw();

	// スプライト描画後処理
	Sprite::PostDraw();

#pragma endregion

	// 3Dモデル描画前処理
	Model2::PreDraw(dxCommn->GetCommandList());

	// パーティクルの描画
	effect_->Draw(&camera_,textureHandle_);

	// 3Dモデル描画後処理
	Model2::PostDraw();
}
