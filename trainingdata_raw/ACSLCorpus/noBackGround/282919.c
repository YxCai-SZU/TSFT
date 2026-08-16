#include <stdbool.h>

/*@
    requires (10 <= (n) && (n) <= 99);
    ensures \result == (n / 10 == 9 || n % 10 == 9);
*/
bool func(int n)
{
    int num;
    int div;
    int counter;
    int modu;
    bool result;
    
    num = n;
    div = 1;
    counter = 0;
    
    /*@
        loop invariant 10 <= n && n <= 99;
        loop invariant 0 <= num && num <= n;
        loop invariant num == n - 10 * counter;
        loop invariant 0 <= counter && counter <= n / 10;
        loop assigns num, counter;
        loop variant num;
    */
    while (num >= 10)
    {
        //@ assert num >= 10;
        num -= 10;
        counter += 1;
    }
    
    div = counter;
    modu = num;
    
    //@ assert div == n / 10;
    //@ assert modu == n % 10;
    
    result = (div == 9 || modu == 9);
    return result;
}
