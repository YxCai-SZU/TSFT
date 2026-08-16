#include <stdbool.h>

/*@ predicate distinct(integer a, integer b, integer c) =
      a != b && b != c && c != a;
*/

/*@ predicate within_range(integer a, integer b, integer c) =
      0 <= a && a <= 100 &&
      0 <= b && b <= 100 &&
      0 <= c && c <= 100;
*/

/*@ lemma distinct_implies_nonzero_diff:
      \forall integer a, b, c;
        distinct(a, b, c) ==> (a - b != 0) && (b - c != 0) && (c - a != 0);
*/

/*@
  requires within_range(a, b, c);
  requires distinct(a, b, c);
  ensures \result == ((a < c && c < b) || (a > c && c > b));
*/
bool func(int a, int b, int c)
{
    bool result;
    
    //@ assert distinct(a, b, c);
    //@ assert within_range(a, b, c);
    
    result = (a < c && c < b) || (a > c && c > b);
    
    //@ assert result == ((a < c && c < b) || (a > c && c > b));
    return result;
}
