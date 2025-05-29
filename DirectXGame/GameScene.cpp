#include "GameScene.h"
#include <random>

using namespace KamataEngine;
using namespace MathUtility;

std::random_device seedGenerator;
std::mt19937 randomEngine(seedGenerator());
std::uniform_real_distribution<float> distribution(-1.0f, 1.0f);

GameScene::GameScene()
{
}

GameScene::~GameScene()
{
	// 3Dモデルデータの解放
	delete modelParticle_;
	// パーティクルの解放
	for (Particle* particle : particles_) {
		delete particle;
	}
	particles_.clear();
}

void GameScene::Initialize()
{
	// 3Dモデルデータの生成
	modelParticle_ = Model::CreateSphere(4, 4);

	// カメラの初期化
	camera_.Initialize();

	// 乱数の初期化
	srand((unsigned)time(NULL));
}

void GameScene::Update()
{
	particles_.remove_if([](Particle* particle) {
		if (particle->IsFinished()) {
			return true;
		}
		return false;
	});

	

	// 確率で発生
	if (rand() % 20 == 0) {
		// 発生位置は乱数
		Vector3 position = { distribution(randomEngine) * 30.0f,distribution(randomEngine) * 20.0f,0 };

		// パーティクルの発生
		ParticleBorn(position);
	}

	// パーティクルの更新
	for (Particle* particle : particles_) {
		particle->Update();
	}
}

void GameScene::Draw()
{
	// DirectXCommon インスタンスの取得
	DirectXCommon* dxCommn = DirectXCommon::GetInstance();

	// 3Dモデル描画前処理
	Model::PreDraw(dxCommn->GetCommandList());
	
	// パーティクルの描画
	for (Particle* particle : particles_) {
		particle->Draw(&camera_);
	}

	// 3Dモデル描画後処理
	Model::PostDraw();
}

void GameScene::ParticleBorn(Vector3 position)
{
	// パーティクルの作成
	for (int i = 0; i < 150; i++) {
		// 生成
		Particle* particle = new Particle();
		// 位置
		//Vector3 position = { 0.0f,0.0f,0.0f };
		// 移動量
		Vector3 velocity = { distribution(randomEngine),distribution(randomEngine),0 };

		Normalize(velocity);
		velocity *= distribution(randomEngine);
		velocity *= 0.1f;

		// 初期化
		particle->Initialize(modelParticle_, position,velocity);
		// リストに追加
		particles_.push_back(particle);
	}
}

