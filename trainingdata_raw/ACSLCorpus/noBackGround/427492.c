#include <limits.h>

/*@
    requires (1 <= (a) <= 10000) && (1 <= (b) <= 10000) && (1 <= (c) <= 10000) && (1 <= (d) <= 10000);
    ensures \result == a + c || \result == b + c || \result == a + d || \result == b + d;
    ensures \result >= 2;
*/
unsigned int func(unsigned int a, unsigned int b, unsigned int c, unsigned int d)
{
    unsigned int ans = UINT_MAX;
    unsigned int ac;
    unsigned int bc;
    unsigned int ad;
    unsigned int bd;

    //@ assert a + c <= 20000;
    ac = a + c;

    //@ assert b + c <= 20000;
    bc = b + c;

    //@ assert a + d <= 20000;
    ad = a + d;

    //@ assert b + d <= 20000;
    bd = b + d;

    ans = (ac < ans) ? ac : ans;
    ans = (bc < ans) ? bc : ans;
    ans = (ad < ans) ? ad : ans;
    ans = (bd < ans) ? bd : ans;

    return ans;
}
