struct Point {
    int x {0};
    int y {0};
};

enum Direction {UP, RIGHT, DOWN, LEFT};

struct Ship {
    Point pos;
    Direction dir {RIGHT};
    int healthy_fragments {5};
};

struct GridTile {
    bool empty {true};
    unsigned int ship_index {0};
    bool damaged {false};
};

enum Turn {A, B};
