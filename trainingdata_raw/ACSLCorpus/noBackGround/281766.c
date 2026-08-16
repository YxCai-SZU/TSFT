#include <stdint.h>

/*@
    requires (1 <= (r) <= 100);
    ensures \result == ((2 * (31415) * (r)) / (10000));
*/
int64_t func(int64_t r) {
    // Variable declarations at scope top
    int64_t precision_factor;
    int64_t pi;
    int64_t product;
    int64_t ans;
    int64_t remainder;
    
    precision_factor = 10000;
    pi = 31415;
    
    //@ assert ((precision_factor) == 10000);
    //@ assert ((pi) == 31415);
    
    //@ assert 2 * pi * r <= 9223372036854775807;
    
    product = 2 * pi * r;
    
    ans = 0;
    remainder = product;
    
    /*@
        loop invariant (1 <= (r) <= 100);
        loop invariant ((precision_factor) == 10000);
        loop invariant ((pi) == 31415);
        loop invariant product == (2 * (pi) * (r));
        loop invariant ans * precision_factor + remainder == product;
        loop invariant 0 <= remainder;
        loop assigns ans, remainder;
    */
    while (remainder >= precision_factor) {
        //@ assert remainder >= precision_factor;
        ans += 1;
        remainder -= precision_factor;
    }
    
    //@ assert ans * precision_factor + remainder == product;
    //@ assert remainder < precision_factor;
    //@ assert ans == ((2 * (pi) * (r)) / (precision_factor));
    
    return ans;
}

int main() {
    return 0;
}
