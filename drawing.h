#include "constants.h"
#include "types.h"

void draw_grid(
    GridTile gird[defaults::Grid_Height * 2][defaults::Grid_Width],
    Turn current_turn,
    unsigned int discovered_mask[defaults::Grid_Height][defaults::Grid_Width]);
