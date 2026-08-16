#include <stdbool.h>

/*@ predicate is_32bit_unsigned(integer x) = 0 <= x <= 4294967295; */

/*@
  requires is_32bit_unsigned(a) && is_32bit_unsigned(b) && 
           is_32bit_unsigned(c) && is_32bit_unsigned(d);
  ensures \result == ((a < b) || (c < d));
  assigns \nothing;
*/
bool func(unsigned int a, unsigned int b, unsigned int c, unsigned int d)
{
    // Variable declarations at top of scope
    bool result;
    
    //@ assert is_32bit_unsigned(a);
    //@ assert is_32bit_unsigned(b);
    //@ assert is_32bit_unsigned(c);
    //@ assert is_32bit_unsigned(d);
    
    result = (a < b) || (c < d);
    return result;
}
