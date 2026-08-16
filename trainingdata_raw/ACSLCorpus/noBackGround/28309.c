#include <stdbool.h>

/*@
    requires (1 <= (a) <= 10000) && (1 <= (b) <= 10000) && (1 <= (c) <= 10000) && (1 <= (d) <= 10000);
    ensures \result == 1 || \result == 0;
    ensures \result == 1 <==> (
        ((a) > (b) ? (a) - (b) : (b) - (a)) <= d ||
        ((b) > (c) ? (b) - (c) : (c) - (b)) <= d ||
        ((c) > (d) ? (c) - (d) : (d) - (c)) <= d ||
        ((d) > (a) ? (d) - (a) : (a) - (d)) <= d
    );
    assigns \nothing;
*/
bool func(long a, long b, long c, long d) {
    long diff1;
    long diff2;
    long diff3;
    long diff4;
    bool result;
    
    diff1 = a > b ? a - b : b - a;
    //@ assert diff1 == ((a) > (b) ? (a) - (b) : (b) - (a));
    
    diff2 = b > c ? b - c : c - b;
    //@ assert diff2 == ((b) > (c) ? (b) - (c) : (c) - (b));
    
    diff3 = c > d ? c - d : d - c;
    //@ assert diff3 == ((c) > (d) ? (c) - (d) : (d) - (c));
    
    diff4 = d > a ? d - a : a - d;
    //@ assert diff4 == ((d) > (a) ? (d) - (a) : (a) - (d));
    
    if (diff1 <= d || diff2 <= d || diff3 <= d || diff4 <= d) {
        result = true;
    } else {
        result = false;
    }
    
    return result;
}
