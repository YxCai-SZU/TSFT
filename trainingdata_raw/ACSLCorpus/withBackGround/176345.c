#include <stdbool.h>

/*@ predicate is_between(integer a, integer b, integer c) =
      a <= c && c <= b;
*/

/*@ lemma multiplication_bounds:
      \forall integer t, s;
        1 <= t <= 10000 && 1 <= s <= 10000 ==>
        t * s <= 10000 * 10000;
*/

/*@ requires 1 <= a <= 100 && 1 <= b <= 100 && 1 <= c <= 100;
    ensures \result == (a <= c && c <= b);
    assigns \nothing;
*/
bool is_between(int a, int b, int c) {
    bool result;
    //@ assert 1 <= a <= 100 && 1 <= b <= 100 && 1 <= c <= 100;
    result = (a <= c && c <= b);
    //@ assert result == (a <= c && c <= b);
    return result;
}

/*@ requires 1 <= d <= 10000 && 1 <= t <= 10000 && 1 <= s <= 10000;
    ensures \result == (d <= t * s);
    assigns \nothing;
*/
bool func(int d, int t, int s) {
    int product;
    bool result;
    //@ assert 1 <= d <= 10000 && 1 <= t <= 10000 && 1 <= s <= 10000;
    //@ assert t * s <= 10000 * 10000;
    product = t * s;
    //@ assert product == t * s;
    result = (d <= product);
    //@ assert result == (d <= t * s);
    return result;
}
