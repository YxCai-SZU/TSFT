#include <stdbool.h>

/*@ predicate is_ordered(integer a, integer b, integer c) =
      a < b && b < c;
*/

/*@ lemma bounds_lemma:
      \forall integer a, b, c;
        1 <= a <= 9 && 1 <= b <= 9 && 1 <= c <= 9 ==>
        a < b && b < c ==> is_ordered(a, b, c);
*/

/*@
    requires 1 <= a <= 9;
    requires 1 <= b <= 9;
    requires 1 <= c <= 9;
    ensures \result == (a < b && b < c);
    assigns \nothing;
*/
bool func(long long a, long long b, long long c)
{
    // Variable declarations at top of scope
    long long epsilon = 1000000000;
    bool result;

    //@ assert 1 <= a <= 9;
    //@ assert 1 <= b <= 9;
    //@ assert 1 <= c <= 9;
    //@ assert a < b && b < c ==> (a < b && b < c);

    result = a < b && b < c;
    return result;
}
