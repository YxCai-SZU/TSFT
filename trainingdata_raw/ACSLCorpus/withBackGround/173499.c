#include <limits.h>

/*@
    predicate is_valid_params(integer x, integer y) =
        1 <= x <= 100 &&
        1 <= y <= 100 &&
        y % 2 == 0;
*/

/*@
    logic integer half_y_logic(integer y) = y / 2;
*/

/*@
    lemma half_y_property:
        \forall integer x, integer y; is_valid_params(x, y) ==> half_y_logic(y) == y / 2;
*/

/*@
    requires is_valid_params(x, y);
    ensures \result == x + (y / 2);
    assigns \nothing;
*/
int func(int x, int y) {
    int half_y;
    int count;
    int temp_y;
    
    if (y >= 0) {
        count = 0;
        temp_y = y;
        /*@
            loop invariant 0 <= temp_y <= y;
            loop invariant 0 <= count <= y / 2;
            loop invariant temp_y == y - 2 * count;
            loop assigns count, temp_y;
            loop variant temp_y;
        */
        while (temp_y >= 2) {
            //@ assert temp_y >= 2;
            count += 1;
            temp_y -= 2;
        }
        half_y = count;
    } else {
        count = 0;
        temp_y = y;
        /*@
            loop invariant y <= temp_y <= 0;
            loop invariant -y / 2 <= count <= 0;
            loop invariant temp_y == y - 2 * count;
            loop assigns count, temp_y;
            loop variant -temp_y;
        */
        while (temp_y <= -2) {
            //@ assert temp_y <= -2;
            count -= 1;
            temp_y += 2;
        }
        half_y = count;
    }
    
    //@ assert half_y == y / 2;
    int result = x + half_y;
    //@ assert result == x + (y / 2);
    return result;
}
