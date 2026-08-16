#include <stdint.h>

/*@
    requires (1 <= (r) <= 100);
    ensures \result == ((r) * (r));
    assigns \nothing;
*/
int32_t func(int32_t r) {
    // Declare all variables at scope top
    int32_t res;
    
    //@ assert (1 <= (r) <= 100);
    
    //@ assert 1 <= r * r <= 10000;
    
    res = r * r;
    
    //@ assert res == ((r) * (r));
    
    return res;
}

int main() {
    return 0;
}
