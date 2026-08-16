#include <stdbool.h>

/*@ predicate strictly_increasing(integer a, integer b, integer c) =
      a < b && b < c;
*/

/*@ predicate strictly_decreasing(integer a, integer b, integer c) =
      a > b && b > c;
*/

/*@ lemma test_strictly_increasing:
      strictly_increasing(1, 2, 3) &&
      !strictly_increasing(3, 3, 3) &&
      !strictly_increasing(1, 1, 1) &&
      strictly_increasing(10, 20, 30) &&
      !strictly_increasing(30, 30, 30);
*/

/*@ lemma test_strictly_decreasing:
      strictly_decreasing(10, 5, 1) &&
      !strictly_decreasing(10, 10, 10) &&
      !strictly_decreasing(1, 1, 1) &&
      strictly_decreasing(30, 20, 10) &&
      !strictly_decreasing(30, 30, 30);
*/

/*@ requires 1 <= a <= 100;
    requires 1 <= b <= 100;
    requires 1 <= c <= 100;
    ensures \result == (a < b && b < c);
    assigns \nothing;
*/
bool func(int a, int b, int c)
{
    bool result;
    
    if (a < b && b < c) {
        result = true;
    } else {
        result = false;
    }
    
    //@ assert (a < b && b < c) == (a < b && b < c);
    return result;
}
