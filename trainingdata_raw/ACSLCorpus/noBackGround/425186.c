#include <stdbool.h>

/*@
    requires 1 <= a <= 123;
    requires 1 <= b <= 123;
    requires 1 <= c <= 123;
    requires 1 <= d <= 123;
    requires 1 <= e <= 123;
    ensures \result == (
        (a < d && b < e && c > 0) ||
        (a > d && a < e && b < c && b < e && c < d) ||
        (a < d && b < e && c > 0 && a < e && b < c && b < d)
    );
    assigns \nothing;
*/
bool func(int a, int b, int c, int d, int e) {
    bool result = false;
    bool condition1;
    bool condition2;
    bool condition3;

    condition1 = (a < d) && (b < e) && (c > 0);
    //@ assert condition1 == (a < d && b < e && c > 0);
    
    condition2 = (a > d) && (a < e) && (b < c) && (b < e) && (c < d);
    //@ assert condition2 == (a > d && a < e && b < c && b < e && c < d);
    
    condition3 = (a < d) && (b < e) && (c > 0) && (a < e) && (b < c) && (b < d);
    //@ assert condition3 == (a < d && b < e && c > 0 && a < e && b < c && b < d);
    
    result = condition1 || condition2 || condition3;
    //@ assert result == (condition1 || condition2 || condition3);
    
    return result;
}
