#include <stdbool.h>

/*@
    predicate is_valid_range(integer x) = 1 <= x <= 100;

    logic integer min_of_three(integer a, integer b, integer c) =
        a < b ?
            (a < c ? a : c)
        :
            (b < c ? b : c);

    logic integer max_of_three(integer a, integer b, integer c) =
        a > b ?
            (a > c ? a : c)
        :
            (b > c ? b : c);

    logic integer mid_of_three(integer a, integer b, integer c) =
        a + b + c - max_of_three(a, b, c) - min_of_three(a, b, c);

    lemma min_max_mid_range:
        \forall integer a, b, c;
            is_valid_range(a) && is_valid_range(b) && is_valid_range(c) ==>
            is_valid_range(min_of_three(a, b, c)) &&
            is_valid_range(max_of_three(a, b, c)) &&
            is_valid_range(mid_of_three(a, b, c));
*/

/*@
    requires 1 <= a <= 100;
    requires 1 <= b <= 100;
    requires 1 <= c <= 100;
    ensures \result == true <==> (a == b + c || b == c + a || c == a + b);
    assigns \nothing;
*/
bool func(int a, int b, int c)
{
    int min;
    int max;
    int mid;

    //@ assert is_valid_range(a) && is_valid_range(b) && is_valid_range(c);

    if (a < b) {
        if (a < c) {
            min = a;
        } else {
            min = c;
        }
    } else {
        if (b < c) {
            min = b;
        } else {
            min = c;
        }
    }

    if (a > b) {
        if (a > c) {
            max = a;
        } else {
            max = c;
        }
    } else {
        if (b > c) {
            max = b;
        } else {
            max = c;
        }
    }

    mid = a + b + c - max - min;

    //@ assert min == min_of_three(a, b, c);
    //@ assert max == max_of_three(a, b, c);
    //@ assert mid == mid_of_three(a, b, c);

    if (min == max) {
        return false;
    } else if (mid == max - min) {
        //@ assert 1 <= min <= 100;
        //@ assert 1 <= mid <= 100;
        //@ assert 1 <= max <= 100;
        return true;
    } else {
        return false;
    }
}
