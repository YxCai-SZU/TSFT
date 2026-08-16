#include <stdint.h>

/*@
    requires (1 <= (n) <= 100 && 1 <= (k) <= 100);
    ensures \result >= 0;
    ensures \result <= n;
    ensures \result == ((n) % (k) == 0 ? 0 : 1);
*/
int32_t func(uint32_t n, uint32_t k) {
    // Variable declarations at top of scope
    int32_t result;
    
    //@ assert (1 <= (n) <= 100 && 1 <= (k) <= 100);
    
    if (n % k == 0) {
        result = 0;
    } else {
        //@ assert 1 <= n && n <= 100;
        //@ assert 1 <= k && k <= 100;
        result = 1;
    }
    
    //@ assert result >= 0;
    //@ assert result <= n;
    return result;
}

#ifdef TEST
#include <assert.h>

int main() {
    // Test cases from original Rust code
    assert(func(3, 3) == 0);
    assert(func(3, 4) == 1);
    assert(func(10, 5) == 0);
    assert(func(11, 5) == 1);
    assert(func(100, 1) == 0);
    assert(func(1, 100) == 1);
    return 0;
}
#endif
