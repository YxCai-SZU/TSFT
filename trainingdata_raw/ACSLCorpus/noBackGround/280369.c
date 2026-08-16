#include <stdbool.h>

/*@
    requires (0 <= (a) && (a) < (b) && (b) < (c) && (c) < (d) && (d) < (e) && (e) <= 123);
    requires (0 <= (k) && (k) <= 123);
    ensures \result == true <==> ((e) - (a)) <= k;
*/
bool func(long a, long b, long c, long d, long e, long k)
{
    long i = a;
    long cnt = 0;
    /*@ ghost long original_a = a; */
    /*@ ghost long original_e = e; */
    /*@ ghost long original_k = k; */

    /*@
        loop invariant ((original_a) <= (i) && (i) <= (original_e) && 0 <= (cnt) && (cnt) <= (i) - (original_a) && (i) - (original_a) == (cnt));
        loop invariant (0 <= (original_a) && (original_a) < (b) && (b) < (c) && (c) < (d) && (d) < (original_e) && (original_e) <= 123);
        loop invariant (0 <= (original_k) && (original_k) <= 123);
        loop assigns i, cnt;
        loop variant original_e - i;
    */
    while (i < e)
    {
        //@ assert cnt == i - original_a;
        cnt += 1;
        //@ assert cnt == i - original_a + 1;
        i += 1;
        //@ assert i - original_a == cnt;
    }
    //@ assert i == original_e;
    //@ assert cnt == original_e - original_a;
    return cnt <= k;
}
