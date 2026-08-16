#include <stdbool.h>

/*@ predicate is_valid_range(integer v) = -1000 <= v <= 1000; */

/*@ logic integer product(integer x, integer y) = x * y; */

/*@ lemma product_bounds:
      \forall integer x, y;
        is_valid_range(x) && is_valid_range(y) ==> -1000000 <= product(x, y) <= 1000000; */

/*@ predicate is_possible_result(integer r, integer a, integer b, integer c, integer d) =
      r == product(a, c) || r == product(a, d) || r == product(b, c) || r == product(b, d); */

/*@ requires is_valid_range(a) && is_valid_range(b) && is_valid_range(c) && is_valid_range(d);
    ensures is_possible_result(\result, a, b, c, d);
    ensures -1000000 <= \result <= 1000000;
    assigns \nothing;
*/
int func(int a, int b, int c, int d)
{
    int tmp[4];
    int max_value;
    int i;

    //@ assert -1000000 <= a * c <= 1000000;
    tmp[0] = a * c;
    //@ assert -1000000 <= a * d <= 1000000;
    tmp[1] = a * d;
    //@ assert -1000000 <= b * c <= 1000000;
    tmp[2] = b * c;
    //@ assert -1000000 <= b * d <= 1000000;
    tmp[3] = b * d;

    max_value = tmp[0];
    i = 1;

    /*@ loop invariant 0 <= i <= 4;
        loop invariant \exists integer k; 0 <= k < i && max_value == tmp[k];
        loop invariant \forall integer j; 0 <= j < i ==> tmp[j] <= max_value;
        loop invariant tmp[0] == a * c && tmp[1] == a * d && tmp[2] == b * c && tmp[3] == b * d;
        loop invariant -1000000 <= max_value <= 1000000;
        loop assigns i, max_value;
        loop variant 4 - i;
    */
    while (i < 4)
    {
        if (tmp[i] > max_value)
        {
            max_value = tmp[i];
        }
        i = i + 1;
    }

    //@ assert is_possible_result(max_value, a, b, c, d);
    return max_value;
}
