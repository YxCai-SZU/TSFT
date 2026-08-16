#include <stdbool.h>

/*@
    requires (1 <= (a) <= 100) && (1 <= (b) <= 100) && (1 <= (c) <= 100) && (1 <= (d) <= 100);
    ensures \result == (((a) + (c)) >= ((b) + (d)));
    assigns \nothing;
*/
bool func(int a, int b, int c, int d)
{
    int sum_a_c;
    int sum_b_d;
    bool result;
    
    //@ assert 1 <= a + c <= 200;
    sum_a_c = a + c;
    
    //@ assert 1 <= b + d <= 200;
    sum_b_d = b + d;
    
    result = sum_a_c >= sum_b_d;
    return result;
}
