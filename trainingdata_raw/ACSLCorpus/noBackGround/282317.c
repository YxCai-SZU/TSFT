#include <limits.h>

/*@
    requires (-1000 <= (a) <= 1000) && (-1000 <= (b) <= 1000);
    ensures \result == ((a) + (b)) || 
            \result == ((a) - (b)) || 
            \result == ((a) * (b));
    ensures \result >= ((a) + (b));
    ensures \result >= ((a) - (b));
    ensures \result >= ((a) * (b));
*/
int func(int a, int b) {
    int sum;
    int diff;
    int prod;
    int result;
    
    //@ assert (-1000 <= (a) <= 1000);
    //@ assert (-1000 <= (b) <= 1000);
    
    sum = a + b;
    diff = a - b;
    
    //@ assert -1000000 <= a * b <= 1000000;
    prod = a * b;
    
    if (sum > diff && sum > prod) {
        result = sum;
    } else if (diff > prod) {
        result = diff;
    } else {
        result = prod;
    }
    
    //@ assert result >= ((a) + (b));
    //@ assert result >= ((a) - (b));
    //@ assert result >= ((a) * (b));
    
    return result;
}
