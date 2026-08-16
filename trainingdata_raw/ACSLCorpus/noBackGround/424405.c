#include <stdbool.h>

/*@ requires 1 <= n <= 100;
    requires 1 <= k <= 100;
    ensures \result == (n / 2 >= k) || (n % 2 == 1 && n / 2 + 1 >= k);
*/
bool func(unsigned int n, unsigned int k) {
    unsigned int half_n;
    
    if (n % 2 == 0) {
        half_n = n / 2;
    } else {
        half_n = n / 2 + 1;
    }
    
    //@ assert (((n) % 2 == 0 && (half_n) == (n) / 2) ||       ((n) % 2 == 1 && (half_n) == (n) / 2 + 1));
    //@ assert half_n == n / 2 || (n % 2 == 1 && half_n == n / 2 + 1);
    
    return half_n >= k;
}
