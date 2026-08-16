#include <stdbool.h>

/*@
    requires (1 <= (a) <= 100) && (1 <= (b) <= 100);
    ensures \result == (((a) + (b) + 1) / 2);
    assigns \nothing;
*/
int func(int a, int b)
{
    int sum;
    int average;
    int temp_sum;
    int count;
    
    sum = a + b;
    average = 0;
    temp_sum = sum;
    count = 0;
    
    //@ ghost int original_sum = sum;
    
    /*@
        loop invariant 0 <= temp_sum <= original_sum;
        loop invariant 0 <= count <= original_sum / 2;
        loop invariant temp_sum == original_sum - 2 * count;
        loop assigns temp_sum, count;
        loop variant temp_sum;
    */
    while (temp_sum >= 2)
    {
        //@ assert temp_sum >= 2;
        temp_sum -= 2;
        count += 1;
    }
    
    if (temp_sum == 1)
    {
        average = count + 1;
    }
    else
    {
        average = count;
    }
    
    //@ assert average == (((a) + (b) + 1) / 2);
    return average;
}
