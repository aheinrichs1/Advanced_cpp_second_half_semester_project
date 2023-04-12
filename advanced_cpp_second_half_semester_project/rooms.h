/*
 * Author Alec Smith
 * 3/29/23
 * ajsmith44@dmacc.edu
 */

#ifndef ROOMS_H
#define ROOMS_H
#include <array>
#include <iostream>
using namespace std;

class Rooms
{
protected:
    bool solved;

public:
    Rooms(){
        this->solved = false;
    }
    bool Puzzle(bool solved);
    void describeRoom();
    void end(bool solved){
        if(solved){
            cout << "The gaurd lets you pass and you exit the room \n \n";
        }else{
            cout << "door is locked";
        }
    }
    void doorUnlocked(bool solved){
        if(solved){
            cout << "You " << endl;
            end(solved);
        } else cout << "Door is locked" <<endl;
    }

    bool getSolved() const
    {
        return solved;
    }

    void setSolved(bool newSolved)
    {
        solved = newSolved;
    }
};

// subclass of Rooms class need to solve riddle to pass
class Riddle : virtual public Rooms
{
private:
    // variables for riddle
    string riddleText = "I am tall when I am young and I am short when I am old, what am I? \n";
    string riddleAnswer = "candle";
    string riddleArray[2][5] ={
    //riddles
    {"I am tall when I am young and I am short when I am old, what am I? \n",
     "What is always in front of you but cannot be seen \n",
     "What can you break, even if you never pick it up or touch it? \n",
     "What can you keep after giving to someone? \n",
     "The person who makes it has no need of it; the person who buys it has no use for it. The person who uses it can neither see nor feel it. What is it? \n",},
    //answers
    {"a candle",
     "the future",
     "a promise",
     "your word",
     "a coffin",}
    };
    static int InstanceCount;
public:

    //constructor
    Riddle(){
        InstanceCount++;
        if(InstanceCount > 5){
            throw invalid_argument("too many instances of Riddle class (Max 5)");
        }

        DescribeRoom();
        solved = Puzzle(riddleArray[0][InstanceCount -1],riddleArray[1][InstanceCount -1] ,solved);
        end(solved);
    }
    //helper methods

    // method that creates the room
    void DescribeRoom(){

        string wallOptions[] = {"it's bare", "is a torch", "is a gaurd blocking the door"};
        string roomString;
        string leftWall = wallOptions[(InstanceCount % 3)];
        string rightWall= wallOptions[((InstanceCount + 1) % 3)];
        string farWall= wallOptions[((InstanceCount + 2) % 3)];
        cout << "You enter a new room, on the right " + rightWall + ", on the left " + leftWall + " and across the room " + farWall << endl;
    }
    bool Puzzle(string riddle, string answer, bool solved){
        string userIn;
        solved = false;
        if(solved == false){
            cout << "\"you need to solve a riddle to get past\" says the gaurd \n";
            cout << riddle << endl;
            getline(cin,userIn);;
            while(userIn != answer){
                cout << "sorry try again \n";
                getline(cin,userIn);
            }
            cout << "\"that is correct!\" \n";
        }
        return true;
    }


};

int Riddle::InstanceCount = 0;
#endif // ROOMS_H
