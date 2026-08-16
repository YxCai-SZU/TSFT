#include <stdbool.h>

/*@ predicate sorted(integer a, integer b, integer c) =
      a < b && b < c;
*/

/*@ lemma ordering_lemma:
      \forall integer a, b, c;
        0 <= a <= 100 && 0 <= b <= 100 && 0 <= c <= 100 &&
        a != b && b != c && a != c ==>
        (a < b && b < c) || (a < c && c < b) || (b < a && a < c) ||
        (b < c && c < a) || (c < a && a < b) || (c < b && b < a);
*/

/*@ requires 0 <= a <= 100;
    requires 0 <= b <= 100;
    requires 0 <= c <= 100;
    requires a != b && b != c && a != c;
    ensures \result == ((a < c && c < b) || (a > c && c > b));
*/
bool func(int a, int b, int c) {
    int min;
    int mid;
    int max;

    if (a < b) {
        if (b < c) {
            min = a;
            mid = b;
            max = c;
        } else if (a < c) {
            min = a;
            mid = c;
            max = b;
        } else {
            min = c;
            mid = a;
            max = b;
        }
    } else {
        if (a < c) {
            min = b;
            mid = a;
            max = c;
        } else if (b < c) {
            min = b;
            mid = c;
            max = a;
        } else {
            min = c;
            mid = b;
            max = a;
        }
    }

    //@ assert min < mid && mid < max;
    return mid == c;
}
