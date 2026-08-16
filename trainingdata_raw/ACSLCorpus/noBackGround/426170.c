#include <stdint.h>

/*@
    requires (1 <= (n) && (n) <= 1000000000);
    ensures \result == (((n) * ((n) - 1)) / 2);
    assigns \nothing;
*/
uint64_t func(uint64_t n) {
    // Variable declarations at scope top
    uint64_t result;
    uint64_t count;
    
    //@ assert (1 <= (n) && (n) <= 1000000000);
    
    //@ assert n * (n - 1) <= 1000000000 * 999999999;
    
    result = n * (n - 1);
    count = 0;
    
    /*@
        loop invariant 1 <= n && n <= 1000000000;
        loop invariant 0 <= count <= (((n) * ((n) - 1)) / 2);
        loop invariant result == n * (n - 1) - 2 * count;
        loop assigns result, count;
        loop variant result;
    */
    while (result >= 2) {
        result -= 2;
        count += 1;
    }
    
    return count;
}

int main() {
    return 0;
}
