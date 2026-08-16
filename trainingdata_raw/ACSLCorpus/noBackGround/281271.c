#include <limits.h>

/*@
    requires (-100 <= (a) <= 100) && (-100 <= (b) <= 100);
    ensures \result == ((a) + (b)) || \result == ((a) - (b)) || \result == ((a) * (b));
    ensures \result >= ((a) + (b));
    ensures \result >= ((a) - (b));
    ensures \result >= ((a) * (b));
    assigns \nothing;
*/
int func(int a, int b) {
    int sum;
    int diff;
    int prod;
    int ans;
    
    //@ assert (-100 <= (a) <= 100) && (-100 <= (b) <= 100);
    
    sum = a + b;
    diff = a - b;
    
    //@ assert -10000 <= a * b <= 10000;
    prod = a * b;
    
    if (sum > diff && sum > prod) {
        ans = sum;
    } else if (diff > prod) {
        ans = diff;
    } else {
        ans = prod;
    }
    
    //@ assert ans == ((a) + (b)) || ans == ((a) - (b)) || ans == ((a) * (b));
    //@ assert ans >= ((a) + (b));
    //@ assert ans >= ((a) - (b));
    //@ assert ans >= ((a) * (b));
    
    return ans;
}
