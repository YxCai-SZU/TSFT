#include <stdbool.h>

/*@ predicate two_equal_one_different(integer a, integer b, integer c) =
      (a == b && a != c) ||
      (a == c && a != b) ||
      (b == c && a != b);
*/

/*@
  requires 1 <= a <= 9;
  requires 1 <= b <= 9;
  requires 1 <= c <= 9;
  ensures \result == true <==> two_equal_one_different(a, b, c);
*/
bool func(int a, int b, int c)
{
    int cnt = 0;
    
    //@ assert 1 <= a <= 9 && 1 <= b <= 9 && 1 <= c <= 9;
    
    if (a == b) {
        cnt += 1;
    }
    if (a == c) {
        cnt += 1;
    }
    if (b == c) {
        cnt += 1;
    }
    
    //@ assert cnt == 1 ==> two_equal_one_different(a, b, c);
    
    return cnt == 1;
}
