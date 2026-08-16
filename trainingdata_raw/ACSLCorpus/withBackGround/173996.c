#include <stdbool.h>

/*@ predicate sorted(integer max, integer mid, integer min) =
      max >= mid && mid >= min;
*/

/*@ logic integer max_of_three(integer a, integer b, integer c) =
      (a >= b && a >= c) ? a : (b >= c ? b : c);
*/

/*@ logic integer mid_of_three(integer a, integer b, integer c) =
      (a >= b && a <= c) || (a <= b && a >= c) ? a :
      (b >= a && b <= c) || (b <= a && b >= c) ? b : c;
*/

/*@ logic integer min_of_three(integer a, integer b, integer c) =
      (a <= b && a <= c) ? a : (b <= c ? b : c);
*/

/*@ lemma sort_property:
      \forall integer a, b, c;
      max_of_three(a, b, c) >= mid_of_three(a, b, c) &&
      mid_of_three(a, b, c) >= min_of_three(a, b, c);
*/

/*@
  requires 1 <= a <= 100;
  requires 1 <= b <= 100;
  requires 1 <= c <= 100;
  ensures \result == (a + b == c || b + c == a || c + a == b);
*/
bool func(unsigned long a, unsigned long b, unsigned long c) {
    unsigned long max;
    unsigned long mid;
    unsigned long min;
    unsigned long temp;

    max = a;
    mid = b;
    min = c;

    //@ assert max == a && mid == b && min == c;

    if (max < mid) {
        temp = max;
        max = mid;
        mid = temp;
    }
    //@ assert max >= mid;

    if (mid < min) {
        temp = mid;
        mid = min;
        min = temp;
    }
    //@ assert mid >= min;

    if (max < mid) {
        temp = max;
        max = mid;
        mid = temp;
    }
    //@ assert max >= mid && mid >= min;

    //@ assert sorted(max, mid, min);
    //@ assert max == max_of_three(a, b, c);
    //@ assert mid == mid_of_three(a, b, c);
    //@ assert min == min_of_three(a, b, c);

    return max == mid + min;
}
