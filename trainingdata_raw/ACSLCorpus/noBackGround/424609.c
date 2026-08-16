#include <stdbool.h>

/*@
    requires 1 <= n && n <= 100;
    requires 1 <= x && x <= 10000;
    requires \valid(lengths + (0..n-1));
    requires ((n) >= 1 && (n) <= 100 &&
        \forall integer i; 0 <= i < (n) ==> (lengths)[i] >= 1 && (lengths)[i] <= 100);
    ensures 1 <= \result && \result <= n + 1;
    ensures \result == 1 || x >= lengths[\result-2];
*/
int func(int n, int x, int *lengths)
{
    int di = 0;
    int i = 0;
    
    /*@
        loop invariant (0 <= (i) && (i) <= (n) &&
        1 <= (n) && (n) <= 100 &&
        1 <= (x) && (x) <= 10000 &&
        0 <= (di) &&
        (di) <= (i) * 100 &&
        (((n)) >= 1 && ((n)) <= 100 &&
        \forall integer i; 0 <= i < ((n)) ==> ((lengths))[i] >= 1 && ((lengths))[i] <= 100) &&
        ((i) > 0 ==> (x) >= (lengths)[(i)-1]));
        loop assigns i, di;
        loop variant n - i;
    */
    while (i < n)
    {
        int l = lengths[i];
        di += l;
        
        if (x < di)
        {
            //@ assert i+1 >= 1 && i+1 <= n+1;
            //@ assert i+1 == 1 || x >= lengths[i-1];
            return i + 1;
        }
        else if (i == n - 1)
        {
            //@ assert i+1 >= 1 && i+1 <= n+1;
            //@ assert i+1 == 1 || x >= lengths[i-1];
            return i + 1;
        }
        
        i += 1;
    }
    
    //@ assert i > 0;
    //@ assert x >= lengths[i-1];
    return n + 1;
}
