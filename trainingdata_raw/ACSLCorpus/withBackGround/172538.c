#include <stddef.h>

/*@
    logic integer compute_result(integer n) =
        100 * (n / 100) + ((n % 100) + 99) / 100;
*/

/*@
    requires 1 <= n <= 10000;
    assigns \nothing;
    ensures \result == compute_result(n);
*/
size_t func(size_t n)
{
    size_t result;
    //@ assert 1 <= n <= 10000;
    result = 100 * (n / 100) + ((n % 100) + 99) / 100;
    //@ assert result == compute_result(n);
    return result;
}

#ifdef TESTING
#include <assert.h>
int main()
{
    assert(func(123) == 123);
    assert(func(100) == 100);
    assert(func(99) == 100);
    assert(func(199) == 200);
    assert(func(9999) == 1000);
    return 0;
}
#endif
