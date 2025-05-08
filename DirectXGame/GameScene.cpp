#include "GameScene.h"

using namespace KamataEngine;

GameScene::GameScene()
{
}

GameScene::~GameScene()
{
	delete effect_;
}

void GameScene::Initialize()
{
	// エフェクトの生成
	effect_ = new Effect();
	// パーティクルの初期化
	effect_->Initialize(effectModel_);
}

void GameScene::Update()
{
	effect_->Update();
}

void GameScene::Draw()
{
	effect_->Draw();
}
