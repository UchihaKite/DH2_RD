#pragma once
#include "SFML\Graphics.hpp"

enum class AnimationType
{
	// List all Animation Types Here
	IDLE,
	WALK,
	POWERUP,
	COUNT
};

class SpriteManager
{
public:
	SpriteManager(std::string FileLocation, sf::Vector2f Scale, sf::Vector2f Position, sf::Vector2f Origin);
	virtual void Update(float DeltaTime);
	virtual void Draw(sf::RenderWindow* Window);
	
	inline void SetSpriteRect(sf::IntRect TargetRect) { m_Sprite.setTextureRect(TargetRect); } // Mostly used for Button Functionality
	inline void SetPosition(sf::Vector2f Position) { m_Sprite.setPosition(Position); }
	inline sf::Vector2f GetSize() { return m_Sprite.getScale(); }

	inline sf::Sprite ReturnSprite() { return m_Sprite; }

	void SetScale(float xScale, float yScale) { m_Sprite.setScale(xScale, yScale); }

protected:
	sf::Sprite m_Sprite;
	sf::Texture m_Texture;
	
	sf::Vector2f m_Scale;
	sf::Vector2f m_Position;
	sf::Vector2f m_Origin;

	std::string m_FileLocation;
	float m_DeltaTime;
};

class AnimationManager : public SpriteManager
{
public:
	AnimationManager(std::string FileLocation, sf::Vector2f Scale, sf::Vector2f Position, sf::Vector2f Origin);
	virtual void Update(float DeltaTime);
	virtual void Draw(sf::RenderWindow* Window);

	inline void SetAnimationLength(int AnimationLength) { m_AnimationLength = AnimationLength; }
	inline void SetSheetPosition(sf::Vector2i SheetPosition) { m_SheetPosition = SheetPosition; }
	inline void SetAnimationCap(int AnimationCap) { m_AnimationCap = AnimationCap; }
	inline void AnimationControl(bool StartOrStop) { m_StartAnimation = StartOrStop; }

	void SetUpFrames(enum class AnimationType Type);
	void PlayAnimation(enum class AnimationType Type, float DeltaTime);

private:

	void Animate(float DeltaTime, std::vector<sf::IntRect> InFrames);

	int m_AnimationLength;
	sf::Vector2i m_SheetPosition;
	int m_AnimationTick;
	float m_DeltaTime;
	int m_AnimationCap;
	bool m_StartAnimation;

	std::vector<sf::IntRect> m_WalkFrames;
	std::vector<sf::IntRect> m_IdleFrames;
	std::vector<sf::IntRect> m_PowerUpFrames;

	sf::Sprite m_ShadowSprite; // For Character/Unit Animations
	sf::Texture m_ShadowTexture;
};

class ButtonManager : public SpriteManager
{
public:
	// This will need to be adjusted as the Clickables (etc) are adjusted for the new project
private:
	// TBD
};