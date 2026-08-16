#include <stdbool.h>

/*@
    requires \valid(grid+(0..1));
    requires ((grid)[0][0] == (grid)[1][2] &&
    (grid)[0][2] == (grid)[1][0] &&
    (grid)[0][1] == (grid)[1][1] &&
    (grid)[0][0] <= 9 &&
    (grid)[0][1] <= 9 &&
    (grid)[0][2] <= 9);
    ensures \result == (grid[0][0] < 10 && grid[0][1] < 10 && grid[0][2] < 10);
    assigns \nothing;
*/
bool is_rotationally_symmetric_func(unsigned char grid[2][3])
{
    bool v1;
    bool v2;
    bool result;

    //@ assert grid[0][0] == grid[1][2];
    //@ assert grid[0][2] == grid[1][0];
    //@ assert grid[0][1] == grid[1][1];

    v1 = (grid[0][0] < 10) && (grid[0][1] < 10) && (grid[0][2] < 10);
    v2 = (grid[1][0] < 10) && (grid[1][1] < 10) && (grid[1][2] < 10);

    //@ assert v1 == v2;

    result = v1 && v2;
    return result;
}
