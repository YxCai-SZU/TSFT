#include <limits.h>

/*@
    requires (-1000000000 <= (a) <= (b) <= 1000000000);
    requires (-1000000000 <= (c) <= (d) <= 1000000000);
    requires (-9223372036854775807 - 1 <= (a) <= 9223372036854775807);
    requires (-9223372036854775807 - 1 <= (b) <= 9223372036854775807);
    requires (-9223372036854775807 - 1 <= (c) <= 9223372036854775807);
    requires (-9223372036854775807 - 1 <= (d) <= 9223372036854775807);
    ensures \result == (\max(\max((a*c), (a*d)), \max((b*c), (b*d))));
    assigns \nothing;
*/
long long func(long long a, long long b, long long c, long long d) {
    long long max1;
    long long max2;
    long long result;
    
    //@ assert -1000000000000000000 <= a*c <= 1000000000000000000;
    
    if (a * c > a * d) {
        max1 = a * c;
    } else {
        max1 = a * d;
    }
    
    //@ assert -1000000000000000000 <= b*c <= 1000000000000000000;
    
    if (b * c > b * d) {
        max2 = b * c;
    } else {
        max2 = b * d;
    }
    
    if (max1 > max2) {
        result = max1;
    } else {
        result = max2;
    }
    
    return result;
}
