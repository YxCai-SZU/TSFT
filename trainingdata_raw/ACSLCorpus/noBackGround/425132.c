#include <stdbool.h>

/*@
    requires 0 <= a && a <= 123 && 0 <= b && b <= 123 && 0 <= c && c <= 123 && 
             0 <= d && d <= 123 && 0 <= e && e <= 123 && 0 <= k && k <= 123 && 
             ((a) < (b) && (b) < (c) && (c) < (d) && (d) < (e));
    ensures \result == (e - a <= k);
*/
bool func(long a, long b, long c, long d, long e, long k)
{
    long max;
    long min;
    
    max = a;
    min = a;
    
    //@ assert max == a && min == a;
    
    if (b > max) {
        max = b;
    }
    //@ assert max >= a && max >= b;
    
    if (c > max) {
        max = c;
    }
    //@ assert max >= a && max >= b && max >= c;
    
    if (d > max) {
        max = d;
    }
    //@ assert max >= a && max >= b && max >= c && max >= d;
    
    if (e > max) {
        max = e;
    }
    //@ assert max >= a && max >= b && max >= c && max >= d && max >= e;
    
    if (b < min) {
        min = b;
    }
    //@ assert min <= a && min <= b;
    
    if (c < min) {
        min = c;
    }
    //@ assert min <= a && min <= b && min <= c;
    
    if (d < min) {
        min = d;
    }
    //@ assert min <= a && min <= b && min <= c && min <= d;
    
    if (e < min) {
        min = e;
    }
    //@ assert min <= a && min <= b && min <= c && min <= d && min <= e;
    
    //@ assert max == e;
    //@ assert min == a;
    
    return max - min <= k;
}
