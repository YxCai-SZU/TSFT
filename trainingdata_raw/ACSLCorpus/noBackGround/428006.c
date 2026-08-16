#include <stddef.h>

/*@
    requires (0 <= (A) && (A) <= 100 &&
        0 <= (P) && (P) <= 100);
    ensures \result == (((A) * 3 + (P)) / 2);
    assigns \nothing;
*/
size_t func(size_t A, size_t P)
{
    size_t ans;

    //@ assert (0 <= (A) && (A) <= 100 &&         0 <= (P) && (P) <= 100);
    ans = (A * 3 + P) / 2;
    //@ assert ans == (((A) * 3 + (P)) / 2);
    return ans;
}

#ifdef TESTING
#include <assert.h>

int main()
{
    assert(func(1, 5) == 7);
    assert(func(2, 3) == 7);
    assert(func(3, 2) == 8);
    assert(func(4, 1) == 9);
    assert(func(5, 0) == 10);
    return 0;
}
#endif
