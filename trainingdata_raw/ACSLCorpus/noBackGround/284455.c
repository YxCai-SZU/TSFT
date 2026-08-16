#include <stdint.h>

/*@
    requires (0 <= (X) <= 1000000000);
    ensures \result == (((X) / 500) * 1000 + (((X) % 500) / 5) * 5);
    assigns \nothing;
*/
int64_t func(int64_t X)
{
    int64_t result;
    int64_t temp;
    int64_t count_500;
    int64_t count_5;
    
    result = 0;
    temp = X;
    count_500 = 0;
    count_5 = 0;
    
    /*@
        loop invariant 0 <= temp <= X;
        loop invariant temp == X - 500 * count_500;
        loop invariant count_500 >= 0;
        loop invariant count_500 <= X / 500;
        loop assigns temp, count_500;
        loop variant temp;
    */
    while (temp >= 500)
    {
        temp = temp - 500;
        count_500 = count_500 + 1;
    }
    
    /*@
        loop invariant 0 <= temp <= X;
        loop invariant temp == X - 500 * count_500 - 5 * count_5;
        loop invariant count_500 >= 0;
        loop invariant count_500 <= X / 500;
        loop invariant count_5 >= 0;
        loop invariant count_5 <= (X - 500 * count_500) / 5;
        loop assigns temp, count_5;
        loop variant temp;
    */
    while (temp >= 5)
    {
        temp = temp - 5;
        count_5 = count_5 + 1;
    }
    
    result = count_500 * 1000 + count_5 * 5;
    
    //@ assert result == (((X) / 500) * 1000 + (((X) % 500) / 5) * 5);
    
    return result;
}

int main()
{
    return 0;
}
