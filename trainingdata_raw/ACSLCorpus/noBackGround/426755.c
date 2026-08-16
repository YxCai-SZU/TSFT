#include <stdbool.h>

/*@
    requires (1 <= (k) <= 100 && 1 <= (x) <= 100000);
    ensures \result == (k * 500 >= x);
    assigns \nothing;
*/
bool func(unsigned int k, unsigned int x) {
    unsigned int t = 500;
    unsigned int sum = 0;
    unsigned int i = 0;
    
    /*@
        loop invariant 0 <= i <= k;
        loop invariant sum == ((i) * (t));
        loop invariant 1 <= k <= 100;
        loop invariant 1 <= x <= 100000;
        loop invariant t == 500;
        loop invariant sum <= 50000;
        loop assigns sum, i;
        loop variant k - i;
    */
    while (i < k) {
        //@ assert sum + t == ((i + 1) * (t));
        sum += t;
        i += 1;
    }
    
    //@ assert sum == k * 500;
    return sum >= x;
}

