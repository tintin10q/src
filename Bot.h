#ifndef SRC_BOT_H_
#define SRC_BOT_H_

#include <vector>
#include "lib_std_facilities.h"


const int map_height = 9;
const int map_lenght = 100;

int map_version(const int x, int y) {
    return y * 10 + x;
}

struct Candy {

    int x{};
    int y{};
    int data{};
};


class Move {
private:
    Candy start;
    Candy end;
    int *map;
public:
    Move() = default;

    Move(int x1, int y1, int x2, int y2);

// should we do map with this. or without it
    Move(Candy start_position, Candy end_postion, int map[]) {
        this->start = start_position;
        this->end = end_postion;
    }

    bool is_legal() {
        // implement is_legal() check all the things
        this->map[3];
        return false;
    }

};

Move::Move(int x1, int y1, int x2, int y2) {

}

class Bot {
public:
    Bot() = default;//initialise Bot class - constructor
    bool is_legal_H(int x1, int y1, int x2, int y2);

    bool is_legal_V(int x1, int y1, int x2, int y2);

    vector<Move> getLegalMoves();


    int *getNextMove(int map[], int nextMove[]);

    void turn_map_2d(const int map[]) {
        for (int i = 0; i < 100; i++) {
            this->myMap[i / 10][i % 10] = map[i];
        }
    }

private:
    int myMap[10][10];


};


bool Bot::is_legal_H(int x1, int y1, int x2, int y2) {
    return true;
};

bool Bot::is_legal_V(int x1, int y1, int x2, int y2) {
    return true;
}

vector<Move> Bot::getLegalMoves() {
    cout << this->myMap;
    vector<Move> legal_moves;
    for (int x = 0; x < 10; x++) {
        for (int y = 0; y < 10; y++) {
            // if not on border
            if (x < 9) { // This is dum, just check with the numbers first and then make the move object
                if (is_legal_H(x, y, x + 1, y)) {
                    Move horizontal = Move({x, y}, {x + 1, y});
                    legal_moves.push_back(horizontal);
                }
            }

            if (y_pos < 9) {
                Move vertical = Move({x_pos, y_pos, map[x]}, {x_pos, y_pos + 1, map[map_version(x, y + 1)]}, map);
                if (vertical.is_legal()) {
                    legal_moves.push_back(vertical);
                }
            }
        }
    }

}


/


int *Bot::getNextMove(int map[], int nextMove[]) //decide and return next move, given the current state of the map.
{
    turn_map_2d(map);
    vector<Move> legal_moves = getLegalMoves();
    nextMove[0] = 1;
    nextMove[1] = 2;
    nextMove[2] = 3;
    nextMove[3] = 4;

    return nextMove;
}


#endif /* SRC_BOT_H_ */
