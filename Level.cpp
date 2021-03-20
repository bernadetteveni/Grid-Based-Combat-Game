//
//  Level.cpp
//  Bernadette Veninata
//  SID: 200259971
//
//  Implementation of the Level type

#include <cassert>
#include <cstdlib>
#include <string>
#include <fstream>
#include <iostream>
#include <iomanip>
using namespace std;

#include "Level.h"

const unsigned int TERRAIN_COUNT = 9;
const char INPUT_TERRAIN_TYPE[TERRAIN_COUNT] =
{
	'.', // EMPTY
	'^', // ROCKY
	':', // ROUGH
	'#', // WALL
	'P', // PLAYER_START
	'*', // PLAYER_GOAL
	'S', // MONSTER_START
	'A', // ATTACKER_START
	'D', // DRONE_START
};

const char OUTPUT_TERRAIN_TYPE[TERRAIN_COUNT] =
{
	' ', // EMPTY 
	'^', // ROCKY
	':', // ROUGH
	'#', // WALL
	' ', // PLAYER_START
	'*', // PLAYER_GOAL
	' ', // MONSTER_START
	' ', // ATTACKER_START
	' ', // DRONE_START
};

const unsigned int TRAVERSAL_COST[TERRAIN_COUNT] =
{
	1,  // EMPTY
	2,  // ROCKY
	4,  // ROUGH
	1000, // WALL
	1,  // PLAYER_START
	1,  // PLAYER_GOAL
	1,  // MONSTER_START
	1,  // ATTACKER_START
	1,  // DRONE_START
};



Level :: Level ()
		: monster_count(0)
{
	for (int r = 0; r < ROWS; r++)
		for (int c = 0; c < COLUMNS; c++)
			terrain[r][c] = EMPTY;
	terrain[0][0] = PLAYER_START;
}

Level :: Level (const string& file_name)
		: monster_count(0)
{
	ifstream in(file_name.c_str());

	if (!in)
	{
		cout << "Error: Cannot read from file named " << file_name << endl;
		exit(1);  // terminate program immediately
	}

	for (int r = 0; in && (r < ROWS); r++)
	{
		for (int c = 0; in && (c < COLUMNS); c++)
		{
			char next_char;
			in >> next_char;

			bool is_input_valid = false;
			for (unsigned int t = 0; t < TERRAIN_COUNT; t++)
			{
				if (next_char == INPUT_TERRAIN_TYPE[t])
				{
					terrain[r][c] = t;
					is_input_valid = true;
				}
			}
			
			if (is_input_valid)
			{
				switch(terrain[r][c])
				{
				case SENTRY_START:
					monster_count++;
					break;
                case ATTACKER_START:
                    monster_count++;
                    break;
                case DRONE_START:
                    monster_count++;
                    break;
				}
			}
			else
			{
				cout	<< "Error: Invalid input at row " << r << ", column " << c
						<< ", substituted empty terrain" << endl;
				terrain[r][c] = EMPTY;
			}
		}
	}
}


Level::Level (const Level& original)
:monster_count(original.getMonsterCount())
{
    for(int i = 0; i<ROWS; i++){
        for(int j = 0; j < COLUMNS; j++){
            terrain[i][j] = original.getValue(toPosition(i, j));
        }
    }
}

Level::~Level (){
//empty
}

Level& Level::operator= (const Level& original){
    if(&original != this){
        monster_count = original.getMonsterCount();
        for(int i = 0; i<ROWS; i++){
            for(int j = 0; j < COLUMNS; j++){
                terrain[i][j] = original.getValue(toPosition(i, j));
            }
        }
    }
    return *this;
}

//Position Level :: getMonsterStart () const
//{
//    for (int r = 0; r < ROWS; r++)
//        for (int c = 0; c < COLUMNS; c++)
//            if (terrain[r][c] == MONSTER_START)
//                return toPosition(r, c);
//
//    // default: return upper left corner if not found
//    return toPosition(0, 0);
//}

Position Level :: getPlayerStart () const
{
	for (int r = 0; r < ROWS; r++)
		for (int c = 0; c < COLUMNS; c++)
			if (terrain[r][c] == PLAYER_START)
				return toPosition(r, c);

	// default: return upper left corner if not found
	return toPosition(0, 0);
}

unsigned int Level :: getMonsterCount () const
{
	return monster_count;
}

unsigned int Level :: getValue (const Position& position) const
{
	assert(isValid(position));

	return terrain[position.row][position.column];
}

unsigned int Level :: getCost (const Position& position) const
{
	assert(isValid(position));

	unsigned int t = terrain[position.row][position.column];
	assert(t < TERRAIN_COUNT);
	return TRAVERSAL_COST[t];
}

void Level :: printAtPosition (const Position& position) const
{
	assert(isValid(position));

	unsigned int t = terrain[position.row][position.column];
	assert(t < TERRAIN_COUNT);
	cout << OUTPUT_TERRAIN_TYPE[t];
}

bool Level :: isWall (const Position& position) const
{
	assert(isValid(position));

	if(terrain[position.row][position.column] == WALL)
		return true;
	else
		return false;
}

bool Level :: isGoalPosition (const Position& position) const
{
	assert(isValid(position));

	if(terrain[position.row][position.column] == PLAYER_GOAL)
		return true;
	else
		return false;
}

