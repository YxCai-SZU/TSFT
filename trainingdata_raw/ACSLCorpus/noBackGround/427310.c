#include <stdint.h>

/*@
    requires (1 <= (n) <= 100000 && 0 <= (k) <= 1);
    ensures \result == ((k) == 0 ? (n) : (n) - 2);
    ensures \result == n - (k * 2) || \result == n;
*/
int64_t func(int64_t n, int64_t k)
{
    int64_t result;
    //@ assert (1 <= (n) <= 100000 && 0 <= (k) <= 1);
    
    if (k == 0)
    {
        result = n;
        //@ assert result == n;
    }
    else
    {
        //@ assert n - 2 == n - (k * 2) || n - 2 == n;
        result = n - 2;
    }
    
    //@ assert result == ((k) == 0 ? (n) : (n) - 2);
    return result;
}

#ifdef TESTING
#include <assert.h>

void test_input(void)
{
    int64_t n = 10;
    int64_t k = 0;
    int64_t result = func(n, k);
    assert(result == n);
}

void test_input2(void)
{
    int64_t n = 10;
    int64_t k = 1;
    int64_t result = func(n, k);
    assert(result == n - 2);
}

int main(void)
{
    test_input();
    test_input2();
    return 0;
}
#endif
