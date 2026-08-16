#include <stdbool.h>

/*@
    requires 1 <= x <= 100;
    requires 1 <= y <= 100;
    ensures \result == (y % 2 == 0);
*/
bool func(int x, int y) {
    bool is_even;
    int n;
    
    if (y >= 0) {
        n = y;
        /*@
            loop invariant 0 <= n <= y;
            loop invariant n % 2 == y % 2;
            loop assigns n;
            loop variant n;
        */
        while (n >= 2) {
            n -= 2;
        }
        //@ assert n == 0 ==> y % 2 == 0;
        is_even = (n == 0);
    } else {
        n = y;
        /*@
            loop invariant n <= y <= 0;
            loop invariant n % 2 == y % 2;
            loop assigns n;
            loop variant -n;
        */
        while (n <= -2) {
            n += 2;
        }
        //@ assert n == 0 ==> y % 2 == 0;
        is_even = (n == 0);
    }
    
    return is_even;
}

int main() {
    return 0;
}
