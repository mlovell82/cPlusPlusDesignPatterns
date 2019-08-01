#include "Class.h"




Maze* MazeGame::CreateMaze(MazeFactory& factory) {
	Maze* aMaze = factory.MakeMaze();
	Room* r1 = factory.MakeRoom(1);
	Room* r2 = factory.MakeRoom(2);
	Door* aDoor = factory.MakeDoor(r1, r2);

	aMaze->AddRoom(r1);
	aMaze->AddRoom(r2);

	r1->SetSide(north, factory.MakeWall());
	r1->SetSide(east, aDoor);
	r1->SetSide(south, factory.MakeWall());
	r1->SetSide(west, factory.MakeWall());

	r2->SetSide(north, factory.MakeWall());
	r2->SetSide(east, factory.MakeWall());
	r2->SetSide(south, factory.MakeWall());
	r2->SetSide(west, aDoor);

	return aMaze;
}


Class::~Class()
{
}
