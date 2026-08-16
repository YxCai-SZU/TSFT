#include <stdint.h>


int64_t func(int64_t X, int64_t A)
{
    int64_t result;
    //@ assert (0 <= (X) <= 9);
    //@ assert (0 <= (A) <= 9);
    if (X < A) {
        result = 0;
    } else {
        result = 10;
    }
    //@ assert result == ((X) < (A) ? 0 : 10);
    return result;
}

#ifdef TESTING
#include <assert.h>

int main()
{
    // Test 1
    assert(func(5, 8) == 0);
    // Test 2 - Note: This test violates the precondition (12 > 9)
    // assert(func(12, 5) == 10);
    // Test 3
    assert(func(0, 0) == 10);
    // Test 4
    assert(func(9, 9) == 10);
    // Test 5
    assert(func(5, 5) == 10);
    // Test 6
    assert(func(9, 0) == 10);
    // Test 7
    assert(func(0, 9) == 0);
    // Test 8
    assert(func(4, 4) == 10);
    return 0;
}
#endif
