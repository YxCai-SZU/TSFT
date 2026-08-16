#include <stdint.h>

/*@
    requires (1 <= (a) <= 10000) && (1 <= (b) <= 10000);
    ensures \result == a + b;
    ensures \result <= 20000;
*/
int32_t func(int32_t a, int32_t b) {
    //@ assert (1 <= (a) <= 10000);
    //@ assert (1 <= (b) <= 10000);
    
    int32_t sum;
    sum = a + b;
    
    //@ assert sum == a + b;
    //@ assert sum <= 20000;
    
    return sum;
}

int main() {
    return 0;
}
