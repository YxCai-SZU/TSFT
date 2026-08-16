#include <limits.h>

/*@
    requires (1 <= (a) <= 10) && (1 <= (b) <= 10) && (1 <= (c) <= 10);
    ensures \result >= 0;
    ensures \result <= a + b + c;
    ensures \result == a + b || \result == b + c || \result == a + c;
    assigns \nothing;
*/
int func(int a, int b, int c)
{
    int result;
    int current_result;
    
    result = INT_MAX;
    
    //@ assert a + b >= 2 && a + b <= 20;
    current_result = (a + b < result) ? (a + b) : result;
    result = current_result;
    
    //@ assert b + c >= 2 && b + c <= 20;
    current_result = (b + c < result) ? (b + c) : result;
    result = current_result;
    
    //@ assert a + c >= 2 && a + c <= 20;
    current_result = (a + c < result) ? (a + c) : result;
    result = current_result;
    
    //@ assert result == a + b || result == b + c || result == a + c;
    return result;
}
