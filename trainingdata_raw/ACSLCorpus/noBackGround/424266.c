#include <stdbool.h>

/*@
    requires 1 <= a <= 100;
    requires 1 <= b <= 100;
    ensures \result == true <==> (a + b) % 2 == 0;
    ensures \result == false <==> (a + b) % 2 != 0;
    assigns \nothing;
*/
bool func(int a, int b)
{
    int sum;
    bool is_even;
    int abs_sum;
    int temp;
    
    sum = a + b;
    is_even = true;
    abs_sum = sum;
    
    //@ assert sum == a + b;
    
    if (sum < 0)
    {
        abs_sum = -sum;
    }
    
    //@ assert abs_sum == ((sum) >= 0 ? (sum) : -(sum));
    
    temp = abs_sum;
    
    /*@
        loop invariant 0 <= temp <= abs_sum;
        loop invariant temp % 2 == abs_sum % 2;
        loop assigns temp;
        loop variant temp;
    */
    while (temp >= 2)
    {
        temp -= 2;
        //@ assert temp % 2 == abs_sum % 2;
    }
    
    //@ assert -1 <= temp % 2 <= 1;
    
    if (temp != 0)
    {
        is_even = false;
    }
    
    if (is_even)
    {
        //@ assert (a + b) % 2 == 0;
        return true;
    }
    else
    {
        //@ assert (a + b) % 2 != 0;
        return false;
    }
}
