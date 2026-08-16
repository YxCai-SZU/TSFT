#include <limits.h>

/*@
    requires -100 <= a <= 100;
    requires -100 <= b <= 100;
    ensures \result == a + b || \result == a - b || \result == a * b;
    ensures \result >= a + b;
    ensures \result >= a - b;
    ensures \result >= a * b;
*/
int func(int a, int b)
{
    int sum;
    int diff;
    int prod;
    int res;

    //@ assert -100 <= a && a <= 100;
    //@ assert -100 <= b && b <= 100;
    
    sum = a + b;
    diff = a - b;
    
    //@ assert a >= -100 && a <= 100;
    //@ assert b >= -100 && b <= 100;
    //@ assert a * b >= -10000 && a * b <= 10000;
    
    prod = a * b;
    
    //@ assert sum >= a + b;
    //@ assert diff >= a - b;
    //@ assert prod >= a * b;
    //@ assert prod >= -10000 && prod <= 10000;
    
    if (sum > diff && sum > prod) {
        res = sum;
    } else if (diff > prod) {
        res = diff;
    } else {
        res = prod;
    }
    
    //@ assert res == a + b || res == a - b || res == a * b;
    //@ assert res >= a + b;
    //@ assert res >= a - b;
    //@ assert res >= a * b;
    
    return res;
}
