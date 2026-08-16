#include <stdbool.h>

/*@
    requires \valid(a + (0..1));
    requires (-100 <= (a[0]) && (a[0]) <= 100) && (-100 <= (a[1]) && (a[1]) <= 100);
    ensures (-10000 <= (\result) && (\result) <= 10000);
    ensures \result == a[0] + a[1] || \result == a[0] - a[1] || \result == a[0] * a[1];
*/
int func(int a[2]) {
    int max;
    int result;
    
    //@ assert (-100 <= (a[0]) && (a[0]) <= 100);
    //@ assert (-100 <= (a[1]) && (a[1]) <= 100);
    
    if (a[0] + a[1] > a[0] - a[1]) {
        max = a[0] + a[1];
    } else {
        max = a[0] - a[1];
    }
    
    //@ assert (-10000 <= (a[0] * a[1]) && (a[0] * a[1]) <= 10000);
    //@ assert (-10000 <= (max) && (max) <= 10000);
    
    if (max > a[0] * a[1]) {
        result = max;
    } else {
        result = a[0] * a[1];
    }
    
    return result;
}
