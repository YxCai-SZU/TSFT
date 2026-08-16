#include <stdbool.h>

/*@
    predicate is_valid_x(integer x) = 1 <= x && x <= 10000;
    predicate reminder_in_range(integer x, integer r) = 0 <= r && r <= x;
    predicate reminder_mod_consistent(integer x, integer r) = r % 1000 == x % 1000;
    predicate result_nonnegative(integer res) = res >= 0;
    predicate result_upper_bound(integer res) = res < 1000;
    predicate result_zero_condition(integer x, integer res) = 
        res == 0 ==> x % 1000 == 0;
    predicate result_positive_condition(integer x, integer res) = 
        res > 0 ==> x % 1000 + res == 1000;
*/

/*@
    requires is_valid_x(x);
    ensures result_nonnegative(\result);
    ensures result_upper_bound(\result);
    ensures result_zero_condition(x, \result);
    ensures result_positive_condition(x, \result);
*/
int func(int x)
{
    int reminder;
    
    // Variable declarations at top
    reminder = x;
    
    // First loop: reduce reminder while >= 1000
    /*@
        loop invariant 1 <= x && x <= 10000;
        loop invariant 0 <= reminder && reminder <= x;
        loop invariant reminder % 1000 == x % 1000;
        loop assigns reminder;
        loop variant reminder;
    */
    while (reminder >= 1000)
    {
        //@ assert reminder >= 1000;
        reminder -= 1000;
    }
    
    // Second loop: increase reminder while < 0
    /*@
        loop invariant 1 <= x && x <= 10000;
        loop invariant reminder < 1000;
        loop invariant reminder % 1000 == x % 1000;
        loop assigns reminder;
        loop variant 1000 - reminder;
    */
    while (reminder < 0)
    {
        //@ assert reminder < 0;
        reminder += 1000;
    }
    
    // Final calculation
    if (reminder == 0)
    {
        //@ assert reminder == 0;
        //@ assert x % 1000 == 0;
        return 0;
    }
    else
    {
        int result = 1000 - reminder;
        //@ assert result > 0;
        //@ assert x % 1000 + result == 1000;
        return result;
    }
}
