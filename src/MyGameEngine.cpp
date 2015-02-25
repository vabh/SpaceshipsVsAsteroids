#include "MyGameEngine.h"

void MyGameEngine::idle(){

	//asteroids and bullets
	collision_asteroid_bullet();
	//asteroids and spaceships
	collision_asteroid_spaceship();
	
	//ships and firing bullets
    for (int i = 0; i < ships->size(); i++) {
        (*ships)[i]->move();

        //controlling fire frequency
        if((*ships)[i]->shoot()){

        	float posX = (*ships)[i]->get_posX();
        	float posY = (*ships)[i]->get_posY();
        	float width = (*ships)[i]->get_width();
        	int damage = (*ships)[i]->get_power();//damage of bullet->power of ship

        	bullets->push_back(new Bullet(posX + width / 2, posY, damage));
        }
    }

    //bullets
    for (int i = 0; i < bullets->size(); i++) {
    	//drawing bullets within the grid, removing others
    	if((*bullets)[i]->get_posX() + (*bullets)[i]->get_width() < 1.f)
        	(*bullets)[i]->move();

        else{
        	//removing out of bounds bullets
        	Bullet *t = (*bullets)[i];
        	bullets->erase(bullets->begin() + i);
        	delete t;
        	t = NULL;
        }
    }

    //asteroids
    for (int i = 0; i < asteroids->size(); i++) {
      	
        if((*asteroids)[i]->get_posX() + (*asteroids)[i]->get_width() > -1.f)
	    	(*asteroids)[i]->move();

        else{
        	//removing out of bound asteroids
        	//score decreases as asteroid has reached the boundary
        	grid->set_score(-ASTEROID_COST);        	

	       	Asteroid *t = (*asteroids)[i];
        	asteroids->erase(asteroids->begin() + i);
        	t = NULL;
        	delete t;
        }
    }
}

void MyGameEngine::collision_asteroid_bullet(){

	for (int i = 0; i < asteroids->size(); i++) {
		
		float asteroidX, asteroidY, asteroidW, asteroidH;
		asteroidX = (*asteroids)[i]->get_posX();
		asteroidY = (*asteroids)[i]->get_posY();
		asteroidW = (*asteroids)[i]->get_width();
		asteroidH = (*asteroids)[i]->get_height();

		int life = (*asteroids)[i]->get_life();

		bool destroy = 0;
		
		for (int j = 0; j < bullets->size(); j++) {

			float bulletX = (*bullets)[j]->get_posX();
			float bulletY = (*bullets)[j]->get_posY();
			float bulletW = (*bullets)[j]->get_width();
			float bulletH = (*bullets)[j]->get_height();
			int bulletD = (*bullets)[j]->get_damage();
									
			if(collision(bulletX, bulletY, bulletW, bulletH, asteroidX, asteroidY, asteroidW, asteroidH)){

				// points for every bullet hit
				grid->set_score(BULLET_HIT);

				Bullet *b = (*bullets)[j];
        		bullets->erase(bullets->begin() + j);
        		delete b;
        		b = NULL;

        		(*asteroids)[i]->set_life(life - bulletD);

        		if(life - bulletD <= 0){
					destroy = 1;
					break;
				}	        	
			}								
		}//for
		//remove asteroid if life = 0
		if(destroy){			
			
			//points for destroying asteroid
			grid->set_score(ASTEROID_DESTROY);

			destroy = 0;			
			Asteroid *a = (*asteroids)[i];
    		asteroids->erase(asteroids->begin() + i);
    		delete a;
    		a = NULL;
		}				
	}//for

	//GAME OVER
	if(grid->get_score() < SHIP_COST && ships->size() == 0)
	{
		printf("You Lost!\nGAME OVER!\n");
		exit(0);
	}
}

void MyGameEngine::collision_asteroid_spaceship(){

	for (int i = 0; i < ships->size(); i++) {

		float shipX = (*ships)[i]->get_posX();
		float shipY = (*ships)[i]->get_posY();
		float shipW = (*ships)[i]->get_width();
		float shipH = (*ships)[i]->get_height();

		float asteroidX, asteroidY, asteroidW, asteroidH;
		bool collide = 0;

		for (int j = 0; j < asteroids->size(); j++) {

			asteroidX = (*asteroids)[j]->get_posX();
			asteroidY = (*asteroids)[j]->get_posY();
			asteroidW = (*asteroids)[j]->get_width();
			asteroidH = (*asteroids)[j]->get_height();

			if(collision(shipX, shipY, shipW, shipH, asteroidX, asteroidY, asteroidW, asteroidH)){
				Asteroid *t = (*asteroids)[j];
        		asteroids->erase(asteroids->begin() + j);
        		delete t;
        		t = NULL;

        		collide = 1;

        		break; //ship has to be removed, further collision should not happen with it
			}					
		}		
		if(collide){
			collide = 0;

			int height_grid = grid->get_height();
        	int width_grid = grid->get_width();        	

			shipX = (float)width_grid / 2.f * shipX + (float)width_grid / 2.f;
			shipY = -(float)height_grid / 2.f * shipY + (float)height_grid / 2.f;

			(*grid).mark_cell_asteroids(shipX, shipY, 0);//the cell should be available again
			//remove spaceship
			Spaceship *t = (*ships)[i];
    		ships->erase(ships->begin() + i);
    		delete t;
    		t = NULL;

    		//points awarded as the asteroid is destroyed [the ship is also lost]
    		grid->set_score(ASTEROID_DESTROY - 2 * SHIP_COST);
		}
	}
}

bool MyGameEngine::collision(float x1, float y1, float w1, float h1, 
    							float x2, float y2, float w2, float h2){

	if((x2 - x1 >= 0 && x2 - x1 <= w1) && ((y2 > y1 && (y2 - y1) < h1)
		|| (y2 <= y1 && (y1 - y2) < h2)))

		return 1;
	else 
		return 0;
}