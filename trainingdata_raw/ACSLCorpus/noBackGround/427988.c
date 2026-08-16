#include <stdbool.h>

/*@
    requires (1 <= (x) <= 100) && (1 <= (y) <= 100) && (1 <= (z) <= 100);
    ensures \result == true <==> x * y >= z;
    assigns \nothing;
*/
bool func(unsigned int x, unsigned int y, unsigned int z)
{
    // Variable declarations at scope top
    bool result;

    //@ assert (1 <= (x) <= 100);
    //@ assert (1 <= (y) <= 100);
    //@ assert (1 <= (z) <= 100);
    
    //@ assert ((x) * (y)) <= 10000;
    
    if (x * y < z) {
        result = false;
    } else {
        result = true;
    }
    
    //@ assert result == true <==> x * y >= z;
    return result;
}

#ifdef TESTING
#include <assert.h>

int main() {
    assert(func(10, 10, 100) == true);
    assert(func(10, 10, 101) == false);
    assert(func(1, 1, 1) == true);
    assert(func(100, 100, 10000) == true);
    return 0;
}
#endif
