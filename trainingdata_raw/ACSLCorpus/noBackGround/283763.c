#include <stdbool.h>

/*@ requires 0 <= a && a <= b && b <= c && c <= d && d <= e;
    requires b - a <= 123 && c - b <= 123 && d - c <= 123 && e - d <= 123;
    requires 0 <= k && k <= 123;
    ensures \result == (e - a <= k);
*/
bool func(int a, int b, int c, int d, int e, int k)
{
    int diff;
    //@ assert a >= 0 && b >= 0 && c >= 0 && d >= 0 && e >= 0;
    diff = e - a;
    //@ assert ((diff) == (e) - (a));
    
    if (diff <= k) {
        //@ assert diff <= k;
        return true;
    } else {
        //@ assert diff > k;
        return false;
    }
}
