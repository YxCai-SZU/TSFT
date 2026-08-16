#include <stdbool.h>

/*@ predicate distinct(integer a, integer b, integer c) =
      a != b && b != c && a != c;
*/

/*@ predicate is_triangle(integer a, integer b, integer c) =
      (a + b == c) || (a + c == b) || (b + c == a);
*/

/*@
  requires 0 <= a <= 100;
  requires 0 <= b <= 100;
  requires 0 <= c <= 100;
  requires distinct(a, b, c);
  ensures \result == true <==> is_triangle(a, b, c);
*/
bool func(unsigned int a, unsigned int b, unsigned int c)
{
    bool result = false;
    
    //@ assert a + b <= 200;
    //@ assert a + c <= 200;
    //@ assert b + c <= 200;
    
    if (a + b == c) {
        result = true;
    } else if (a + c == b) {
        result = true;
    } else if (b + c == a) {
        result = true;
    }
    
    return result;
}
