#include "Stage.h"
#include <cmath>

using namespace KamataEngine;

Stage::Stage()
{
}

Stage::~Stage()
{
	delete BGSprite_;
	delete ScrollBGSprite_;
}

void Stage::Initialize()
{
	BGTextureHandle_ = TextureManager::Load("BG.png");
	BGSprite_ = KamataEngine::Sprite::Create(BGTextureHandle_, { 0,0 });

	ScrollBGTextureHandle_ = TextureManager::Load("BG2.png");
	ScrollBGSprite_ = KamataEngine::Sprite::Create(ScrollBGTextureHandle_, { -1280,0 });
}

void Stage::Update()
{
	// 左にスクロール
	Vector2 pos1 = BGSprite_->GetPosition();
	Vector2 pos2 = ScrollBGSprite_->GetPosition();

	pos1.x -= scrollSpeed;
	pos2.x -= scrollSpeed;

	// 画面外に出たら右側に移動
	if (pos1.x <= -1280) {
		pos1.x = pos2.x + 1280;
	}
	if (pos2.x <= -1280) {
		pos2.x = pos1.x + 1280;
	}

	BGSprite_->SetPosition(pos1);
	ScrollBGSprite_->SetPosition(pos2);
}

void Stage::Draw()
{
	// DirectXCommon インスタンスの取得
	DirectXCommon* dxCommn = DirectXCommon::GetInstance();
	

	// 3Dモデル描画前処理
	Sprite::PreDraw(dxCommn->GetCommandList());

	BGSprite_->Draw();

	ScrollBGSprite_->Draw();

	// 3Dモデル描画後処理
	Sprite::PostDraw();
}
