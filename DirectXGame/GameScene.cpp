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

	for (int i = 0; i < 5; i++) {
		delete numberSprite_[i];
	}

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

	enemyTextureHandle_ = TextureManager::Load("white1x1.png");
	enemyModel_ = Model::Create();
	for (int i = 0; i < 5; i++) {
		Enemy* enemy = new Enemy();
		enemy->Initialize(playerModel_, playerTextureHandle_, &camera_);
		enemies_.push_back(enemy);
	}

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

	numberTextureHandle_ = TextureManager::Load("number.png");
	for (int i = 0; i < 5; i++) {
		numberSprite_[i]= Sprite::Create(numberTextureHandle_, { 100.0f+size_.x * i,5 });
		numberSprite_[i]->SetSize(size_);
	}

	worldTransform_.Initialize();
	 // カメラの初期化
	camera_.Initialize();
}

void GameScene::Update()
{

	effect_->Update();

	stage->Update();

	player_->Update();

	for (Enemy* enemy : enemies_) {
		enemy->Update();
	}

	Input* input = Input::GetInstance();

	// スペースキーが押されたらHPを減らす
	if (input->TriggerKey(DIK_SPACE)) {
		isDamageActive_ = true;
	}

	// フラグが立っている間は毎フレームHPを減らす
	if (isDamageActive_) {
		hp_ -= 0.5f;  // フレームごとの減少量
		if (hp_ <= 0.0f) {
			hp_ = 0.0f;
			isDamageActive_ = false;  // HPが尽きたら自動減少ストップ（必要なら）
		}
	}

	Number();

	// HPに応じてグラフの割合を更新
	float rate = hp_ / 100.0f;
	GreenGraph_->SetGraphValue(rate);
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

	for (Enemy* enemy : enemies_) {
		enemy->Draw(&camera_, enemyTextureHandle_);
	}


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

	for (int i = 0; i < 5; i++) {
		numberSprite_[i]->Draw();
	}

	// スプライト描画後処理
	Sprite::PostDraw();

#pragma endregion

	// 3Dモデル描画前処理
	Model2::PreDraw(dxCommn->GetCommandList());

	// パーティクルの描画
	//effect_->Draw(&camera_,textureHandle_);

	// 3Dモデル描画後処理
	Model2::PostDraw();
}

void GameScene::Number()
{
	int32_t number = static_cast<int32_t>(hp_);
	int32_t digit = 10000;

	for (int i = 0; i < 5; i++) {
		int32_t nowNumber = number / digit;
		number %= digit;

		numberSprite_[i]->SetTextureRect({ size_.x * nowNumber, 0.0f }, size_);

		digit /= 10;
	}
}


