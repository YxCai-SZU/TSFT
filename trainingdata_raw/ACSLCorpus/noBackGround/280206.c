#include <stddef.h>

/*@
    requires (1 <= (n) <= 100 && 1 <= (x) <= 100 && 1 <= (t) <= 100);
    ensures \result >= 0;
    ensures \result == (((n) / (x) + 1) * (t)) || \result == (((n) / (x)) * (t));
    assigns \nothing;
*/
size_t func(size_t n, size_t x, size_t t)
{
    // Variable declarations at scope top
    size_t ans;

    // Precondition-based assertions
    //@ assert 1 <= n <= 100 && 1 <= x <= 100 && 1 <= t <= 100;
    
    // Arithmetic bound verifications
    //@ assert n / x <= 100;
    //@ assert n / x + 1 <= 101;
    //@ assert n / x * t <= 10000;
    //@ assert (n / x + 1) * t <= 10100;

    if (n % x == 0) {
        ans = (n / x) * t;
        //@ assert ans == (((n) / (x)) * (t));
    } else {
        ans = (n / x + 1) * t;
        //@ assert ans == (((n) / (x) + 1) * (t));
    }

    // Postcondition verification
    //@ assert ans >= 0;
    //@ assert ans == (((n) / (x) + 1) * (t)) || ans == (((n) / (x)) * (t));

    return ans;
}

int main() {
    return 0;
}
