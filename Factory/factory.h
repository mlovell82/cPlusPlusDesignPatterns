#pragma once
enum Direction { north, east, south, west };
class MapSite {
public:
	virtual void Enter() = 0;
};

class Room : public MapSite {
public:
	Room() {};

	Room(int roomNo) {
		_roomNumber = roomNo;
	};

	MapSite* GetSide(Direction) const {};

	void SetSide(Direction, MapSite*) {};

	virtual void Enter() {};

private:
	MapSite * _sides[4];
	int _roomNumber;
};

class Wall : public MapSite {
public:
	Wall();

	virtual void Enter();
};

class Door : public MapSite {
public:
	Door(Room* = 0, Room* = 0);

	virtual void Enter();

	Room* OtherSideFrom(Room*);

private:
	Room* _room1;
	Room* _room2;
	bool _isOpen;
};

class Maze {
public:
	Maze();

	void AddRoom(Room*);

	Room* RoomNo(int) const;

private:
	// ...
};

class MazeFactory
{
public:
	MazeFactory();
	~MazeFactory();
	
	virtual Maze* MakeMaze() const {
		return new Maze;
	}

	virtual Wall* MakeWall() const {
		return new Wall;
	}

	virtual Room* MakeRoom() const {
		return new Room;
	}

	virtual Door* MakeDoor() const {
		return new Door;
	}

};

class MazeGame{
	MazeGame() {};
	Maze* CreateMaze(MazeFactory& factory);
};
