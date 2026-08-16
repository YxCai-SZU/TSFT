#include <stdbool.h>

/*@ predicate in_range(integer x) = -40 <= x <= 40; */
/*@ predicate is_yes(integer x) = x >= 30; */

/*@ lemma range_split: 
      \forall integer x; in_range(x) ==> (x >= 30 || x < 30); */

/*@ requires in_range(x);
    ensures \result == (x >= 30);
    assigns \nothing;
 */
bool func(int x)
{
    //@ assert in_range(x);
    if (x >= 30) {
        //@ assert x >= 30;
        return true;
    } else {
        //@ assert x < 30;
        return false;
    }
}

/*@ requires in_range(x);
    ensures \result == (x >= 30);
    assigns \nothing;
 */
bool func_isolation(int x)
{
    //@ assert in_range(x);
    //@ assert -40 <= x && x <= 40;
    if (x >= 30) {
        //@ assert x >= 30;
        return true;
    } else {
        //@ assert x < 30;
        return false;
    }
}

/*@ requires in_range(x);
    assigns \nothing;
 */
void assert_isolation(int x)
{
    //@ assert -40 <= x && x <= 40;
}
