#include <stdbool.h>

/*@ requires 0 <= a <= 123;
    requires 0 <= b <= 123;
    requires 0 <= c <= 123;
    requires 0 <= d <= 123;
    requires 0 <= e <= 123;
    requires 0 <= k <= 123;
    requires ((a) < (b) && (b) < (c) && (c) < (d) && (d) < (e));
    ensures \result == true <==> (e - a <= k);
*/
bool func(int a, int b, int c, int d, int e, int k) {
    //@ assert ((a) < (b) && (b) < (c) && (c) < (d) && (d) < (e));
    //@ assert 0 <= a <= 123 && 0 <= e <= 123 && 0 <= k <= 123;
    //@ assert e - a <= k <==> (e - a <= k);
    return e - a <= k;
}
