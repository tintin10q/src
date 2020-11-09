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
    bool skip = false;
};


class Move {
private:
    Candy start;
    Candy end;
    int* map;
public:
    Move() = default;

// should we do map with this. or without it
    Move(Candy start_position, Candy end_postion, int map[]) {
        this->start = start_position;
        this->end = end_postion;
        this->map = map;
    }

    bool is_legal() {
        // implement is_legal() check all the things
        this->map[3];
        return false; }

};


vector<Move> getLegalMoves(int map[]) {
    int y = 0;
    int x_pos;
    int y_pos;
    vector<Move> legal_moves;
    for (int x = 0; x < 100; x++) {
        x_pos = x % 10;
        y_pos = y % 10;
        if (x_pos == 0 and x > 1) {
            cout << endl;
            y++;
        }
        // get x or y by doing % 10 like x % 10, get value with map[x]

        // if not on border
        if (x_pos < 9) {
            Move horizontal = Move({x_pos, y_pos, map[x]}, {x_pos + 1, y_pos, map[x + 1]}, map);
            if (horizontal.is_legal()) {
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

    cout << endl;
    cin >> y;

    return {};
}

class Bot {
public:
    Bot() = default;//initialise Bot class - constructor



    int *getNextMove(int map[], int nextMove[]);



};

int *Bot::getNextMove(int map[], int nextMove[]) //decide and return next move, given the current state of the map.
{
    vector<Move> legal_moves = getLegalMoves(map);
    nextMove[0] = 1;
    nextMove[1] = 2;
    nextMove[2] = 3;
    nextMove[3] = 4;

    return nextMove;
}


#endif /* SRC_BOT_H_ */
