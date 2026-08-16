#include <stdbool.h>

/*@
    requires 1 <= a <= 500;
    requires 1 <= b <= 500;
    requires 1 <= c <= 1000;
    ensures \result == (c >= a + b && a + b >= 0);
*/
bool func(int a, int b, int c) {
    int sum;
    
    //@ assert (1 <= (a) <= 500 && 1 <= (b) <= 500);
    //@ assert ((a) + (b)) == a + b;
    
    sum = a + b;
    
    //@ assert c >= sum && sum >= 0 ==> c >= a + b && a + b >= 0;
    
    return c >= sum && sum >= 0;
}
