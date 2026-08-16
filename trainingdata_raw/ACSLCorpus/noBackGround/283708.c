#include <stdbool.h>

/*@ requires 0 <= a <= 123 && 0 <= b <= 123 && 0 <= c <= 123;
    requires 0 <= d <= 123 && 0 <= e <= 123 && 0 <= k <= 123;
    requires a < b && b < c && c < d && d < e;
    ensures \result == ((b - a <= k) || (c - a <= k) || (d - a <= k) ||
                       (e - a <= k) || (b - e <= k) || (c - e <= k) || (d - e <= k));
*/
bool func(int a, int b, int c, int d, int e, int k)
{
    bool ok = false;
    
    //@ assert ((a) < (b) && (b) < (c) && (c) < (d) && (d) < (e));
    
    if (b - a <= k) {
        ok = true;
        //@ assert ok == true;
    } else if (c - a <= k) {
        ok = true;
        //@ assert ok == true;
    } else if (d - a <= k) {
        ok = true;
        //@ assert ok == true;
    } else if (e - a <= k) {
        ok = true;
        //@ assert ok == true;
    } else if (b - e <= k) {
        ok = true;
        //@ assert ok == true;
    } else if (c - e <= k) {
        ok = true;
        //@ assert ok == true;
    } else if (d - e <= k) {
        ok = true;
        //@ assert ok == true;
    }
    
    //@ assert ok == ((b - a <= k) || (c - a <= k) || (d - a <= k) || (e - a <= k) || (b - e <= k) || (c - e <= k) || (d - e <= k));
    return ok;
}
