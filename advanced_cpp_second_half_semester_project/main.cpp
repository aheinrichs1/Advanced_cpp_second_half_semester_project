#include "roomA.h"
#include "PuzzleRoom.h"
#include "battleRoom.h"
#include "rooms.h"
#include <iostream>

int main()
{
    PuzzleRoom room = PuzzleRoom();
    Rooms r = Riddle();
    roomAMain();

    battleRoomMain();
    roomAMain();
    return 0;
}
