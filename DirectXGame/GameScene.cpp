#include "GameScene.h"
#include <random>
#include <cmath>  // M_PI を使いたい場合

using namespace KamataEngine;

std::random_device seedGenerator;
std::mt19937 randomEngine(seedGenerator());

std::uniform_real_distribution<float> distribution(-1.0f, 1.0f);
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

	camera_.Initialize();

	// 乱数の初期化
	srand((unsigned)time(NULL));
}

void GameScene::Update()
{
	// 終了フラグの立ってエフェクトを削除
	effects_.remove_if([](Effect* effect) {
		if (effect->IsFinished()) {
			return true;
		}
		return false;
		});

	if (rand() % 20 == 0) {
		// 発生位置は乱数
		Vector3 position = { distribution(randomEngine) * 30.0f,distribution(randomEngine) * 20.0f,0 };
		// パーティクルの発生
		EffectBorn(position);
	}

	for (Effect* effect : effects_) {
		effect->Update();
	}
}

void GameScene::Draw()
{
	DirectXCommon* dxCommn = DirectXCommon::GetInstance();

	Model::PreDraw(dxCommn->GetCommandList());

	for (Effect* effect : effects_) {
		effect->Draw(&camera_);
	}

	Model::PostDraw();
}

void GameScene::EffectBorn(Vector3 position)
{
	// パーティクルの生成
	for (int i = 0; i < 10; i++) {
		// 生成
		Effect* effect = new Effect();
		// 大きさ
		KamataEngine::Vector3 scale = { 3.0f, scaleDistribution(randomEngine), 3.0f };
		// 角度
		KamataEngine::Vector3 rotation = { 0.0f, 0.0f, rotationDistribution(randomEngine) };
		// 初期化
		effect->Initialize(effectModel_, scale, rotation, position);
		// リストに追加
		effects_.push_back(effect);
	}
}
