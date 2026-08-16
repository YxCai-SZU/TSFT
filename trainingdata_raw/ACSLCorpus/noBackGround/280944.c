#include <stdbool.h>

/*@
    requires (400 <= (x) && (x) < 2000);
    ensures \result == (8 - ((x) - 400) / 200);
    assigns \nothing;
*/
int func(int x)
{
    int result;
    int temp;
    int count;
    
    //@ assert (400 <= (x) && (x) < 2000);
    
    result = 8;
    temp = x - 400;
    count = 0;
    
    /*@
        loop invariant 400 <= x && x < 2000;
        loop invariant temp >= 0;
        loop invariant temp == x - 400 - 200 * count;
        loop invariant count >= 0;
        loop invariant count <= (x - 400) / 200;
        loop assigns temp, count;
        loop variant temp;
    */
    while (temp >= 200)
    {
        temp -= 200;
        count += 1;
    }
    
    //@ assert temp == x - 400 - 200 * count;
    //@ assert result == 8;
    
    result -= count;
    
    //@ assert result == 8 - count;
    return result;
}

int main(void)
{
    return 0;
}
