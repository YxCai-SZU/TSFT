#include <stdbool.h>

/*@
    predicate is_valid_n(integer n) = 1 <= n && n <= 100;

    logic integer left_side(integer n, integer i) = i * 800;
    logic integer right_side(integer n, integer i) = i * 200;

    lemma loop_decreases_left:
        \forall integer n, i; is_valid_n(n) && 0 <= i && i < n ==> n - i > 0;

    lemma loop_decreases_right:
        \forall integer n, i; is_valid_n(n) && 0 <= i && i < n/15 ==> n/15 - i > 0;
*/

/*@
    requires is_valid_n(n);
    ensures \result == (n * 800 >= (n / 15) * 200);
*/
bool func(unsigned int n)
{
    int x = 800;
    int y = 200;
    int ans = 0;
    unsigned int i = 0;

    /*@
        loop invariant 0 <= i <= n;
        loop invariant ans == i * x;
        loop invariant is_valid_n(n);
        loop assigns i, ans;
        loop variant n - i;
    */
    while (i < n)
    {
        //@ assert i < n;
        ans += x;
        i += 1;
    }

    int temp_ans = 0;
    unsigned int temp_i = 0;

    /*@
        loop invariant 0 <= temp_i <= n / 15;
        loop invariant temp_ans == temp_i * y;
        loop invariant is_valid_n(n);
        loop assigns temp_i, temp_ans;
        loop variant n / 15 - temp_i;
    */
    while (temp_i < n / 15)
    {
        //@ assert temp_i < n / 15;
        temp_ans += y;
        temp_i += 1;
    }

    //@ assert ans == n * x;
    //@ assert temp_ans == (n / 15) * y;
    return ans >= temp_ans;
}
