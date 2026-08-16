#include <stdbool.h>

/*@
    requires 1 <= n <= 1000000;
    requires 1 <= m <= 10000;
    requires \valid(p + (0..n-1));
    requires \valid(q + (0..m-1));
    requires (\forall integer i, j; 0 <= i < j < (n) ==> (p)[i] != (p)[j]);
    requires (\forall integer i, j; 0 <= i < j < (m) ==> (q)[i] != (q)[j]);
    requires (\forall integer i; 0 <= i < (n) ==> 1 <= (p)[i] <= 10000);
    requires (\forall integer i; 0 <= i < (m) ==> 1 <= (q)[i] <= 10000);
    ensures 0 <= \result <= m;
*/
int func(int n, int m, int *p, int *q)
{
    int count = 0;
    int index = 0;
    /*@
        loop invariant 0 <= index <= m;
        loop invariant 0 <= count <= index;
        loop assigns index, count;
        loop variant m - index;
    */
    while (index < m)
    {
        bool found = false;
        int p_index = 0;
        /*@
            loop invariant 0 <= p_index <= n;
            loop invariant found == false;
            loop assigns p_index, found;
            loop variant n - p_index;
        */
        while (p_index < n)
        {
            if (q[index] == p[p_index])
            {
                found = true;
                break;
            }
            p_index++;
        }
        if (found)
        {
            count++;
        }
        index++;
    }
    return count;
}
