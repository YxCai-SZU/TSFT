#include <stddef.h>

/*@
    requires (2 <= (n) && (n) <= 100000);
    ensures \result == ((((n)) / 2) + (((n)) % 2));
    ensures \result >= 1;
*/
size_t func(size_t n)
{
    size_t half_n;
    size_t is_odd;
    size_t res;

    half_n = n / 2;
    is_odd = n % 2;
    //@ assert half_n == ((n) / 2);
    //@ assert is_odd == ((n) % 2);
    //@ assert ((((n)) / 2) + (((n)) % 2)) == half_n + is_odd;
    //@ assert 1 <= half_n + is_odd && half_n + is_odd <= n;
    res = half_n + is_odd;
    return res;
}

int main()
{
    return 0;
}
