#include <stdbool.h>

/*@
    requires (1 <= (k) <= 100 && 1 <= (x) <= 100000);
    ensures \result == (k * 500 >= x);
    assigns \nothing;
*/
bool func(unsigned int k, unsigned int x) {
    // Variable declarations at top of scope
    const unsigned int en = 500;
    unsigned int high = 0;
    unsigned int i = 1;
    
    /*@
        loop invariant 1 <= i <= k + 1;
        loop invariant high == (i - 1) * en;
        loop invariant high <= k * en;
        loop assigns high, i;
        loop variant k - i + 1;
    */
    while (i <= k) {
        //@ assert high + en == i * en;
        high += en;
        i += 1;
    }
    
    //@ assert high == k * en;
    return high >= x;
}

int main() {
    return 0;
}
