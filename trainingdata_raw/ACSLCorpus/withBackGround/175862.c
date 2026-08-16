#include <stdbool.h>
#include <stddef.h>

/*@ predicate abs_diff(integer a, integer b, integer diff) =
        (a > b ==> diff == a - b) &&
        (a <= b ==> diff == b - a);
*/

/*@ predicate vec_eq{L}(int *S, int *T, integer len, integer i) =
        \forall integer k; 0 <= k < i ==> S[k] == T[k];
*/

/*@ lemma abs_diff_sym:
        \forall integer a, b, d1, d2;
        abs_diff(a, b, d1) && abs_diff(b, a, d2) ==> d1 == d2;
*/

/*@ lemma vec_eq_full:
        \forall int *S, *T, integer len;
        vec_eq(S, T, len, len) ==> (\forall integer i; 0 <= i < len ==> S[i] == T[i]);
*/

/*@ requires 1 <= A <= 10000;
    requires 1 <= B <= 10000;
    requires 1 <= C <= 10000;
    requires 1 <= D <= 10000;
    ensures \result == (A > B ? A - B : B - A) + (C > D ? C - D : D - C);
*/
int func(int A, int B, int C, int D)
{
    int ans;
    int tmp1;
    int tmp2;

    //@ assert abs_diff(A, B, A > B ? A - B : B - A);
    tmp1 = A > B ? A - B : B - A;
    //@ assert abs_diff(C, D, C > D ? C - D : D - C);
    tmp2 = C > D ? C - D : D - C;
    ans = tmp1 + tmp2;
    //@ assert abs_diff(A, B, tmp1) && abs_diff(C, D, tmp2);
    return ans;
}

/*@ requires \valid_read(S + (0..len-1));
    requires \valid_read(T + (0..len-1));
    ensures \result == true <==> (\forall integer i; 0 <= i < len ==> S[i] == T[i]);
*/
bool func2(int *S, int *T, size_t len)
{
    size_t i = 0;

    /*@ loop invariant 0 <= i <= len;
        loop invariant vec_eq(S, T, len, i);
        loop assigns i;
        loop variant len - i;
    */
    while (i < len)
    {
        //@ assert i < len;
        if (S[i] != T[i])
        {
            //@ assert !vec_eq(S, T, len, i+1);
            return false;
        }
        //@ assert vec_eq(S, T, len, i+1);
        i++;
    }
    //@ assert vec_eq(S, T, len, len);
    return true;
}
