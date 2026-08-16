#include <stdbool.h>

/*@
    requires 1 <= n <= 100;
    requires 0 <= m <= n;
    ensures \result == (n == m);
*/
bool func(int n, int m) {
    int a;
    int b;
    bool is_equal;
    int temp_n;
    int temp_m;
    int temp_result;
    
    a = n;
    b = m;
    is_equal = false;
    
    temp_n = n;
    temp_m = m;
    temp_result = 0;
    
    if (temp_n >= temp_m) {
        temp_result = temp_n - temp_m;
    } else {
        temp_result = temp_m - temp_n;
    }
    
    if (temp_result == 0) {
        is_equal = true;
    }
    
    //@ assert is_equal == (n == m);
    
    return is_equal;
}
