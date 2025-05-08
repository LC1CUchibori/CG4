#pragma once
#include "KamataEngine.h"
#include "Effect.h"

class GameScene
{
public:
	GameScene();

	~GameScene();

	// 初期化
	void Initialize();

	// 更新
	void Update();

	// 描画
	void Draw();

private:
	// エフェクト
	Effect* effect_ = nullptr;

	KamataEngine::Model* effectModel_ = nullptr;
};

