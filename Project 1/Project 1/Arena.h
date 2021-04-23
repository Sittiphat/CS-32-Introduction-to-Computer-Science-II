#ifndef ARENA_H
#define ARENA_H

#include "globals.h"
#include "Player.h" // Arena.h must not contain any #include line that, if removed, still allows the above replacement main.cpp
//#include "Robot.h" // Replaced this with signature, so only this works?

#include "Previous.h"

class Robot; // Added this and somehow worked after adding Player.cpp


class Arena
{
public:
    // Constructor/destructor
    Arena(int nRows, int nCols);
    ~Arena();

    // Accessors
    int     rows() const;
    int     cols() const;
    Player* player() const;
    int     robotCount() const;
    int     nRobotsAt(int r, int c) const;
    void    display(std::string msg) const;
    Previous& thePrevious();

    // Mutators
    bool   addRobot(int r, int c);
    bool   addPlayer(int r, int c);
    void   damageRobotAt(int r, int c);
    bool   moveRobots();

private:
    Previous m_previous;
    int     m_rows;
    int     m_cols;
    Player* m_player;
    Robot* m_robots[MAXROBOTS];
    int     m_nRobots;
};

#endif