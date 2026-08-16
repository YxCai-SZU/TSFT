#include <stdbool.h>

/*@
    requires (\valid((grid)) && \valid((grid)[0]) && \valid((grid)[1]) &&
        \valid((grid)[0] + (0..2)) && \valid((grid)[1] + (0..2)) &&
        (\forall integer i, j; 0 <= i <= 1 && 0 <= j <= 2 ==>
            '0' <= (grid)[i][j] && (grid)[i][j] <= '9'));
    ensures ((\result) == ((grid)[0][0] == (grid)[1][2] &&
                   (grid)[0][1] == (grid)[1][1] &&
                   (grid)[0][2] == (grid)[1][0]));
    assigns \nothing;
*/
bool is_rotationally_symmetric(char **grid)
{
    //@ assert \valid(grid) && \valid(grid[0]) && \valid(grid[1]);
    //@ assert \valid(grid[0] + (0..2)) && \valid(grid[1] + (0..2));
    //@ assert \forall integer i, j; 0 <= i <= 1 && 0 <= j <= 2 ==> '0' <= grid[i][j] && grid[i][j] <= '9';
    
    bool result;
    result = (grid[0][0] == grid[1][2] && 
              grid[0][1] == grid[1][1] && 
              grid[0][2] == grid[1][0]);
    
    //@ assert ((result) == ((grid)[0][0] == (grid)[1][2] &&                    (grid)[0][1] == (grid)[1][1] &&                    (grid)[0][2] == (grid)[1][0]));
    return result;
}
