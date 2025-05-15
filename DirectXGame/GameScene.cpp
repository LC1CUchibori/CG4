#include "GameScene.h"
#include <random>
#include <cmath>  // M_PI を使いたい場合

using namespace KamataEngine;

std::random_device seedGenerator;
std::mt19937 randomEngine(seedGenerator());

std::uniform_real_distribution<float> scaleDistribution(0.2f, 0.3f);
std::uniform_real_distribution<float> rotationDistribution(-3.14159265f, 3.14159265f);

GameScene::GameScene() {}

GameScene::~GameScene()
{
	for (Effect* effect : effects_) {
		delete effect;
	}
	delete effectModel_;
}

void GameScene::Initialize()
{
	effectModel_ = Model::Create();

	// パーティクルの生成
	for (int i = 0; i < 10; i++) {
		// 生成
		Effect* effect = new Effect();
		// 位置
		KamataEngine::Vector3 position = { 0.0f,0.0f,0.1f * i };
		// 大きさ
		KamataEngine::Vector3 scale = { 3.0f, scaleDistribution(randomEngine), 3.0f };
		// 角度
		KamataEngine::Vector3 rotation = { 0.0f, 0.0f, rotationDistribution(randomEngine) };
		// 初期化
		effect->Initialize(effectModel_, scale, rotation, position);
		// リストに追加
		effects_.push_back(effect);
	}
	camera_.Initialize();
}

void GameScene::Update()
{
	for (Effect* effect : effects_) {
		effect->Update();
	}

	effects_.remove_if([](Effect* effect) {
		if (effect->IsFinished()) {
			return true;
		}
		return false;
		});
}

void GameScene::Draw()
{
	DirectXCommon* dxCommn = DirectXCommon::GetInstance();

	Model::PreDraw(dxCommn->GetCommandList());

	for (Effect* effect : effects_) {
		effect->Draw(&camera_,&objectColor_);
	}

	Model::PostDraw();
}
