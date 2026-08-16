#include <stdbool.h>

/*@
    requires (3 <= (n) <= 100 &&
        1 <= (x) <= 10000 &&
        \valid((ls) + (0 .. (n)-1)) &&
        \forall integer j; 0 <= j < (n) ==> 1 <= (ls)[j] <= 100);
    ensures 1 <= \result <= n + 1;
    assigns \nothing;
*/
int func(int n, int x, int *ls)
{
    int l = 0;
    int i = 0;

    /*@
        loop invariant (0 <= (i) <= (n) &&
        0 <= (l) <= (i) * 100 &&
        (3 <= ((n)) <= 100 &&
        1 <= ((x)) <= 10000 &&
        \valid(((ls)) + (0 .. ((n))-1)) &&
        \forall integer j; 0 <= j < ((n)) ==> 1 <= ((ls))[j] <= 100) &&
        (i) <= (n) &&
        (l) <= (x) + 100);
        loop assigns i, l;
        loop variant n - i;
    */
    while (i < n)
    {
        //@ assert 0 <= i < n;
        l += ls[i];
        
        if (l > x)
        {
            //@ assert i + 1 >= 1;
            //@ assert i + 1 <= n + 1;
            return i + 1;
        }
        
        i++;
        //@ assert l <= x + 100;
    }
    
    //@ assert l <= x + 100;
    //@ assert n + 1 >= 1;
    //@ assert n + 1 <= n + 1;
    return n + 1;
}
