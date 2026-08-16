#include <stdbool.h>

/*@
    requires (1 <= (a) <= 100 && 1 <= (b) <= 100);
    ensures \result == (((a) + (b) + 1) / 2);
*/
int func(int a, int b)
{
    int sum;
    int avg;
    int i;
    int abs_sum;
    int temp_sum;

    sum = a + b;
    avg = 0;
    i = 0;
    
    //@ assert (1 <= (a) <= 100 && 1 <= (b) <= 100);
    
    if (sum < 0)
    {
        abs_sum = -sum;
    }
    else
    {
        abs_sum = sum;
    }
    
    //@ assert abs_sum == ((sum) < 0 ? -(sum) : (sum));
    
    temp_sum = abs_sum;
    
    /*@
        loop invariant 0 <= temp_sum <= abs_sum;
        loop invariant temp_sum % 2 == abs_sum % 2;
        loop invariant i == (abs_sum - temp_sum) / 2;
        loop invariant (1 <= (a) <= 100 && 1 <= (b) <= 100);
        loop assigns temp_sum, i;
        loop variant temp_sum;
    */
    while (temp_sum >= 2)
    {
        //@ assert temp_sum >= 2;
        temp_sum -= 2;
        i += 1;
    }
    
    if (temp_sum == 1 && sum > 0)
    {
        i += 1;
    }
    
    avg = i;
    
    //@ assert avg == (((a) + (b) + 1) / 2);
    
    return avg;
}
