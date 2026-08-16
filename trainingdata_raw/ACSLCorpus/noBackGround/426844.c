#include <stdint.h>

/*@
    requires (1 <= (a) <= 100 && 1 <= (b) <= 100);
    ensures \result >= 0;
    ensures \result == ((a) > (b) * 2 ? (a) - (b) * 2 : 0);
    assigns \nothing;
*/
int64_t func(int64_t a, int64_t b)
{
    // Declare all variables at the top
    int64_t result;
    
    //@ assert (1 <= (a) <= 100 && 1 <= (b) <= 100);
    
    if (a > b * 2) {
        result = a - b * 2;
    } else {
        result = 0;
    }
    
    //@ assert result >= 0;
    //@ assert result == ((a) > (b) * 2 ? (a) - (b) * 2 : 0);
    
    return result;
}

/* Test functions */
#ifdef TESTING
#include <assert.h>

void test1(void) {
    assert(func(10, 5) == 0);
}

void test2(void) {
    assert(func(3, 2) == 0);
}

void test3(void) {
    assert(func(9, 2) == 1);
}

void test4(void) {
    assert(func(1, 1) == 0);
}

void test5(void) {
    assert(func(100, 50) == 0);
}

void test6(void) {
    assert(func(100, 35) == 30);
}
#endif
