#include <stdbool.h>

/*@ requires (1 <= (a) <= 100) && (1 <= (b) <= 100) && (1 <= (c) <= 100);
    ensures \result == ((a + b + 1) >= c);
    assigns \nothing;
*/
bool func(long a, long b, long c) {
    long sum;
    
    //@ assert (1 <= (a) <= 100);
    //@ assert (1 <= (b) <= 100);
    //@ assert (1 <= (c) <= 100);
    
    if (a + b >= c - 1) {
        sum = a + b + 1;
    } else {
        sum = a + b;
    }
    
    //@ assert sum == (((a) + (b) >= (c) - 1) ? (a) + (b) + 1 : (a) + (b));
    //@ assert (((((a)) + ((b)) >= ((c)) - 1) ? ((a)) + ((b)) + 1 : ((a)) + ((b))) >= (c)) <==> ((a + b + 1) >= c);
    
    return sum >= c;
}
