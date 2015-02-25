#include "Asteroid.h"

Asteroid::Asteroid(float posX_, float posY_, float speedY_){

	height = 0.06f;
	width = 0.06f;

	speed = -0.007f;
	speedY = speedY_;

	life = 5;

	//the difficulty level has increased
	if(speedY != 0){
		height += 0.04f;
		width += 0.04f;
		r = 0.7f;
		g = 0.1f;
		b = 0.5f;	

		speed = -0.014;

		life = 10;
	}
	
	boundary_left = -1.0f;
	boundary_right = 1.0f;

	posX = posX_;
	posY = posY_;
	if(posY + height > 1.0f){
	 	posY = posY - (posY + height - 1.0f);	 	
	}
	if(posY < -1.0f)
		posY = -1.0f;
}

float Asteroid::get_posX(){
	return posX;
}

float Asteroid::get_posY(){
	return posY;
}

float Asteroid::get_width(){
	return width;
}

float Asteroid::get_height(){
	return height;
}

void Asteroid::draw(){
	GraphicPrimitives::drawFillRect2D(posX, posY, width, height, r, g, b);
}

void Asteroid::move(){
	posX += speed;

	posY += speedY;
	if(posY >= 1.f || posY <= -1.0f)
		speedY = -speedY;
}

int Asteroid::strike(int damage){

	life = life - damage;
	return life > 0;
}

int Asteroid::get_life(){
	return life;
}

void Asteroid::set_life(int l){
	b += (life - l) * 0.1f;
	g += 0.2f;
	r += 0.2f;
	life = l;
}