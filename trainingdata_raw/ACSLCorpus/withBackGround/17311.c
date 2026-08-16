#include <stdbool.h>

/*@ predicate distinct(integer a, integer b, integer c) =
      a != b && b != c && a != c;
*/

/*@ lemma distinct_implies_neq:
      \forall integer a, b, c;
        1 <= a <= 100 && 1 <= b <= 100 && 1 <= c <= 100 &&
        distinct(a, b, c) ==> a != b && b != c && a != c;
*/

/*@ requires 1 <= a <= 100;
    requires 1 <= b <= 100;
    requires 1 <= c <= 100;
    requires distinct(a, b, c);
    ensures \result == ((a < c && c < b) || (b < c && c < a));
*/
bool func(int a, int b, int c)
{
    //@ assert distinct(a, b, c);
    return (a < c && c < b) || (b < c && c < a);
}
