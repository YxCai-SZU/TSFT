#include <stdbool.h>
#include <stddef.h>

/*@
    requires \valid(grid) && \valid(grid[0]) && \valid(grid[1]);
    requires \valid(grid[0] + (0..2)) && \valid(grid[1] + (0..2));
    ensures ((\result) <==> (
            (grid)[0][0] == (grid)[1][2] &&
            (grid)[0][2] == (grid)[1][0] &&
            (grid)[0][1] == (grid)[1][1]
        ));
    assigns \nothing;
*/
bool is_rotationally_symmetric(int **grid)
{
    //@ assert \valid(grid[0] + (0..2));
    //@ assert \valid(grid[1] + (0..2));
    
    bool result;
    result = (grid[0][0] == grid[1][2]) && 
             (grid[0][2] == grid[1][0]) && 
             (grid[0][1] == grid[1][1]);
    
    //@ assert ((result) <==> (             (grid)[0][0] == (grid)[1][2] &&             (grid)[0][2] == (grid)[1][0] &&             (grid)[0][1] == (grid)[1][1]         ));
    return result;
}
