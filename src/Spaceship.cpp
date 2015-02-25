#include "Spaceship.h"

Spaceship::Spaceship(float posX_, float posY_, float b_r, float b_c, float cell_distance, int type_) {

	type = type_;
	posX = posX_;
	posY = posY_;

	width = 0.1f;
	height = 0.1f;

	boundary_top = b_r;
	boundary_bottom =  b_r - cell_distance;

	if(posX + width > b_c ){//prevent overlap with next col
		posX = posX - (posX + width - b_c);
	}

	if(posY + height > b_r){//prevent overlap with next row
	 	posY = posY - (posY + height - b_r);	 	
	}

	set_parameters();
}

void Spaceship::set_parameters(){
	if(type == 1){

		r = 1.0f;

		speed = 0.01f;
		fire_frequency = 50;
		fire_wait = fire_frequency;
		
		power = 2;

	}

	if(type == 2){

		g = 1.0f;

		speed = 0.008f;
		fire_frequency = 70;
		fire_wait = fire_frequency;
		
		power = 3;

	}

	if(type == 3){

		b = 1.0f;

		speed = 0.05f;
		fire_frequency = 15;
		fire_wait = fire_frequency;
		
		power = 1;

	}
}

float Spaceship::get_posX(){
	return posX;
}

float Spaceship::get_posY(){
	return posY;
}

float Spaceship::get_width(){
	return width;
}

float Spaceship::get_height(){
	return height;
}

int Spaceship::get_power(){
	return power;
}

void Spaceship::draw(){
	GraphicPrimitives::drawFillRect2D(posX, posY, width, height, r, g, b);	
}

void Spaceship::move(){
	posY += speed;
    if (posY + height > boundary_top || posY < boundary_bottom) {
        speed = -speed;
        posY += speed;
    }

    //fire frequency
    fire_wait--;
    if(fire_wait == 0)
    {
    	fire_wait = fire_frequency;
    }
}

bool Spaceship::shoot(){
	return fire_wait == 1;
}