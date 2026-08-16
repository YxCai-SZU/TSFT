#include <stdint.h>

/*@
    requires (1 <= (n) && (n) <= 100000);
    ensures \result >= 0;
    ensures \result < 1000;
    ensures \result == ((n) % 1000 == 0 ? 0 : 1000 - ((n) % 1000));
*/
int32_t func(uint32_t n)
{
    uint32_t num;
    uint32_t amari;
    int32_t ans;

    num = n / 1000;
    amari = n % 1000;

    //@ assert amari == n % 1000;

    if (amari == 0) {
        ans = 0;
        //@ assert ans == 0;
    } else {
        ans = 1000 - amari;
        //@ assert ans == 1000 - amari;
    }

    //@ assert ans >= 0;
    //@ assert ans < 1000;
    //@ assert ans == ((n) % 1000 == 0 ? 0 : 1000 - ((n) % 1000));

    return ans;
}
