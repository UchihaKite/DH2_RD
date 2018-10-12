#include "AssetManagers.h"
#include <iostream>

const int SPRITE_SIZE = 96;

SpriteManager::SpriteManager(std::string FileLocation, sf::Vector2f Scale, sf::Vector2f Position, sf::Vector2f Origin) :
	m_FileLocation(FileLocation),
	m_Scale(Scale),
	m_Position(Position),
	m_Origin(Origin),
	m_DeltaTime(0.0f)
{
	if (!m_Texture.loadFromFile(m_FileLocation))
	{
		// If for whatever reason it fails to load
		std::cout << "Error loading: " << m_FileLocation << std::endl;
	}

	m_Sprite.setTexture(m_Texture);
	m_Sprite.setScale(m_Scale);
	m_Sprite.setPosition(m_Position);
	m_Sprite.setOrigin(m_Origin);
}

void SpriteManager::Update(float DeltaTime)
{
	// Might need later
}

void SpriteManager::Draw(sf::RenderWindow * Window)
{
	Window->draw(m_Sprite);
}

AnimationManager::AnimationManager(std::string FileLocation, sf::Vector2f Scale, sf::Vector2f Position, sf::Vector2f Origin) :
	SpriteManager(FileLocation, Scale, Position, Origin),
	m_AnimationTick(0),
	m_DeltaTime(0.0f),
	m_AnimationCap(0),
	m_StartAnimation(false)
{
	m_Sprite.setTextureRect(sf::IntRect(0, 0, SPRITE_SIZE, SPRITE_SIZE));
	m_ShadowTexture.loadFromFile("Sprites/shadow.png");
}

void AnimationManager::Update(float DeltaTime)
{
	SpriteManager::Update(DeltaTime);
}

void AnimationManager::Draw(sf::RenderWindow* Window)
{
	m_ShadowSprite.setTexture(m_ShadowTexture);
	m_ShadowSprite.setPosition(m_Sprite.getPosition() - sf::Vector2f(m_SheetPosition.x + 90.f, m_SheetPosition.y - 175.f));
	
	Window->draw(m_ShadowSprite);
	SpriteManager::Draw(Window);
}

void AnimationManager::SetUpFrames(AnimationType Type)
{
	if (Type == AnimationType::IDLE)
	{
		for (int AddFrame = 0; AddFrame <= m_AnimationLength; AddFrame++)
		{
			m_IdleFrames.push_back(sf::IntRect(AddFrame * m_SheetPosition.x, m_SheetPosition.y, SPRITE_SIZE, SPRITE_SIZE));
		}
	}
	if (Type == AnimationType::WALK)
	{
		for (int AddFrame = 0; AddFrame <= m_AnimationLength; AddFrame++)
		{
			m_WalkFrames.push_back(sf::IntRect(AddFrame * m_SheetPosition.x, m_SheetPosition.y, SPRITE_SIZE, SPRITE_SIZE));
		}
	}
	if (Type == AnimationType::POWERUP)
	{
		for (int AddFrame = 0; AddFrame <= m_AnimationLength; AddFrame++)
		{
			m_PowerUpFrames.push_back(sf::IntRect(AddFrame * m_SheetPosition.x, m_SheetPosition.y, SPRITE_SIZE, SPRITE_SIZE));
		}
	}
}

void AnimationManager::PlayAnimation(AnimationType Type, float DeltaTime) // Used in Update
{
	if (m_StartAnimation == true)
	{
		if (Type == AnimationType::IDLE)
		{
			Animate(DeltaTime, m_IdleFrames);
		}
		if (Type == AnimationType::WALK)
		{
			Animate(DeltaTime, m_WalkFrames);
		}
		if (Type == AnimationType::POWERUP)
		{
			Animate(DeltaTime, m_PowerUpFrames);
		}
	}
}

void AnimationManager::Animate(float DeltaTime, std::vector<sf::IntRect> InFrames)
{
	m_DeltaTime += DeltaTime;
	if (m_DeltaTime > 0.2f)
	{
		m_DeltaTime = 0;
		m_Sprite.setTextureRect(InFrames[m_AnimationTick]);
		m_AnimationTick++;
		if (m_AnimationTick >= m_AnimationCap)
		{
			m_AnimationTick = 0;
		}
	}
}