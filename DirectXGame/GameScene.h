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
	std::list<Effect*>effects_;

	// カメラ
	KamataEngine::Camera camera_;

	KamataEngine::ObjectColor objectColor_;

	// エフェクトモデル描画
	KamataEngine::Model* effectModel_ = nullptr;
};

