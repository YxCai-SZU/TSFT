#include <stdbool.h>

/*@ predicate valid_grid(int (*grid)[3]) =
    \forall integer i, j; 0 <= i < 2 && 0 <= j < 3 ==> 
        1 <= grid[i][j] && grid[i][j] <= 9;
*/

/*@ predicate rotationally_symmetric(int (*grid)[3]) =
    grid[0][0] == grid[1][2] && 
    grid[0][1] == grid[1][1] && 
    grid[0][2] == grid[1][0];
*/

/*@ lemma reverse_correctness:
    \forall int (*grid)[3];
        rotationally_symmetric(grid) ==>
        grid[0][0] == grid[1][2] && grid[0][1] == grid[1][1] && grid[0][2] == grid[1][0];
*/

/*@ requires valid_grid(grid);
    ensures \result <==> rotationally_symmetric(grid);
*/
bool is_rotationally_symmetric(int (*grid)[3])
{
    int row1[3];
    int row2[3];
    int reversed_row2[3];
    bool result;
    
    // Copy rows
    row1[0] = grid[0][0];
    row1[1] = grid[0][1];
    row1[2] = grid[0][2];
    
    row2[0] = grid[1][0];
    row2[1] = grid[1][1];
    row2[2] = grid[1][2];
    
    // Reverse row2
    reversed_row2[0] = row2[2];
    reversed_row2[1] = row2[1];
    reversed_row2[2] = row2[0];
    
    // Compare elements
    result = (row1[0] == reversed_row2[0] && 
              row1[1] == reversed_row2[1] && 
              row1[2] == reversed_row2[2]);
    
    //@ assert result == (grid[0][0] == grid[1][2] && grid[0][1] == grid[1][1] && grid[0][2] == grid[1][0]);
    
    return result;
}
