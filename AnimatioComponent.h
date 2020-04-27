#ifndef ANIMATIONCOMPONENT_H
#define ANIMATIONCOMPONENT_H
#include "stdafx.h"

class AnimatioComponent
{
private:
	class Animation
	{
	public:
		//variabless
		sf::Sprite& sprite;
		sf::Texture& textureSheet;
		float animTick;
		float tick;
		int width;
		int height;
		sf::IntRect startRect;
		sf::IntRect currectRect;
		sf::IntRect endRect;

		Animation(sf::Sprite& sprite, sf::Texture& texture_sheet,
			float anim_tick,
			int start_frame_x, int start_frame_y,
			int frame_x, int frame_y,
			int width, int height) :
			sprite(sprite),
			textureSheet(texture_sheet),
			animTick(anim_tick),
			width(width), height(height)
		{
			this->tick = 0;
			this->startRect = sf::IntRect(start_frame_x * width, start_frame_y * height, width, height);
			this->currectRect = this->startRect;
			this->endRect = sf::IntRect(frame_x * width, frame_y * height, width, height);

			this->sprite.setTexture(this->textureSheet, true);
			this->sprite.setTextureRect(this->startRect);
		}

		//Function
		void play(const float& dt)
		{
			
			//Update tick
			this->tick += 100.f * dt;
			if (this->tick >= animTick)
			{
				//reset
				this->tick = 0;

				if (this->currectRect != this->endRect)
				{
					this->currectRect.left += this->width;
				}
				else
				{
					this->currectRect.left = this->startRect.left;
				}

				this->sprite.setTextureRect(this->currectRect);

			}

		}

		void reset()
		{
			this->tick = 0;
			this->currectRect.left = this->startRect.left;
		}
	};

	sf::Sprite& sprite;
	sf::Texture& textute;
	std::map<std::string, Animation*> animation;
	Animation* lastAnimation;
public:
	AnimatioComponent(sf::Sprite& sprite, sf::Texture& textureAnim);
	virtual ~AnimatioComponent();

	/*Create new animation

		key - KEY name animation
		anim_tick - dt animation in TI
		start_frame_x - start position from image for anim in X cord
		start_frame_y - start position from image for anim in Y cord
	
	
	
	
	*/
	void addAnimation(const std::string key,
		float anim_tick,
		int start_frame_x, int start_frame_y,
		int frame_x, int frame_y,
		int width, int height);

			


	void play(const std::string key,const float& dt);
	//void render(sf::RenderTarget* arget);
};
#endif // !ANIMATIONCOMPONENT_H