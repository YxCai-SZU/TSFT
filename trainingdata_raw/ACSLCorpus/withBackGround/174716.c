#include <stdbool.h>

/*@ predicate contains_zero(int *s, integer len) =
      \exists integer i; 0 <= i < len && s[i] == 0;
*/

/*@ predicate all_positive(int *s, integer len) =
      \forall integer i; 0 <= i < len ==> s[i] > 0;
*/

/*@ lemma sum_bounds:
      \forall integer a, b, c, d;
      1 <= a <= 10000 && 1 <= b <= 10000 && 1 <= c <= 10000 && 1 <= d <= 10000 ==>
      a + b + c + d <= 40000;
*/

/*@ requires 1 <= a <= 10000;
    requires 1 <= b <= 10000;
    requires 1 <= c <= 10000;
    requires 1 <= d <= 10000;
    ensures \result == a + b + c + d;
    ensures \result <= 40000;
    assigns \nothing;
*/
int func(int a, int b, int c, int d)
{
    int res;
    //@ assert 1 <= a <= 10000;
    res = a + b;
    //@ assert 1 <= b <= 10000;
    res = res + c;
    //@ assert 1 <= c <= 10000;
    res = res + d;
    //@ assert 1 <= d <= 10000;
    //@ assert res == a + b + c + d;
    return res;
}

/*@ requires 1 <= a <= 10000;
    requires 1 <= b <= 10000;
    requires 1 <= c <= 10000;
    requires 1 <= d <= 10000;
    ensures \result == a + b + c + d;
    ensures \result <= 40000;
    assigns \nothing;
*/
int func2(int a, int b, int c, int d)
{
    int res;
    //@ assert 1 <= a <= 10000;
    res = a + b;
    //@ assert 1 <= b <= 10000;
    res = res + c;
    //@ assert 1 <= c <= 10000;
    res = res + d;
    //@ assert 1 <= d <= 10000;
    //@ assert res == a + b + c + d;
    return res;
}
