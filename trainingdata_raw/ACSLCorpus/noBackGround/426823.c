#include <stdbool.h>

/*@
    requires (0 <= (x) <= 9 && 0 <= (a) <= 9);
    ensures (x < a ==> \result == 0) && (x >= a ==> \result == 10);
    assigns \nothing;
*/
int func(int x, int a)
{
    int ans;
    int i;
    
    //@ assert (0 <= (x) <= 9 && 0 <= (a) <= 9);
    
    if (x < a) {
        ans = 0;
    } else {
        ans = 10;
    }
    
    i = 0;
    /*@
        loop invariant 0 <= i <= 10;
        loop invariant (0 <= (x) <= 9 && 0 <= (a) <= 9);
        loop invariant ans == ((x) < (a) ? 0 : 10);
        loop assigns i;
        loop variant 10 - i;
    */
    while (i < 10)
    {
        // Dummy condition to match original logic
        if (x < a) {
            // Empty then branch
        } else {
            // Empty else branch
        }
        
        i = i + 1;
    }
    
    //@ assert (x < a ==> ans == 0) && (x >= a ==> ans == 10);
    return ans;
}

int main(void)
{
    return 0;
}
