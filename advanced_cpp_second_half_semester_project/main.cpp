#include "roomA.h"
#include "PuzzleRoom.h"
#include "battleRoom.h"
#include "rooms.h"
#include <iostream>

int main()
{
    Rooms r = Riddle();
    roomAMain();
    PuzzleRoom room = PuzzleRoom();
    battleRoomMain();
    roomAMain();
}
