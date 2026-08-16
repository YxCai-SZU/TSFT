#include <limits.h>

/*@
    requires (1 <= (a) <= 10000) && (1 <= (b) <= 10000) && (1 <= (c) <= 10000) && (1 <= (d) <= 10000);
    ensures \result >= 0;
    ensures \result <= a + b + c + d;
*/
int func(int a, int b, int c, int d)
{
    int ans = INT_MAX;
    int a_local = a;
    int b_local = b;
    int c_local = c;
    int d_local = d;
    int min_ab;
    int min_cd;
    int min_all;

    // First minimum calculation
    //@ assert a_local >= 1 && a_local <= 10000;
    //@ assert b_local >= 1 && b_local <= 10000;
    min_ab = (a_local < b_local) ? a_local : b_local;
    //@ assert min_ab >= 1 && min_ab <= 10000;

    //@ assert c_local >= 1 && c_local <= 10000;
    //@ assert d_local >= 1 && d_local <= 10000;
    min_cd = (c_local < d_local) ? c_local : d_local;
    //@ assert min_cd >= 1 && min_cd <= 10000;

    min_all = (min_ab < min_cd) ? min_ab : min_cd;
    //@ assert min_all >= 1 && min_all <= 10000;

    ans = (ans < min_all) ? ans : min_all;
    //@ assert ans >= 0 && ans <= 10000;

    // Subtraction assertions
    //@ assert a_local >= min_all;
    //@ assert b_local >= min_all;
    //@ assert c_local >= min_all;
    //@ assert d_local >= min_all;

    a_local = a_local - min_all;
    b_local = b_local - min_all;
    c_local = c_local - min_all;
    d_local = d_local - min_all;

    // Second minimum calculation
    //@ assert a_local >= 0 && a_local <= 9999;
    //@ assert b_local >= 0 && b_local <= 9999;
    min_ab = (a_local < b_local) ? a_local : b_local;
    //@ assert min_ab >= 0 && min_ab <= 9999;

    //@ assert c_local >= 0 && c_local <= 9999;
    //@ assert d_local >= 0 && d_local <= 9999;
    min_cd = (c_local < d_local) ? c_local : d_local;
    //@ assert min_cd >= 0 && min_cd <= 9999;

    min_all = (min_ab < min_cd) ? min_ab : min_cd;
    //@ assert min_all >= 0 && min_all <= 9999;

    ans = (ans < min_all) ? ans : min_all;
    //@ assert ans >= 0 && ans <= 10000;

    // Final postcondition verification
    //@ assert ans <= a + b + c + d;

    return ans;
}
