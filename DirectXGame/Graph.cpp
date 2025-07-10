#include "Graph.h"
using namespace KamataEngine;

Graph::Graph()
{
}

Graph::~Graph()
{
	delete RedSprite_;
	delete GreenSprite_;
}

void Graph::Initialize()
{
	RedSprite_ = new Sprite;
	RedSprite_->Initialize();
	RedSprite_->SetSize({500.0f,50.0f});
	RedSprite_->SetColor({ 1.0f, 0.0f, 0.0f, 1.0f });
	RedSprite_->SetPosition({ 5.0f,5.0f });

	GreenSprite_ = new Sprite;
	GreenSprite_->Initialize();
	GreenSprite_->SetSize({500.0f,50.0f});
	GreenSprite_->SetColor({ 1.0f, 0.0f, 0.0f, 1.0f });
	GreenSprite_->SetPosition({ 5.0f,5.0f });
}

void Graph::Update()
{
}

void Graph::Draw()
{
	RedSprite_->Draw();
}

void Graph::SetSize(const Vector2& size)
{
	size_ = size;
	RedSprite_->SetSize(size_);
	GreenSprite_->SetSize(size_);
}

void Graph::SetPosition(const Vector2& pos)
{
	position_ = pos;
	GreenSprite_->SetPosition(position_);
}

void Graph::SetColor(const KamataEngine::Vector4& color)
{
	GreenSprite_->SetColor(color);
}
