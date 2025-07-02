#include "TitleScene.h"

using namespace KamataEngine;

TitleScene::TitleScene()
{
}

TitleScene::~TitleScene()
{
	delete TitleSprite_;
	delete BGSprite_;
}

void TitleScene::Initialize()
{
	TitleTextureHandle_ = TextureManager::Load("title.png");

	TitleSprite_ = Sprite::Create(TitleTextureHandle_, { 150,50 });

	BGTextureHandle_ = TextureManager::Load("BG.png");

	BGSprite_ = KamataEngine::Sprite::Create(BGTextureHandle_, { 0,0 });
}

void TitleScene::Update()
{
	if (!isTitleStopped_) {
		// Y座標のイージング移動
		float deltaY = targetY_ - titleY_;
		titleY_ += deltaY * 0.03f;

		// 揺れの時間更新
		oscillationTime_ += 0.01f;

		// X座標
		float offsetX = std::sin(oscillationTime_) * 10.0f;

		// 停止条件
		if (std::abs(deltaY) < 0.5f) {
			isTitleStopped_ = true;
			titleY_ = targetY_;
			offsetX = 0.0f;
		}

		// スプライト位置設定
		TitleSprite_->SetPosition({ 150 + 50, titleY_ });
	}
}

void TitleScene::Draw()
{
	// DirectXCommon インスタンスの取得
	DirectXCommon* dxCommn = DirectXCommon::GetInstance();

	// 3Dモデル描画前処理
	Sprite::PreDraw(dxCommn->GetCommandList());

	BGSprite_->Draw();

	TitleSprite_ -> Draw();
	
	// 3Dモデル描画後処理
	Sprite::PostDraw();
}
