#include "Graph.h"
using namespace KamataEngine;

void Graph::Initialize()
{
	sprite_->SetSize({30.0f,15.0f});
	sprite_->SetColor({ 1.0f, 0.0f, 0.0f, 1.0f });
	sprite_->SetPosition({ 5.0f,5.0f });
}

void Graph::Update()
{
}

void Graph::Draw()
{
	sprite_->Draw();
}

void Graph::SetSize(const Vector2 &size)
{
	size_ = size;
	sprite_->SetSize({30.0f, size_.y});
}

void Graph::SetPosition(const Vector2& pos)
{
	position_ = pos;
	sprite_->SetPosition(position_);
}

void Graph::SetColor(const KamataEngine::Vector4& color)
{
	sprite_->SetColor(color);
}
