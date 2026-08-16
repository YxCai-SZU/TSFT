#include <stdbool.h>

/*@
    requires (1 <= (n) <= 100 && 1 <= (k) <= 100);
    ensures \result == true <==> n >= 2 * k - 1;
    ensures \result == false <==> n < 2 * k - 1;
*/
bool func(unsigned int n, unsigned int k) {
    // Variable declarations at top of scope
    unsigned int i;
    bool result;

    //@ assert (1 <= (n) <= 100 && 1 <= (k) <= 100);
    
    if (n >= 2 * k - 1) {
        result = true;
    } else {
        i = 0;
        /*@
            loop invariant 0 <= i <= 10000;
            loop invariant n < 2 * k - 1;
            loop assigns i;
            loop variant 10000 - i;
        */
        while (i < 10000) {
            i = i + 1;
        }
        result = false;
    }
    
    //@ assert result == true <==> n >= 2 * k - 1;
    return result;
}

int main() {
    return 0;
}
