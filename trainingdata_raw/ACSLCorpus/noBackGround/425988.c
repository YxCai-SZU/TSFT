#include <limits.h>

/*@
    requires (0 <= (x) < 10) && (0 <= (y) < 10) && (0 <= (z) < 10);
    ensures \result == ((x) * 10 + (y) * 10 + (z) * 10);
    ensures 0 <= \result < 1000;
    assigns \nothing;
*/
int func(int x, int y, int z) {
    int result;
    
    //@ assert x * 10 >= 0;
    //@ assert y * 10 >= 0;
    //@ assert z * 10 >= 0;
    //@ assert x * 10 < 100;
    //@ assert y * 10 < 100;
    //@ assert z * 10 < 100;
    //@ assert x * 10 + y * 10 + z * 10 >= 0;
    //@ assert x * 10 + y * 10 + z * 10 < 1000;
    
    result = x * 10 + y * 10 + z * 10;
    return result;
}

int main() {
    return 0;
}
