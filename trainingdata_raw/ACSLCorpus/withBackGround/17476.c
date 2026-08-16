#include <stdbool.h>

/*@
    predicate in_range(integer a, integer b, integer c) =
        a > 0 && b > 0 && c > 0 && c >= a && c < b;
*/

/*@
    lemma range_complement:
        \forall integer a, b, c;
            a > 0 && b > 0 && c > 0 ==>
            (c >= a && c < b) || (c < a || c >= b);
*/

/*@
    requires a > 0 && b > 0 && c > 0;
    ensures \result == (c >= a && c < b);
*/
bool func(unsigned long long a, unsigned long long b, unsigned long long c)
{
    unsigned long long start = a;
    unsigned long long end = b;
    unsigned long long value = c;
    bool result;

    //@ assert a > 0 && b > 0 && c > 0;
    
    if (c >= a && c < b) {
        result = true;
        //@ assert result == (c >= a && c < b);
        return result;
    } else {
        //@ assert c < a || c >= b;
        result = false;
        //@ assert result == (c >= a && c < b);
        return result;
    }
}
