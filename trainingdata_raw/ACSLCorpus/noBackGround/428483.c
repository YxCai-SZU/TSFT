#include <stdbool.h>

/*@
    requires (0 <= (a) && (a) <= 123) && (0 <= (b) && (b) <= 123) && (0 <= (c) && (c) <= 123) && (0 <= (d) && (d) <= 123) && (0 <= (e) && (e) <= 123) && (0 <= (k) && (k) <= 123);
    requires ((a) < (b) && (b) < (c) && (c) < (d) && (d) < (e));
    ensures \result == true <==> (e - a <= k);
*/
bool func(int a, int b, int c, int d, int e, int k)
{
    int cnt = 0;
    int i = a;

    /*@
        loop invariant (0 <= (a) && (a) <= 123) && (0 <= (b) && (b) <= 123) && (0 <= (c) && (c) <= 123) && (0 <= (d) && (d) <= 123) && (0 <= (e) && (e) <= 123) && (0 <= (k) && (k) <= 123);
        loop invariant ((a) < (b) && (b) < (c) && (c) < (d) && (d) < (e));
        loop invariant a <= i && i <= e;
        loop invariant cnt == i - a;
        loop assigns cnt, i;
    */
    while (i < e)
    {
        //@ assert i < e;
        cnt += 1;
        i += 1;
    }

    //@ assert cnt == e - a;
    //@ assert cnt <= k <==> e - a <= k;
    return cnt <= k;
}
