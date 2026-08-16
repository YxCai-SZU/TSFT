#include <stdint.h>

/*@
    requires (1 <= (a) && (a) <= 100);
    ensures \result == ((a) * 314159 / 100000);
    assigns \nothing;
*/
int64_t func(int64_t a)
{
    int64_t pi = 314159;
    int64_t result = 0;
    int64_t temp = a * pi;
    int64_t count = 0;
    
    //@ assert 1 <= a * pi && a * pi <= 100 * 314159;
    
    /*@
        loop invariant 1 <= a && a <= 100;
        loop invariant pi == 314159;
        loop invariant temp >= 0;
        loop invariant temp == a * pi - 100000 * count;
        loop invariant count >= 0;
        loop invariant count <= a * pi / 100000;
        loop assigns temp, count;
        loop variant temp;
    */
    while (temp >= 100000)
    {
        temp -= 100000;
        count += 1;
    }
    
    result = count;
    
    //@ assert result == ((a) * 314159 / 100000);
    
    return result;
}

int main(void)
{
    return 0;
}
