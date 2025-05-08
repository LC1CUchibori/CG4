#include "GameScene.h"

using namespace KamataEngine;

void GameScene::Initialize()
{
	// エフェクトの生成
	effect_ = new Effect();
	// パーティクルの初期化
	effect_->Initialize();
}

void GameScene::Update()
{
	effect_->Update();
}

void GameScene::Draw()
{
	effect_->Draw();
}
