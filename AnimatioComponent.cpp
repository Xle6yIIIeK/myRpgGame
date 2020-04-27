#include "AnimatioComponent.h"

AnimatioComponent::AnimatioComponent(sf::Sprite& sprite, sf::Texture& textureAnim) :
	sprite(sprite), textute(textureAnim), lastAnimation(NULL)
{

}

AnimatioComponent::~AnimatioComponent()
{
	for (auto& i : this->animation)
	{
		delete i.second;
	}
}

void AnimatioComponent::addAnimation(const std::string key,
	float anim_tick,
	int start_frame_x, int start_frame_y,
	int frame_x, int frame_y,
	int width, int height)
{
	this->animation[key] = new Animation(
		this->sprite, this->textute,
		anim_tick,
		start_frame_x, start_frame_y,
		frame_x, frame_y,
		width, height);
}
//someadd coment

void AnimatioComponent::play(const std::string key, const float& dt)
{
	if (this->lastAnimation != this->animation[key])
	{
		if (this->lastAnimation == NULL)
		{
			this->lastAnimation = this->animation[key];
		}
		else
		{
			this->lastAnimation->reset();
			this->lastAnimation = this->animation[key];
		}
	}
	this->animation[key]->play(dt);
}
