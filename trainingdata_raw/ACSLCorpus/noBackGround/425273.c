#include <limits.h>

/*@
    requires (-100 <= (a) <= 100) && (-100 <= (b) <= 100);
    ensures \result == ((a) + (b)) || 
            \result == ((a) - (b)) || 
            \result == ((a) * (b));
    ensures \result >= ((a) + (b));
    ensures \result >= ((a) - (b));
    ensures \result >= ((a) * (b));
    assigns \nothing;
*/
int func(int a, int b) {
    int sum;
    int diff;
    int prod;
    int res;
    
    //@ assert (-100 <= (a) <= 100) && (-100 <= (b) <= 100);
    
    sum = a + b;
    //@ assert sum == ((a) + (b));
    
    diff = a - b;
    //@ assert diff == ((a) - (b));
    
    //@ assert -10000 <= a * b <= 10000;
    prod = a * b;
    //@ assert prod == ((a) * (b));
    
    if (sum > diff && sum > prod) {
        res = sum;
        //@ assert res == ((a) + (b));
    } else if (diff > prod) {
        res = diff;
        //@ assert res == ((a) - (b));
    } else {
        res = prod;
        //@ assert res == ((a) * (b));
    }
    
    //@ assert res >= ((a) + (b));
    //@ assert res >= ((a) - (b));
    //@ assert res >= ((a) * (b));
    
    return res;
}
