#include <stdbool.h>

/*@
    predicate is_less_than_half_max(unsigned int x) = x < 0x80000000;

    logic integer diff(unsigned int e, unsigned int a) = e - a;

    lemma diff_nonnegative: \forall unsigned int e, a; e >= a ==> diff(e, a) >= 0;
    lemma diff_bounded: \forall unsigned int e, a; 
        is_less_than_half_max(e) && is_less_than_half_max(a) && e >= a ==> 
        diff(e, a) <= 0x7FFFFFFF;
*/

/*@
    requires is_less_than_half_max(a);
    requires is_less_than_half_max(b);
    requires is_less_than_half_max(c);
    requires is_less_than_half_max(d);
    requires is_less_than_half_max(e);
    requires is_less_than_half_max(k);
    requires a < b && b < c && c < d && d < e;
    ensures \result == (k >= (e - a) || (e - a) <= 0);
*/
bool func(unsigned int a, unsigned int b, unsigned int c, 
          unsigned int d, unsigned int e, unsigned int k)
{
    // Variable declarations at top
    unsigned int difference;
    bool condition1;
    bool condition2;
    bool result;

    //@ assert e >= a;
    //@ assert e - a <= 0x7FFFFFFF;
    
    difference = e - a;
    condition1 = k >= difference;
    condition2 = difference <= 0;
    
    if (condition1 || condition2) {
        result = true;
    } else {
        //@ assert k < difference && difference > 0;
        result = false;
    }
    
    return result;
}
