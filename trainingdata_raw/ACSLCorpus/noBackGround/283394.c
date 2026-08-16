#include <stdbool.h>
#include <limits.h>

/*@ requires 1 <= n <= 100;
    requires 0 <= a <= n * n;
    ensures \result == n * n - a;
    assigns \nothing;
*/
int func(int n, int a) {
    //@ assert 0 <= n * n;
    //@ assert n * n <= 10000;
    
    return n * n - a;
}

int main() {
    int v[3] = {1, 3, 5};
    
    //@ assert (\forall integer i, j; 0 <= i <= j < (3) ==> (&v[0])[i] <= (&v[0])[j]);
    //@ assert (\forall integer i; 0 <= i < (3) ==> (&v[0])[i] > 0);
    
    return 0;
}
