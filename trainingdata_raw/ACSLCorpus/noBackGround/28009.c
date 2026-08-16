#include <stdbool.h>

/*@ requires (1 <= (r) <= 100);
    ensures \result == (3 * (r) * (r));
    assigns \nothing;
 */
int func(int r) {
    // Variable declarations at top of scope
    int result;
    
    //@ assert (1 <= (r) <= 100);
    
    result = 3 * r;
    
    //@ assert 3 * r <= 300;
    //@ assert 3 * r >= 3;
    
    result = result * r;
    
    //@ assert 3 * r * r <= 300 * 100;
    //@ assert 3 * r * r >= 3 * 1;
    
    return result;
}

#ifdef TEST
#include <assert.h>

void test_input(void) {
    int r = 1;
    int result = func(r);
    assert(result == 3 * r * r);
}
#endif
