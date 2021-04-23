#ifndef PLAYER_H
#define PLAYER_H

//#include "Arena.h" // Still does not work and idk lol

#include <string> // FAILED: Player.h must not contain any #include line that, if removed, still allows the above replacement main.cpp to compile successfully under both g32and either Visual C++ or clang++.


class Arena; // Added this and somehow worked after adding Player.cpp

class Player
{
public:
    // Constructor
    Player(Arena* ap, int r, int c);

    // Accessors
    int  row() const;
    int  col() const;
    int  age() const;
    bool isDead() const;

    // Mutators
    std::string takeComputerChosenTurn();
    void   stand();
    void   move(int dir);
    bool   shoot(int dir);
    void   setDead();

private:
    Arena* m_arena;
    int    m_row;
    int    m_col;
    int    m_age;
    bool   m_dead;

    int    computeDanger(int r, int c) const;
};

#endif