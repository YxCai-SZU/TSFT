#include <stdbool.h>

/*@ predicate is_shichi_go_san(integer x) = 
      x == 3 || x == 5 || x == 7; */

/*@ requires 3 <= x <= 7;
    ensures \result == (x == 3 || x == 5 || x == 7);
    assigns \nothing;
 */
bool is_shichi_go_san(unsigned int x)
{
    //@ assert 3 <= x <= 7;
    return x == 3 || x == 5 || x == 7;
}
