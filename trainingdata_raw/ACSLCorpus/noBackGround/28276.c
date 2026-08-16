#include <stdbool.h>

/*@
    requires (0 <= (A) && (A) <= 100 &&
        0 <= (P) && (P) <= 100);
    ensures \result >= 0;
    ensures \result <= A * 3 + P;
*/
int func(int A, int P)
{
    int sum;
    int ans;
    bool is_even;
    
    sum = A * 3 + P;
    ans = 0;
    is_even = true;
    
    /*@
        loop invariant 0 <= A && A <= 100;
        loop invariant 0 <= P && P <= 100;
        loop invariant 0 <= sum;
        loop invariant sum <= A * 3 + P;
        loop invariant ans >= 0;
        loop invariant ans <= (A * 3 + P - sum) / 2;
        loop assigns sum, ans, is_even;
        loop variant sum;
    */
    while (sum >= 2 && is_even)
    {
        //@ assert sum >= 2;
        sum -= 2;
        ans += 1;
        is_even = (sum & 1) == 0;
    }
    
    //@ assert ans <= A * 3 + P;
    return ans;
}
