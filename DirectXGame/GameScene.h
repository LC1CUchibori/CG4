#include "KamataEngine.h"
#include "Particle.h"
#pragma once



class GameScene
{
public:
	// インストラクタ
	GameScene();

	// デストラクタ
	~GameScene();

	// 初期化
	void Initialize();

	// 更新
	void Update();

	// 描画
	void Draw();
private:
	// パーティクル3Dモデルデータ
	KamataEngine::Model* modelParticle_ = nullptr;

	// カメラ
	KamataEngine::Camera camera_;

	// パーティクル
	Particle* particle_ = nullptr;

	std::list<Particle*> particles_;
};

