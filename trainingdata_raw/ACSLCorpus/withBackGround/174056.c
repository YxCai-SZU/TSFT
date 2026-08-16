#include <limits.h>

/*@
    predicate valid_params(integer a, integer b, integer c, integer k) =
        a >= 0 && b >= 0 && c >= 0 &&
        k >= 1 &&
        k <= a + b + c &&
        a + b + c <= 2000000000;

    logic integer compute_res(integer a_cnt, integer b_cnt, integer c_cnt) =
        a_cnt - c_cnt + (b_cnt > 0 ? 1 : 0);
*/

/*@
    requires valid_params(a, b, c, k);
    ensures \result <= a + b + c;
    ensures \result >= k - b - c;
    assigns \nothing;
*/
int func(int a, int b, int c, int k)
{
    int a_cnt;
    int b_cnt;
    int c_cnt;
    int res;

    a_cnt = (k < a) ? k : a;
    //@ assert a_cnt >= 0 && a_cnt <= a;

    b_cnt = (k - a - b > 0) ? (k - a - b) : 0;
    //@ assert b_cnt >= 0;

    c_cnt = (k - a - b - c > 0) ? (k - a - b - c) : 0;
    //@ assert c_cnt >= 0;

    //@ assert a_cnt + b_cnt + c_cnt <= a + b + c;
    res = a_cnt - c_cnt;
    //@ assert res <= a + b + c;
    //@ assert res >= k - b - c;

    /*@
        loop invariant b_cnt >= 0 && c_cnt >= 0;
        loop invariant a_cnt + b_cnt + c_cnt <= a + b + c;
        loop invariant res <= a + b + c;
        loop invariant res >= k - b - c;
        loop assigns b_cnt, c_cnt;
        loop variant b_cnt + c_cnt;
    */
    while (b_cnt > 0 && c_cnt > 0)
    {
        b_cnt -= 1;
        c_cnt -= 1;
    }

    res += (b_cnt > 0) ? 1 : 0;
    //@ assert res <= a + b + c;
    //@ assert res >= k - b - c;

    return res;
}

int main()
{
    return 0;
}
