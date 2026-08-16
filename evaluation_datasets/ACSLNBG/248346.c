#include <limits.h>


int func(int a, int b) {
    // Variable declarations at top of scope
    int result;

    //@ assert (1 <= (a) <= 100);
    //@ assert (1 <= (b) <= 100);
    //@ assert a * b <= 100 * 100;
    //@ assert a * b >= 1 * 1;
    
    result = a * b;
    return result;
}
