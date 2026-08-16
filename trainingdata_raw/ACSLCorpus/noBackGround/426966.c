#include <stddef.h>

/*@
requires x != y;
ensures \result == 0;
assigns \nothing;
*/
int max_exclusive_proof(size_t x, size_t y) {
    //@ assert ((x) != (y));
    
    if (x > y) {
        //@ assert x > y;
    } else {
        //@ assert y > x;
    }
    
    return 0;
}

int main() {
    return 0;
}
