#include <stdbool.h>

/*@
    predicate x_lt_y(integer x, integer y) = x < y;
    predicate result_lt(integer x, integer y) = x + 2 < y + 3;
*/

/*@
    requires x_lt_y(x, y);
    ensures result_lt(x, y);
    assigns \nothing;
*/
void test_proof(int x, int y) {
    // Variable declarations at top of scope
    int temp_x = x;
    int temp_y = y;
    
    //@ assert temp_x < temp_y;
    //@ assert temp_x + 2 < temp_y + 3;
}
