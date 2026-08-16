#include <stdbool.h>

/*@
    requires (1 <= (b) && (b) <= (a) && (a) <= 20 && 1 <= (c) && (c) <= 20);
    ensures \result >= 0;
    ensures \result <= c;
    ensures (a - b >= c) ==> \result == 0;
    ensures (a - b < c) ==> \result == c - (a - b);
*/
int func(int a, int b, int c)
{
    int ans;
    //@ assert (1 <= (b) && (b) <= (a) && (a) <= 20 && 1 <= (c) && (c) <= 20);
    
    if (a - b < c) {
        ans = c - (a - b);
        //@ assert ans == (((a) - (b) < (c)) ? ((c) - ((a) - (b))) : 0);
    } else {
        ans = 0;
        //@ assert ans == (((a) - (b) < (c)) ? ((c) - ((a) - (b))) : 0);
    }
    
    //@ assert ans >= 0;
    //@ assert ans <= c;
    //@ assert (a - b >= c) ==> ans == 0;
    //@ assert (a - b < c) ==> ans == c - (a - b);
    
    return ans;
}
