#include <iostream>
#include "drawing.h"
using std::cout;
using std::endl;

// discovered mask:
// 0 - unknown enemy tile
// 1 - discovered empty enemy tile
// 2 - tile discovered by damaging a ship
struct PlayerState {
    int available_ships[4] {1, 2, 3, 4};
    Ship placed_ships[10];
    int healthy_fragments {20};
    unsigned int discovered_mask[defaults::Grid_Height][defaults::Grid_Width] {};
    bool can_shoot {false};
};

int main() {
    // app state
    GridTile grid[defaults::Grid_Height*2][defaults::Grid_Width] {};
    PlayerState playerA_state;
    PlayerState playerB_state;
    Turn current_turn {A};

    draw_grid(grid, current_turn, playerA_state.discovered_mask);

    cout << endl;
    cout << "\033[32;1m" << "Player " << ((current_turn == Turn::A) ? "A" : "B") << "\033[0m" << "  Please type in your commands below:" << endl;
    cout << "> ";
    char command[50];
    fgets(command, 50, stdin);
    cout << command << endl;

    return 0;
}
