#include "Grid.h"

Grid::Grid(int rows_, int columns_, float c_): rows(rows_), columns(columns_) {
	row_distance = 2.0f / rows_;
	col_distance = 2.0f / columns_;
 
	width_grid = 800;
	height_grid = 600;

	r = g = b = c_;

	difficulty = 0;
	score = 100;

	ship_type = 1;

	//monitor grid cells
	grid_asteroids = new int* [rows];
	for(int i = 0; i < rows; ++i)
		grid_asteroids[i] = new int[columns];

	for(int i = 0; i < rows; i++){
		for(int j = 0; j < columns; j++)
			grid_asteroids[i][j] = 0;	
	}
}

Grid::~Grid()
{
	for(int i = 0; i < rows; ++i)
		delete[] grid_asteroids[i];

	delete[] grid_asteroids;
}

void Grid::set_dimension(int w, int h){
	width_grid = w;
	height_grid = h;
}

int Grid::get_width(){
	return width_grid;
}

int Grid::get_height(){
	return height_grid;
}

int Grid::get_rows(){
	return rows;
}

int Grid::get_columns(){
	return columns;
}

float Grid::get_row_distance(){
	return row_distance;
}

float Grid::get_col_distance(){
	return col_distance;
}	

void Grid::mark_cell_asteroids(int x, int y, int v) {
	int r = y / (height_grid / rows);
	int c = x / (width_grid / columns);
	grid_asteroids[r][c] = v;
}

bool Grid::cell_marked_asteroids(int x, int y){
	int r = y / (height_grid / rows);
	int c = x / (width_grid / columns);

	return grid_asteroids[r][c];

}

int Grid::get_difficulty(){
	return difficulty;
}

void Grid::set_difficulty(int d){
	difficulty = d;
}

void Grid::set_ship_type(int t){
	ship_type = t;
}

int Grid::get_ship_type(){
	return ship_type;
}

int Grid::get_score(){
	return score;
}

void Grid::set_score(int s){
	score += s;
}

void Grid::draw() {

	// halo background for the baord
	for(float i = 0; i <= 2.0f; i+= 0.2f){            
        for(float j = 0; j <= 2.0f; j+= 0.5f){
           GraphicPrimitives::drawLine2D(i-1.f, -j, -i+1.f, j, 0.0f, 0.6f, 0.7f);
	    }        
    }

    //grid columns
    float xC = -1.0f;
    for(int i = 1 ; i < get_columns(); i++){
        xC += col_distance;
        GraphicPrimitives::drawLine2D(xC, 1.0f, xC, -1.0f, r, g, b);
    }
    //grid rows
    float yC = -1.0f;//drawing is being done from the bottom to the top
    for(int i = 1 ; i < get_rows(); i++){
        yC += row_distance;
        GraphicPrimitives::drawLine2D(-1.0f, yC, 1.0f, yC, r, g, b);
    }
}