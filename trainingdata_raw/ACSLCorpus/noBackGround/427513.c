#include <stdbool.h>

/*@
    requires (1 <= (a) <= 100) && (1 <= (b) <= 100);
    ensures \result == ((a + b) % 3 == 0);
*/
bool func(int a, int b)
{
    int sum;
    bool is_multiple;
    int temp_sum;
    
    sum = a + b;
    is_multiple = false;
    temp_sum = sum;
    
    /*@
        loop invariant 1 <= a <= 100;
        loop invariant 1 <= b <= 100;
        loop invariant 0 <= temp_sum <= sum;
        loop invariant sum == a + b;
        loop invariant temp_sum % 3 == sum % 3;
        loop assigns temp_sum;
    */
    while (temp_sum >= 3)
    {
        temp_sum -= 3;
    }
    
    if (temp_sum == 0)
    {
        is_multiple = true;
    }
    
    //@ assert is_multiple == ((a + b) % 3 == 0);
    
    return is_multiple;
}
