#include <limits.h>

/*@
    requires a > 0 && b > 0 && a <= 1000 && b <= 1000;
    ensures \result == (a + b) * b;
    assigns \nothing;
*/
int non_linear_arith_example19(int a, int b) {
    // Variable declarations at scope top
    int result;
    
    //@ assert ((a) > 0 && (b) > 0 && (a) <= 1000 && (b) <= 1000);
    
    //@ assert a * b >= 0;
    //@ assert a * b <= 1000000;
    
    //@ assert b * b >= 0;
    //@ assert b * b <= 1000000;
    
    //@ assert (a + b) * b <= 2000000;
    
    //@ assert (a + b) * b == a * b + b * b;
    
    result = (a + b) * b;
    return result;
}

int main() {
    return 0;
}
