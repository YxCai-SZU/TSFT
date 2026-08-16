#include <stdbool.h>

/*@ predicate in_range(integer a) = -100 <= a <= 100; */
/*@ predicate within_bounds(integer a, integer b, integer c) = 
      c >= a && c <= b; */

/*@
  requires in_range(A) && in_range(B) && in_range(C);
  requires A <= B;
  ensures \result == (C >= A && C <= B);
*/
bool func(long A, long B, long C)
{
    bool result;
    
    //@ assert in_range(A);
    //@ assert in_range(B);
    //@ assert in_range(C);
    //@ assert A <= B;
    
    if (C < A || C > B) {
        //@ assert C < A || C > B;
        result = false;
    } else {
        //@ assert C >= A && C <= B;
        result = true;
    }
    
    //@ assert result == (C >= A && C <= B);
    return result;
}
