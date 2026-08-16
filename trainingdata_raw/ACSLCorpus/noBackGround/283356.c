#include <stddef.h>

/*@
    requires (1 <= (n) && (n) <= 10000);
    ensures \result == (((n) / 500) * 1000 + (((n) % 500) / 5) * 5);
    assigns \nothing;
*/
size_t func(size_t n) {
    size_t ans;
    size_t temp;

    ans = 0;
    ans += (n / 500) * 1000;
    temp = n - (n / 500) * 500;

    //@ assert 0 <= temp && temp <= 500;
    ans += (temp / 5) * 5;

    //@ assert ans == (n / 500) * 1000 + ((n % 500) / 5) * 5;
    return ans;
}
