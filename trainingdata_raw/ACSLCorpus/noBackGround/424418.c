#include <limits.h>

/*@
    requires (-1000 <= (a) <= 1000) && (-1000 <= (b) <= 1000);
    ensures \result == a + b || \result == a - b || \result == a * b;
    ensures \result >= a + b && \result >= a - b && \result >= a * b;
    assigns \nothing;
*/
int func(int a, int b)
{
    int sum;
    int diff;
    int prod;
    int res;
    
    //@ assert -1000 <= a && a <= 1000;
    //@ assert -1000 <= b && b <= 1000;
    
    sum = a + b;
    diff = a - b;
    
    //@ assert a * b >= -1000000;
    //@ assert a * b <= 1000000;
    
    prod = a * b;
    
    res = sum;
    
    if (diff > res) {
        res = diff;
    }
    
    if (prod > res) {
        res = prod;
    }
    
    //@ assert res == a + b || res == a - b || res == a * b;
    //@ assert res >= a + b;
    //@ assert res >= a - b;
    //@ assert res >= a * b;
    
    return res;
}
