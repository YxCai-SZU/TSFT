#include <stdbool.h>

/*@
    requires 1 <= a <= 9;
    requires 1 <= b <= 9;
    requires 1 <= c <= 9;
    ensures \result == (((a) * 100 + (b) * 10 + (c)) % 4 == 0);
*/
bool func(int a, int b, int c)
{
    int sum;
    bool is_divisible;
    int abs_sum;
    int remainder;
    
    sum = a * 100 + b * 10 + c;
    is_divisible = false;
    abs_sum = sum;
    
    //@ assert sum >= 111 && sum <= 999;
    
    if (sum < 0)
    {
        abs_sum = -sum;
    }
    
    //@ assert abs_sum >= 0;
    
    remainder = abs_sum;
    
    /*@
        loop invariant 0 <= remainder <= abs_sum;
        loop invariant remainder % 4 == abs_sum % 4;
        loop assigns remainder;
        loop variant remainder;
    */
    while (remainder >= 4)
    {
        remainder -= 4;
    }
    
    //@ assert remainder == abs_sum % 4;
    
    if (remainder == 0)
    {
        is_divisible = true;
    }
    
    //@ assert is_divisible == (abs_sum % 4 == 0);
    //@ assert is_divisible == (((a) * 100 + (b) * 10 + (c)) % 4 == 0);
    
    return is_divisible;
}
