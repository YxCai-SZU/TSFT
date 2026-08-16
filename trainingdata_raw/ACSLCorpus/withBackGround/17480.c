#include <stdbool.h>

/*@ predicate a_inv(int *a) =
      \valid(a) && \valid(a+1) &&
      1 <= a[0] && a[0] <= 16 &&
      1 <= a[1] && a[1] <= 16 &&
      a[0] + a[1] <= 16;
*/

/*@ predicate b_inv(int *b) =
      \valid(b) && \valid(b+1) &&
      1 <= b[0] && b[0] <= 16 &&
      1 <= b[1] && b[1] <= 16 &&
      b[0] + b[1] <= 16;
*/

/*@ logic integer max_of_four(integer a0b1, integer a1b0, integer a0b0, integer a1b1) =
      (a0b1 >= a1b0 && a0b1 >= a0b0 && a0b1 >= a1b1) ? a0b1 :
      (a1b0 >= a0b0 && a1b0 >= a1b1) ? a1b0 :
      (a0b0 >= a1b1) ? a0b0 : a1b1;
*/

/*@ lemma max_val_lemma:
      \forall integer a0, a1, b0, b1, max_val;
      max_val == max_of_four(a0+b1, a1+b0, a0+b0, a1+b1) ==>
      (max_val == a0+b1 || max_val == a1+b0 || max_val == a0+b0 || max_val == a1+b1);
*/

/*@
  requires a_inv(a) && b_inv(b);
  ensures \result == (a[0]+b[1] >= 8 || a[1]+b[0] >= 8 || a[0]+b[0] >= 8 || a[1]+b[1] >= 8);
*/
bool func(int *a, int *b)
{
    int a0;
    int a1;
    int b0;
    int b1;
    int max1;
    int max2;
    int max_val;
    bool res;

    //@ assert a[0] >= 1 && a[0] <= 16;
    //@ assert a[1] >= 1 && a[1] <= 16;
    //@ assert b[0] >= 1 && b[0] <= 16;
    //@ assert b[1] >= 1 && b[1] <= 16;
    //@ assert a[0] + a[1] <= 16;
    //@ assert b[0] + b[1] <= 16;

    a0 = a[0];
    a1 = a[1];
    b0 = b[0];
    b1 = b[1];

    //@ assert 1 <= a0 && a0 <= 16;
    //@ assert 1 <= a1 && a1 <= 16;
    //@ assert 1 <= b0 && b0 <= 16;
    //@ assert 1 <= b1 && b1 <= 16;
    //@ assert a0 + a1 <= 16;
    //@ assert b0 + b1 <= 16;

    if (a0 + b1 > a1 + b0) {
        max1 = a0 + b1;
    } else {
        max1 = a1 + b0;
    }

    if (a0 + b0 > a1 + b1) {
        max2 = a0 + b0;
    } else {
        max2 = a1 + b1;
    }

    if (max1 > max2) {
        max_val = max1;
    } else {
        max_val = max2;
    }

    //@ assert max_val == max_of_four(a0+b1, a1+b0, a0+b0, a1+b1);
    //@ assert max_val == a0+b1 || max_val == a1+b0 || max_val == a0+b0 || max_val == a1+b1;

    res = max_val >= 8;
    //@ assert res == (a0+b1 >= 8 || a1+b0 >= 8 || a0+b0 >= 8 || a1+b1 >= 8);
    return res;
}
