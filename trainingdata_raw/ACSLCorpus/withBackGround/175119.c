#include <stdbool.h>

/*@
    predicate condition_one(integer a, integer b, integer c, integer d) =
        c <= b && a + b <= d;

    predicate condition_two(integer a, integer b, integer c, integer d) =
        c <= a && a + b <= d;

    predicate condition_three(integer a, integer b, integer c, integer d) =
        c > b && c <= a + b && a + b <= d;

    lemma addition_bound: \forall integer a, b; 1 <= a <= 10000 && 1 <= b <= 10000 ==> a + b <= 20000;
*/

/*@
    requires 1 <= a <= 10000;
    requires 1 <= b <= 10000;
    requires 1 <= c <= 10000;
    requires 1 <= d <= 10000;
    ensures \result == (c <= b && a + b <= d) || (c <= a && a + b <= d) || (c > b && c <= a + b && a + b <= d);
*/
bool func(unsigned int a, unsigned int b, unsigned int c, unsigned int d)
{
    // Variable declarations at the top
    bool result;

    //@ assert a + b <= 20000;

    if (c <= b && a + b <= d)
    {
        //@ assert condition_one(a, b, c, d);
        result = true;
    }
    else if (c <= a && a + b <= d)
    {
        //@ assert condition_two(a, b, c, d);
        result = true;
    }
    else if (c > b && c <= a + b && a + b <= d)
    {
        //@ assert condition_three(a, b, c, d);
        result = true;
    }
    else
    {
        //@ assert !condition_one(a, b, c, d) && !condition_two(a, b, c, d) && !condition_three(a, b, c, d);
        result = false;
    }

    return result;
}
