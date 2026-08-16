#include <stdbool.h>

/*@ predicate is_less_than_max(integer x) = x < 0x80000000; */

/*@
    requires is_less_than_max(a) && is_less_than_max(b) && is_less_than_max(c);
    ensures \result == (a < b && b < c);
    assigns \nothing;
*/
bool func(int a, int b, int c)
{
    // Variable declarations at top of scope
    bool result;

    //@ assert is_less_than_max(a);
    //@ assert is_less_than_max(b);
    //@ assert is_less_than_max(c);
    //@ assert is_less_than_max(a);
    
    //@ assert a < b || a == b || a > b;
    //@ assert b < c || b == c || b > c;
    
    //@ assert a < b || a == b || a > b;
    //@ assert b < c || b == c || b > c;
    
    result = a < b && b < c;
    return result;
}
