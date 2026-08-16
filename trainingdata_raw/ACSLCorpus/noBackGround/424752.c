#include <stdint.h>

/*@
    requires (1 <= (x) <= 1000000000);
    ensures \result == (((x) - 1) / 2);
    assigns \nothing;
*/
int64_t func(int64_t x)
{
    int64_t result = 0;
    int64_t temp = x - 1;
    int64_t count = 0;
    
    /*@
        loop invariant 0 <= temp <= x - 1;
        loop invariant 0 <= count <= (((x) - 1) / 2);
        loop invariant x - 1 == temp + 2 * count;
        loop assigns temp, count;
        loop variant temp;
    */
    while (temp >= 2)
    {
        //@ assert temp >= 2;
        temp -= 2;
        count += 1;
    }
    
    result = count;
    
    //@ assert count == (((x) - 1) / 2);
    
    return result;
}

int main()
{
    return 0;
}
