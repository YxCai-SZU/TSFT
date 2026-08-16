#include <stdint.h>

/*@
    requires (0 <= (a) && (a) < 100);
    ensures \result == ((a) * (a) * (a));
    assigns \nothing;
*/
uint32_t func(uint32_t a)
{
    // Variable declarations at scope top
    uint32_t a2;
    uint32_t a3;

    //@ assert (0 <= (a) && (a) < 100);
    //@ assert 0 <= a && a < 100;

    //@ assert 0 <= a * a && a * a < 10000;
    a2 = a * a;

    //@ assert 0 <= a2 * a && a2 * a < 1000000;
    a3 = a2 * a;

    //@ assert a3 == ((a) * (a) * (a));
    return a3;
}

int main()
{
    // Variable declarations at scope top
    uint32_t array[4] = {1, 2, 3, 4};
    uint32_t result;

    result = func(1);
    return 0;
}
