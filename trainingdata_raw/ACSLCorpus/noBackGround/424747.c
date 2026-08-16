#include <stdint.h>

/*@
    requires 1 <= n <= 100;
    requires 1 <= k <= 100;
    ensures \result >= 0;
    ensures \result <= n;
*/
int32_t func(uint32_t n, uint32_t k) {
    int32_t result;
    
    if (n % k == 0) {
        result = 0;
    } else {
        //@ assert n <= 100;
        result = 1;
    }
    
    return result;
}

int main() {
    int32_t v[3] = {2, 3, 2};
    
    //@ assert ((3) > 0 ==> (&v[0])[0] == (&v[0])[(3) - 1]);
    
    return 0;
}
