#include "GameScene.h"
#include <random>
#include <cmath>  // M_PI を使いたい場合

using namespace KamataEngine;

std::random_device seedGenerator;
std::mt19937 randomEngine(seedGenerator());


std::uniform_real_distribution<float> scaleDistribution(1.0f, 3.0f);
std::uniform_real_distribution<float> rotationDistribution(-3.14159265f, 3.14159265f);

GameScene::GameScene() {}

GameScene::~GameScene()
{
	delete effect_;
	delete effectModel_;
}

void GameScene::Initialize()
{
	effectModel_ = Model::Create();

	KamataEngine::Vector3 scale = { 1.0f, scaleDistribution(randomEngine), 1.0f };

	KamataEngine::Vector3 rotation = { 0.0f, 0.0f, rotationDistribution(randomEngine) };

	effect_ = new Effect();
	effect_->Initialize(effectModel_, scale, rotation);

	camera_.Initialize();
}

void GameScene::Update()
{
	effect_->Update();
}

void GameScene::Draw()
{
	DirectXCommon* dxCommn = DirectXCommon::GetInstance();

	Model::PreDraw(dxCommn->GetCommandList());

	effect_->Draw(&camera_);

	Model::PostDraw();
}
