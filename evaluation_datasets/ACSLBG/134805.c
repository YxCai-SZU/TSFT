#include <limits.h>

/*@
    predicate is_valid_params(integer x, integer y) =
        1 <= x <= 100 &&
        1 <= y <= 100 &&
        y % 2 == 0;

    logic integer half_y(integer y) = y / 2;

    lemma half_y_times_two:
        \forall integer x, y; is_valid_params(x, y) ==> half_y(y) * 2 == y;
*/


int func(int x, int y) {
    int half_y;
    int count;
    int temp_y;

    // Positive branch
    if (y >= 0) {
        count = 0;
        temp_y = y;
        
        while (temp_y >= 2) {
            temp_y -= 2;
            count += 1;
        }
        half_y = count;
    } else {
        // Negative branch (not reachable due to preconditions)
        count = 0;
        temp_y = y;
        
        while (temp_y <= -2) {
            temp_y += 2;
            count -= 1;
        }
        half_y = count;
    }

    //@ assert half_y * 2 == y;
    //@ assert x + half_y <= 150;

    return x + half_y;
}
