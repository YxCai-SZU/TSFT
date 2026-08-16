#include <stdbool.h>

/*@ predicate is_in_range(integer x) = -100 <= x && x <= 100; */

/*@
  requires is_in_range(a) && is_in_range(b) && is_in_range(c);
  ensures (a == b && a != c) ==> \result == c;
  ensures (a != b && a == c) ==> \result == b;
  ensures (a == c && a != b) ==> \result == b;
  ensures (a == b && a == c) || (a != b && b != c && c != a) ==> 
          (\result == a || \result == b || \result == c);
*/
long func(long a, long b, long c)
{
    long result;
    //@ assert is_in_range(a) && is_in_range(b) && is_in_range(c);
    
    if (a == b) {
        result = c;
        //@ assert (a == b && a != c) ==> result == c;
        return result;
    } else if (a == c) {
        result = b;
        //@ assert (a != b && a == c) ==> result == b;
        return result;
    } else if (b == c) {
        result = a;
        //@ assert (a == c && a != b) ==> result == b;
        return result;
    } else {
        //@ assert a != b && b != c && c != a;
        result = a;
        //@ assert (a != b && b != c && c != a) ==> (result == a || result == b || result == c);
        return result;
    }
}
