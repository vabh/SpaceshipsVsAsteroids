#include "Bullet.h"

Bullet::Bullet(float posX_, float posY_, int damage_){
	posX = posX_;
	posY = posY_;
	speed = 0.0095;

	// depends on ship which lanuched the bullet
	damage = damage_;

	if(damage == 1){
		b =1.f;
	}
	else if(damage == 2){
		r = 1.f;
	}
	else if(damage == 3){
		g = 1.f;
	}
}

float Bullet::get_posX(){
	return posX;
}

float Bullet::get_posY(){
	return posY;
}

float Bullet::get_width(){
	return width;
}

float Bullet::get_height(){
	return height;
}

int Bullet::get_damage(){
	return damage;
}

void Bullet::draw(){
	GraphicPrimitives::drawFillRect2D(posX, posY, width, height, r, g, b);
}

void Bullet::move(){
	posX += speed;
}