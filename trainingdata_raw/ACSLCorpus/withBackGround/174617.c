#include <stdint.h>

/*@
    predicate is_valid_a(integer a) = 1 <= a && a <= 12;
    predicate is_valid_b(integer b) = 1 <= b && b <= 31;
    predicate condition_one(integer a, integer b) = a < 10 && b >= 10;
    predicate condition_two(integer a, integer b) = a > 9 && b >= a + 1;
    predicate condition_three(integer a, integer b) = a < 10 && b < 10;
    predicate condition_four(integer a, integer b) = a > 9 && b < a + 1;
*/

/*@
    requires is_valid_a(a) && is_valid_b(b);
    ensures \result == 1 || \result == 0;
    ensures \result == 1 ==> (condition_one(a, b) || condition_two(a, b));
    ensures \result == 0 ==> (condition_three(a, b) || condition_four(a, b));
*/
int32_t func(uint32_t a, uint32_t b)
{
    uint32_t ans;
    //@ assert is_valid_a(a) && is_valid_b(b);
    
    if (a < 10 && b >= 10) {
        ans = 1;
        //@ assert condition_one(a, b);
    } else if (a > 9 && b >= a + 1) {
        ans = 1;
        //@ assert condition_two(a, b);
    } else {
        ans = 0;
        //@ assert !condition_one(a, b) && !condition_two(a, b);
    }
    
    //@ assert ans == 1 ==> (condition_one(a, b) || condition_two(a, b));
    //@ assert ans == 0 ==> (condition_three(a, b) || condition_four(a, b));
    
    if (ans == 1) {
        return 1;
    } else {
        return 0;
    }
}
