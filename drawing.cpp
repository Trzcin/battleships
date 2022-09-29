#include "constants.h"
#include "types.h"
#include <iostream>
#include <string.h>

using std::cout;
using std::endl;

void draw_grid(
    GridTile grid[defaults::Grid_Height * 2][defaults::Grid_Width],
    Turn current_turn,
    unsigned int discovered_mask[defaults::Grid_Height][defaults::Grid_Width])
{
    // clear console
    cout << "\033[2J\033[1;1H";

    for (int i = 0; i < defaults::Top_Margin; i++) {
        cout << endl;
    }

    // first line/top boarder
    char h_border[defaults::Left_Margin + defaults::Grid_Width*5 + 2*5 + 1];
    //for (int i = 0; i < defaults::Left_Margin; i++) {
        //h_border[i] = ' ';
    //}
    strcat(h_border, "\t");
    for (int i = defaults::Left_Margin; i < defaults::Left_Margin + defaults::Grid_Width + 2; i++) {
        strcat(h_border, symbols::border);
    }
    cout << h_border << endl;

    for (int i = 0; i < 2; i++) {
        for (int y = 0; y < defaults::Grid_Height; y++) {
            char line_buffer[defaults::Left_Margin + defaults::Grid_Width*5 + 2*5 + 1] {};

            //for (int j = 0; j < defaults::Left_Margin; j++) {
                //line_buffer[j] = ' ';
            //}
            strcat(line_buffer, "\t");
            strcat(line_buffer, symbols::border);
            for (int x = 0; x < defaults::Grid_Width; x++) {
                // should draw unknown teritiory
                if ((current_turn == Turn::A && i == 1) || (current_turn == Turn::B && i == 0)) {
                    switch (discovered_mask[y][x]) {
                        case 0:
                            strcat(line_buffer, symbols::cloud);
                            break;
                        case 1:
                            strcat(line_buffer, symbols::water);
                            break;
                        case 2:
                            strcat(line_buffer, symbols::explosion);
                            break;
                    }
                    continue;
                }

                // known teritory
                int realY = i * defaults::Grid_Height + y;
                if (grid[realY][x].empty) {
                    strcat(line_buffer, symbols::water);
                } else if (grid[realY][x].damaged) {
                    strcat(line_buffer, symbols::explosion);
                } else {
                    strcat(line_buffer, symbols::ship);
                }
            }
            strcat(line_buffer, symbols::border);
            cout << line_buffer << endl;
        }

        // bottom border
        cout << h_border << endl;
    }
}
