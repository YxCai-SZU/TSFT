#include <stdbool.h>

/*@
    requires (1 <= (n) <= 100 && 0 <= (m) <= (n));
    ensures \result == (n == m);
*/
bool func(unsigned int n, unsigned int m) {
    //@ assert n == m ==> n == m;
    return n == m;
}

/*@
    requires (1 <= (x) <= 100 && 0 <= (y) <= (x));
    ensures \result == (x == y);
*/
bool func2(int x, int y) {
    //@ assert x == y ==> x == y;
    return x == y;
}

/*@
    requires (1 <= (a) <= 100 && 1 <= (b) <= 100 && 0 <= (c) <= (a) && 0 <= (d) <= (b));
    ensures \result == (a * b == c * d);
*/
bool func3(int a, int b, int c, int d) {
    int ab_product;
    int cd_product;
    
    ab_product = a * b;
    cd_product = c * d;
    
    //@ assert 1 <= ab_product <= 10000;
    //@ assert 0 <= cd_product <= 10000;
    
    return ab_product == cd_product;
}
