#include "MyControlEngine.h"
#include "GraphicPrimitives.h"

void MyControlEngine::MouseCallback(int button, int state, int x, int y){

	//new spaceship, if points are available!
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN && grid->get_score() - SHIP_COST >= 0) {     
    	
    	if(!(*grid).cell_marked_asteroids(x, y)){
        	(*grid).mark_cell_asteroids(x, y, 1);

        	int height_grid = grid->get_height();
        	int width_grid = grid->get_width();

        	int r = y / (height_grid / (*grid).get_rows()); // row number
			int c = x / (width_grid / (*grid).get_columns());// col number
			float boundary_c = c * (*grid).get_col_distance() + (*grid).get_col_distance();
			float boundary_r = r * (*grid).get_row_distance();// +(*grid).get_row_distance();
															  // matching with upper boundary	
			boundary_r = (boundary_r - 1.0f) * -1.f;
			boundary_c -= 1.0f;

			float posX = (x - (float)width_grid / 2) / ((float)width_grid / 2.f);
			float posY = (y - (float)height_grid / 2) / ((float)height_grid / -2.f);

			int type = grid->get_ship_type();
        	ships->push_back(new Spaceship(posX, posY, boundary_r, boundary_c, (*grid).get_row_distance(), type));

        	//reduce score for placing ship
        	grid->set_score(-SHIP_COST);
    	}
    }

    //test method
  //   if(button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN) { 
  //   	int height_grid = grid->get_height();   	   			
		// //asteroids->push_back(new Asteroid(1.f, (y - 300) / -300.f));
		// asteroids->push_back(new Asteroid(1.f, (y - height_grid / 2.f) / -(height_grid / 2.f), 0.f));		
  //   }
}

void MyControlEngine::KeyboardCallback(unsigned char key, int x, int y){

	// new wave, launched only if current wave is over
	// activated by spacebar
	if(key == ' ' && asteroids->size() == 0){

		// fetch the difficulty level and increase it
		int difficulty = grid->get_difficulty() + 1;
		if(difficulty > 16)
			grid->set_difficulty(difficulty + 1);
		else
			grid->set_difficulty(difficulty * 2);

		int num_asteroids = get_random_number(1, difficulty);
		float posX = 1.f;

		//need to make it intelligent depending on difficulty
		for(int i = 0; i < num_asteroids; i++){
			float posY = (float)get_random_number(0, 200) / 100 - 1.0f ;
			float speedY = 0.f;

			int direction = (i % 2) == 0 ? -1 : 1;			
			if(difficulty > 16)
				speedY = 0.004 * ((i % 2) == 0 ? -1 : 1);

			asteroids->push_back(new Asteroid(posX, posY, speedY));
		}
	}

	//set spcaeship type
	if(key == '1' || key == '2' || key == '3'){
		grid->set_ship_type((int)(key - '0'));
	}

	//force quit the game
	if(key == 'e' || key == 'E'){
		printf("\nThank you for playing.\n");
		exit(0);
	}
}

int MyControlEngine::get_random_number(int a, int b){

	std::random_device rd;
	std::default_random_engine e1(rd());
    std::uniform_int_distribution<int> uniform_dist(a, b);	
    return uniform_dist(e1);
}