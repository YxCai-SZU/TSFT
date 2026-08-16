#include <stdint.h>

/*@ requires (1 <= (n) <= 100 &&
      0 <= (a) <= (n) * (n));
    ensures \result == n * n - a;
    assigns \nothing;
*/
int32_t func(int32_t n, int32_t a) {
    // Variable declarations at top of scope
    int32_t b;
    
    //@ assert 1 <= n;
    //@ assert n <= 100;
    //@ assert 0 <= a;
    //@ assert a <= n * n;
    //@ assert 0 <= n * n;
    //@ assert n * n <= 100 * 100;
    
    b = n * n - a;
    return b;
}

int main() {
    return 0;
}
