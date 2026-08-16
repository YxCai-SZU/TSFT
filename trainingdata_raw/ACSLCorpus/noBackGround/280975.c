#include <stddef.h>
#include <stdbool.h>

/*@
    requires 3 <= N <= 20;
    requires \valid(p + (0 .. N-1));
    requires (\forall integer i; 0 <= i < (N) ==>
            (p)[i] >= 1 && (p)[i] <= (N) &&
        \forall integer i, j; 0 <= i < j < (N) ==>
            (p)[i] != (p)[j]);
    assigns \nothing;
    ensures \result >= 0;
*/
int func(size_t N, int *p) {
    int res = 0;
    size_t i = 1;
    /*@
        loop invariant 1 <= i <= N - 1;
        loop invariant res >= 0;
        loop invariant res <= (int)i;
        loop invariant (\forall integer i; 0 <= i < (N) ==>
            (p)[i] >= 1 && (p)[i] <= (N) &&
        \forall integer i, j; 0 <= i < j < (N) ==>
            (p)[i] != (p)[j]);
        loop invariant 3 <= N <= 20;
        loop assigns i, res;
        loop variant N - i;
    */
    while (i < N - 1) {
        int p_i_minus_1 = p[i - 1];
        int p_i = p[i];
        int p_i_plus_1 = p[i + 1];
        //@ assert p_i_minus_1 >= 1 && p_i_minus_1 <= (int)N;
        //@ assert p_i >= 1 && p_i <= (int)N;
        //@ assert p_i_plus_1 >= 1 && p_i_plus_1 <= (int)N;
        //@ assert p_i_minus_1 != p_i && p_i != p_i_plus_1 && p_i_minus_1 != p_i_plus_1;
        if ((p_i_minus_1 < p_i && p_i < p_i_plus_1) ||
            (p_i_minus_1 > p_i && p_i > p_i_plus_1)) {
            //@ assert res >= 0 && res <= (int)i;
            res = res + 1;
            //@ assert res >= 0 && res <= (int)i + 1;
        }
        i += 1;
        //@ assert res <= (int)i;
    }
    return res;
}
