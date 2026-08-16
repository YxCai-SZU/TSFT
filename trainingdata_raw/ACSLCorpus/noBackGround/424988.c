#include <stdbool.h>

/*@ requires grid[0][0] == grid[1][2] &&
             grid[0][1] == grid[1][1] &&
             grid[0][2] == grid[1][0] &&
             grid[0][0] <= 127 &&
             grid[0][1] <= 127 &&
             grid[0][2] <= 127;
    ensures \result == \true;
*/
bool is_rotationally_symmetric(unsigned char grid[2][3])
{
    //@ assert grid[0][0] == grid[1][2];
    return true;
}
