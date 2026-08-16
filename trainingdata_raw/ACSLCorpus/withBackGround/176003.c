#include <stdbool.h>

/*@ predicate is_valid_params(integer a, integer b, integer c, integer d) =
      a >= 1 && a <= 100 &&
      b >= 1 && b <= 100 &&
      c >= 1 && c <= 100 &&
      d >= 1 && d <= 100;
*/

/*@ logic integer sum_of_two(integer a, integer b, integer c, integer d, integer idx) =
      idx == 0 ? a + b :
      idx == 1 ? a + c :
      idx == 2 ? a + d :
      idx == 3 ? b + c :
      idx == 4 ? b + d :
      c + d;
*/

/*@ lemma sum_bounds:
      \forall integer a, b, c, d;
      is_valid_params(a, b, c, d) ==>
      (\forall integer idx; 0 <= idx <= 5 ==> sum_of_two(a, b, c, d, idx) >= 0);
*/

/*@ lemma sum_upper_bound:
      \forall integer a, b, c, d;
      is_valid_params(a, b, c, d) ==>
      (\forall integer idx; 0 <= idx <= 5 ==> sum_of_two(a, b, c, d, idx) <= a + b + c + d);
*/

/*@ requires is_valid_params(a, b, c, d);
    ensures \result >= 0;
    ensures \result <= a + b + c + d;
    ensures \result == a + b || \result == a + c || \result == a + d ||
            \result == b + c || \result == b + d || \result == c + d;
    assigns \nothing;
*/
int func(int a, int b, int c, int d) {
    int e[6];
    int min_value;
    int i;

    e[0] = a + b;
    e[1] = a + c;
    e[2] = a + d;
    e[3] = b + c;
    e[4] = b + d;
    e[5] = c + d;

    min_value = e[0];
    i = 1;

    /*@ loop invariant 1 <= i <= 6;
        loop invariant \exists integer j; 0 <= j < i && min_value == e[j];
        loop invariant \forall integer k; 0 <= k < i ==> min_value <= e[k];
        loop invariant is_valid_params(a, b, c, d);
        loop assigns min_value, i;
        loop variant 6 - i;
    */
    while (i < 6) {
        //@ assert 0 <= i < 6;
        if (e[i] < min_value) {
            min_value = e[i];
        }
        i = i + 1;
    }

    //@ assert \exists integer idx; 0 <= idx < 6 && min_value == e[idx];
    return min_value;
}
