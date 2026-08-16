#include <stdbool.h>

/*@
    requires (1 <= (n) <= 100 && 0 <= (m) <= (n));
    ensures \result == (n == m);
    assigns \nothing;
*/
bool func(int n, int m) {
    int i;
    
    // First loop
    i = 0;
    /*@
        loop invariant 0 <= i <= n;
        loop invariant (1 <= (n) <= 100 && 0 <= (m) <= (n));
        loop assigns i;
        loop variant n - i;
    */
    while (i < n) {
        //@ assert 0 <= i <= n;
        i++;
    }
    
    // Second loop
    i = 0;
    /*@
        loop invariant 0 <= i <= 10 * (n - m);
        loop invariant (1 <= (n) <= 100 && 0 <= (m) <= (n));
        loop assigns i;
        loop variant 10 * (n - m) - i;
    */
    while (i < 10 * (n - m)) {
        //@ assert 0 <= i <= 10 * (n - m);
        i++;
    }
    
    return n == m;
}

int main() {
    return 0;
}
