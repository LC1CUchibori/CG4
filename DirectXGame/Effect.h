#pragma once

#include <KamataEngine.h>

// エフェクト
class Effect
{
public:

	void Initialize(KamataEngine::Model* model,KamataEngine::Vector3 scale,KamataEngine::Vector3 rotation,KamataEngine::Vector3 position);

	void Update();

	void Draw(KamataEngine::Camera* camera);

	bool IsFinished() {
		return IsFinished_;
	}

private:
	// ワールド変換データ
	KamataEngine::WorldTransform worldTransform_;
	// モデル
	KamataEngine::Model* model_ = nullptr;

	// 色
	KamataEngine::ObjectColor objectColor_;
	// 色の数値
	KamataEngine::Vector4 color_;

	// 大きさ
	KamataEngine::Vector3 scale_;
	// 回転
	KamataEngine::Vector3 rotation_;

	// 終了フラグ
	bool IsFinished_ = false;
	// 経過時間カウント
	float counter_ = 0.0f;
	// 存続時間(消滅までの時間)<秒>
	const float kDuration = 1.0f;


	KamataEngine::Vector3 originalScale_;

	float rotationSpeedY_ = 0.0f;

	float originalPositionX_ = 0.0f;  // 元のX座標を保持
};

