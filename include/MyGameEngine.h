#include "Engine.h"
#include "Grid.h"
#include "Spaceship.h"
#include "Asteroid.h"
#include "Bullet.h"

class MyGameEngine : public GameEngine {

    Grid * grid;
    std::vector<Spaceship *> *ships;
    std::vector<Asteroid *> *asteroids;
    std::vector<Bullet *> *bullets;

public:
    MyGameEngine(Grid * grid_, std::vector<Spaceship *> *ships_, std::vector<Asteroid *> *asteroids_,
    			 std::vector<Bullet *> *bullets_):
	    grid(grid_),
	    ships(ships_),
	    asteroids(asteroids_),
	    bullets(bullets_)
    {}
    
    virtual void idle();

    void collision_asteroid_bullet();
    void collision_asteroid_spaceship();
    
    bool collision(float x1, float y1, float w1, float h1, 
    			float x2, float y2, float w2, float h2);
};
