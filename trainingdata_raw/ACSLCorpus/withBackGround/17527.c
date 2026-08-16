#include <limits.h>

/*@ predicate valid_params(integer X, integer Y) =
      1 <= X && X <= 205 &&
      1 <= Y && Y <= 205 &&
      Y % 2 == 0;
*/

/*@ logic integer expected_money(integer X, integer Y) =
      X > Y ? 0 : (Y - X) + (Y - X) / 2;
*/

/*@ lemma money_nonnegative:
      \forall integer X, Y;
      valid_params(X, Y) ==> expected_money(X, Y) >= 0;
*/

/*@ lemma money_cases:
      \forall integer X, Y;
      valid_params(X, Y) ==>
        (X > Y ==> expected_money(X, Y) == 0) &&
        (X <= Y ==> expected_money(X, Y) == (Y - X) + (Y - X) / 2);
*/

/*@ requires valid_params(X, Y);
    ensures \result >= 0;
    ensures X > Y ==> \result == 0;
    ensures X <= Y ==> \result == (Y - X) + (Y - X) / 2;
*/
int func(int X, int Y) {
    int money;
    int temp;
    int count;
    int i;

    money = 0;
    temp = X;

    if (X > Y) {
        money = 0;
    } else {
        temp = Y - X;
        money = temp;
        count = 0;
        i = 0;

        /*@ loop invariant 0 <= i <= temp;
            loop invariant 0 <= count <= i / 2;
            loop invariant temp == Y - X;
            loop invariant money == temp;
            loop invariant 1 <= X && X <= 205;
            loop invariant 1 <= Y && Y <= 205;
            loop invariant Y % 2 == 0;
            loop invariant count * 2 == i;
            loop assigns i, count;
            loop variant temp - i;
        */
        while (i < temp) {
            if (i + 1 < temp) {
                count += 1;
            } else {
                break;
            }
            i += 2;
        }
        money += count;
    }

    //@ assert (X <= Y ==> money == (Y - X) + (Y - X) / 2);
    return money;
}
