#include <stdbool.h>

/*@
    requires 0 <= n;
    ensures \result == (n % 2 == 0);
*/
bool is_even_func(unsigned int n) {
    //@ assert n % 2 == 0 || n % 2 == 1;
    return n % 2 == 0;
}

/*@
    requires 0 <= a <= 100;
    requires 0 <= b <= 100;
    requires 0 <= c <= 100;
    ensures \result == (c <= a + b && c >= (a > b ? a - b : b - a));
*/
bool func(unsigned int a, unsigned int b, unsigned int c) {
    unsigned int ab;
    unsigned int apb;
    
    if (a > b) {
        ab = a - b;
    } else {
        ab = b - a;
    }
    apb = a + b;
    
    //@ assert ab == (a > b ? a - b : b - a);
    //@ assert apb == a + b;
    
    if (c <= apb && c >= ab) {
        return true;
    } else {
        return false;
    }
}

/*@
    requires 0 <= a <= 100;
    requires 0 <= b <= 100;
    requires 0 <= c <= 100;
    ensures \result == (c <= a + b && c >= (a > b ? a - b : b - a));
*/
bool func2(unsigned int a, unsigned int b, unsigned int c) {
    unsigned int ab;
    unsigned int apb;
    
    if (a > b) {
        ab = a - b;
    } else {
        ab = b - a;
    }
    apb = a + b;
    
    //@ assert apb == a + b;
    //@ assert ab == (a > b ? a - b : b - a);
    
    if (c <= apb && c >= ab) {
        return true;
    } else {
        return false;
    }
}

int main() {
    return 0;
}
