#include <stdbool.h>

/*@ predicate is_in_range(integer x) = 1 <= x && x <= 100000; */

/*@ logic integer div_100(integer x) = x / 100; */

/*@ lemma div_100_identity: 
      \forall integer x; is_in_range(x) ==> div_100(x) * 100 / 100 == div_100(x); */

/*@ requires is_in_range(x);
    ensures \result == (x / 100 * 100 <= x && x <= x / 100 * 105);
    assigns \nothing;
 */
bool func(unsigned int x)
{
    unsigned int n;
    unsigned int a;

    //@ assert is_in_range(x);
    n = x / 100;
    a = x / 100;

    if (x / 100 != x / 100 * 100 / 100)
    {
        //@ assert a == x / 100;
        return false;
    }
    else
    {
        //@ assert n == x / 100;
        return x <= a * 105;
    }
}
