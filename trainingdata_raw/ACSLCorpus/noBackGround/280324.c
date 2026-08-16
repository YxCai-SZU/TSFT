#include <stdbool.h>
/*@
    requires ((1 <= ((a)) <= 100) && (1 <= ((b)) <= 100));
    ensures \result == ((a) * (b));
    assigns \nothing;
*/
int func(int a, int b)
{
    //@ assert (1 <= (a) <= 100);
    //@ assert (1 <= (b) <= 100);
    //@ assert ((a) * (b)) <= 10000;
    return a * b;
}

/*@
    requires \valid(list + (0 .. len-1));
    requires (0 <= (m) < (len) && (m) <= (n) < (len));
    ensures (\forall integer j; (m) <= j <= (n) ==> (\result) >= (list)[j]);
    ensures (\exists integer k; (m) <= k <= (n) && (\result) == (list)[k]);
    assigns \nothing;
*/
int max_range_list(int *list, unsigned int len, unsigned int m, unsigned int n)
{
    //@ assert m <= n;
    //@ assert n < len;
    int max = list[m];
    unsigned int i = m + 1;
    /*@
        loop invariant m <= i;
        loop invariant i <= n + 1;
        loop invariant (\forall integer j; (m) <= j <= (i-1) ==> (max) >= (list)[j]);
        loop invariant (\exists integer k; (m) <= k <= (i-1) && (max) == (list)[k]);
        loop invariant (0 <= (m) < (len) && (m) <= (n) < (len));
        loop assigns i, max;
        loop variant n - i + 1;
    */
    while (i <= n)
    {
        if (list[i] > max)
        {
            max = list[i];
        }
        i++;
    }
    return max;
}
