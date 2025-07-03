#pragma once
#include <cstdint>
#include <KamataEngine.h>

class Stage
{
public:
	Stage();
	~Stage();

	void Initialize();

	void Update();

	void Draw();

private:
	// 背景テクスチャハンドル
	uint32_t BGTextureHandle_ = 0;
	// 背景スプライト
	KamataEngine::Sprite* BGSprite_ = nullptr;

	// 背景テクスチャハンドル
	uint32_t ScrollBGTextureHandle_ = 0;
	// 背景スプライト
	KamataEngine::Sprite* ScrollBGSprite_ = nullptr;

	const int posX = 640;
	const int posY = 360;
	const float scrollPos[4] = { 0.0f,1280.0f,2560.0f,3840.0f };
	const float scrollSpeed = 2.0f;
};

