#include <stddef.h>

/*@
    requires 1 <= k <= 1000;
    requires 1 <= a <= b <= 1000;
    ensures \result == 0;
    ensures b / k >= a / k || b / k > a / k - 1;
*/
int func(size_t k, size_t a, size_t b) {
    //@ assert (1 <= (k) <= 1000 && 1 <= (a) <= (b) <= 1000);
    
    //@ ghost
    //@ assert b / k >= a / k || b / k > a / k - 1;
    
    return 0;
}

int main() {
    return 0;
}
