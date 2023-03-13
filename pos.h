//
// Created by Cata on 5/24/2022.
//

#ifndef PINGPONG_POS_H
#define PINGPONG_POS_H

struct pos {
    double x, y;

    pos& operator=(const pos &other) {
        x = other.x;
        y = other.y;
        return *this;
    }

    pos& operator+=(const pos &other) {
        x += other.x;
        y += other.y;
        return *this;
    }

    pos operator*(float speed) {
        return pos({x * speed, y * speed});
    }
};

#endif //PINGPONG_POS_H
