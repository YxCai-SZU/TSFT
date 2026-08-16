#include <stdbool.h>

/*@
    requires 0 <= a < b < c < d < e <= 123;
    requires 0 <= k <= 123;
    ensures \result == 1 <==> ((b) - (a) <= (k) && (c) - (a) <= (k) && (d) - (a) <= (k) && (e) - (a) <= (k));
*/
bool func(int a, int b, int c, int d, int e, int k)
{
    int flag = 0;
    
    //@ assert 0 <= a < b < c < d < e <= 123;
    
    if (b - a > k) {
        flag += 1;
    }
    if (c - a > k) {
        flag += 1;
    }
    if (d - a > k) {
        flag += 1;
    }
    if (e - a > k) {
        flag += 1;
    }
    
    //@ assert flag >= 0 && flag <= 4;
    
    return flag == 0;
}
