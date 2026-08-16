#include <limits.h>

/*@
    requires (1 <= (a) <= 10000) && (1 <= (b) <= 10000) && (1 <= (c) <= 10000) && (1 <= (d) <= 10000);
    ensures \result >= 0;
    ensures \result <= b + c;
    assigns \nothing;
*/
int func(int a, int b, int c, int d)
{
    int ans;
    int tmp_a;
    int tmp_b;
    int tmp_c;
    int min_val;
    
    ans = b < a ? b : a;
    tmp_a = a < b ? a : b;
    tmp_b = b < a ? b : a;
    tmp_c = c - tmp_a - tmp_b;
    
    //@ assert tmp_c == c - (a < b ? a : b) - (b < a ? b : a);
    
    ans += tmp_c < 0 ? 0 : tmp_c;
    tmp_c = tmp_c < 0 ? 0 : tmp_c;
    
    //@ assert ans >= 0;
    
    min_val = d < tmp_c ? d : tmp_c;
    ans -= min_val;
    
    //@ assert ans >= 0;
    
    return ans;
}
