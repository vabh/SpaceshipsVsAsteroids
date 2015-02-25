#pragma once
#include "GraphicPrimitives.h"

#define SHIP_COST 30
#define ASTEROID_COST 40
#define BULLET_HIT 10
#define ASTEROID_DESTROY 50

class Grid {

	int width_grid, height_grid;
	int rows;
	int columns;
	float col_distance;
	float row_distance;

	float r, g, b;

	int **grid_asteroids;

	int difficulty;
    int score;

    int ship_type;

public:
    Grid(int rows_ = 1, int columns_ = 10, float c_ = 0.3f);
    ~Grid();

    void draw();

    void set_dimension(int w, int h);
    int get_width();
    int get_height();
    int get_rows();
    int get_columns();
    float get_row_distance();
    float get_col_distance();

    void mark_cell_asteroids(int x, int y, int v);
    bool cell_marked_asteroids(int x, int y);

    int get_difficulty();
    void set_difficulty(int d);

    void set_ship_type(int t);
    int get_ship_type();

    int get_score();
    void set_score(int s);
};