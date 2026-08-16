#include <stdint.h>

/*@
    requires (1 <= (N) <= 1000);
    ensures \result == N * N;
    assigns \nothing;
*/
uint64_t func(uint64_t N)
{
    uint64_t ans = 0;
    uint64_t i = 0;
    
    /*@
        loop invariant 0 <= i <= N;
        loop invariant ans == 0;
        loop assigns i, ans;
        loop variant N - i;
    */
    while (i < N)
    {
        i = i + 1;
        //@ assert i <= N;
    }
    
    //@ assert N * N <= 1000000;
    ans = N * N;
    return ans;
}

int main()
{
    return 0;
}
