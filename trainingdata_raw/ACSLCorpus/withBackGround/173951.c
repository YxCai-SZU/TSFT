#include <stdbool.h>

/*@ predicate is_ordered(integer a, integer b, integer c, integer d, integer e) =
       a <= b && b <= c && c <= d && d <= e;
*/

/*@ lemma ordering_implication:
       \forall integer a, b, c, d, e, k;
       a >= 0 && b >= 0 && c >= 0 && d >= 0 && e >= 0 &&
       a <= 123 && b <= 123 && c <= 123 && d <= 123 && e <= 123 &&
       k >= 0 && k <= 123 &&
       is_ordered(a, b, c, d, e) &&
       e <= a + k ==>
       a <= b && b <= c && c <= d && d <= e && e <= a + k;
*/

/*@ requires 0 <= a && a <= 123;
    requires 0 <= b && b <= 123;
    requires 0 <= c && c <= 123;
    requires 0 <= d && d <= 123;
    requires 0 <= e && e <= 123;
    requires 0 <= k && k <= 123;
    ensures \result == true <==> a <= b && b <= c && c <= d && d <= e && e <= a + k;
*/
bool func(long a, long b, long c, long d, long e, long k)
{
    //@ assert a >= 0 && a <= 123;
    //@ assert b >= 0 && b <= 123;
    //@ assert c >= 0 && c <= 123;
    //@ assert d >= 0 && d <= 123;
    //@ assert e >= 0 && e <= 123;
    //@ assert k >= 0 && k <= 123;

    if (a > b) {
        //@ assert !(a <= b);
        return false;
    }
    if (b > c) {
        //@ assert !(b <= c);
        return false;
    }
    if (c > d) {
        //@ assert !(c <= d);
        return false;
    }
    if (d > e) {
        //@ assert !(d <= e);
        return false;
    }
    if (e > a + k) {
        //@ assert !(e <= a + k);
        return false;
    }
    
    //@ assert a <= b && b <= c && c <= d && d <= e;
    //@ assert e <= a + k;
    return true;
}
