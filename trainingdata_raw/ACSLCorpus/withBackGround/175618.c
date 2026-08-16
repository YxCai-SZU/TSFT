#include <stdbool.h>

/*@
    predicate is_even{L}(int *s, integer len) =
        \forall integer i; 0 <= i < len ==> (s[i] & 1) == 0;

    logic integer square(integer a) = a * a;

    lemma square_bound: \forall integer a; 0 <= a <= 100 ==> a * a <= 10000;
*/

/*@
    requires 0 <= a <= 100;
    ensures \result == a * a;
    assigns \nothing;
*/
int func(int a)
{
    int result;
    
    //@ assert 0 <= a && a <= 100;
    //@ assert a * a <= 10000;
    
    result = a * a;
    return result;
}
