#include <stdint.h>

/*@
    requires (1 <= (X) <= 100000);
    ensures \result == 0 || \result == 1;
    ensures \result == ((\let n = (X) / 100;
        \let remained = (X) % 100;
        \let a = remained / 5;
        \let b = remained % 5;
        \let ans1 = (n >= 1 + a + b ? 1 : (n >= a + b ? 1 : (n >= b ? 1 : 0)));
        \let ans2 = (remained >= 5 ? 1 : 0);
        \let ans3 = ((X) / 100 >= 1 ? 1 : 0);
        ans1 + ans2 + ans3) >= 2 ? 1 : 0);
*/
int32_t func(uint64_t X)
{
    uint64_t n;
    uint64_t remained;
    uint64_t a;
    uint64_t b;
    int32_t ans;
    
    n = X / 100;
    remained = X % 100;
    a = remained / 5;
    b = remained % 5;
    ans = 0;
    
    //@ assert n == X / 100;
    //@ assert remained == X % 100;
    //@ assert a == remained / 5;
    //@ assert b == remained % 5;
    
    if (n >= 1 + a + b) {
        ans += 1;
    } else if (n >= a + b) {
        ans += 1;
    } else if (n >= b) {
        ans += 1;
    }
    
    //@ assert ans == (n >= 1 + a + b ? 1 : (n >= a + b ? 1 : (n >= b ? 1 : 0)));
    
    if (remained >= 5) {
        ans += 1;
    }
    
    //@ assert ans == (n >= 1 + a + b ? 1 : (n >= a + b ? 1 : (n >= b ? 1 : 0))) + (remained >= 5 ? 1 : 0);
    
    if (X / 100 >= 1) {
        ans += 1;
    }
    
    //@ assert ans == (\let n = (X) / 100;         \let remained = (X) % 100;         \let a = remained / 5;         \let b = remained % 5;         \let ans1 = (n >= 1 + a + b ? 1 : (n >= a + b ? 1 : (n >= b ? 1 : 0)));         \let ans2 = (remained >= 5 ? 1 : 0);         \let ans3 = ((X) / 100 >= 1 ? 1 : 0);         ans1 + ans2 + ans3);
    //@ assert ans >= 0;
    //@ assert ans <= 5;
    
    return (ans >= 2) ? 1 : 0;
}
