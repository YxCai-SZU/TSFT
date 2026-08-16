#include <stdbool.h>

/*@ requires 1 <= n <= 1000000;
    ensures \result == 1 || \result == 0;
    ensures \result == 1 ==> ((n) == 1 || (n) == 2 || (n) == 5 || (n) == 8);
    ensures \result == 0 ==> !((n) == 1 || (n) == 2 || (n) == 5 || (n) == 8);
*/
int func(int n)
{
    int ans;
    //@ assert 1 <= n <= 1000000;
    
    if (n == 1 || n == 2 || n == 5 || n == 8) {
        ans = 1;
    } else {
        ans = 0;
    }
    
    //@ assert ans == 1 || ans == 0;
    //@ assert ans == 1 ==> ((n) == 1 || (n) == 2 || (n) == 5 || (n) == 8);
    //@ assert ans == 0 ==> !((n) == 1 || (n) == 2 || (n) == 5 || (n) == 8);
    
    return ans;
}
