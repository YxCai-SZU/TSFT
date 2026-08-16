#include <stdbool.h>

/*@
    predicate has_seven(integer n) =
        n / 100 == 7 || (n / 10) % 10 == 7 || n % 10 == 7;
 */

/*@
    requires 100 <= n <= 999;
    ensures \result == (n / 100 == 7 || (n / 10) % 10 == 7 || n % 10 == 7);
    assigns \nothing;
 */
bool func(unsigned int n)
{
    unsigned int num;
    num = n;

    /*@
        loop invariant 100 <= n <= 999;
        loop invariant num <= n;
        loop invariant num >= 0;
        loop invariant (n / 100 == 7 || (n / 10) % 10 == 7 || n % 10 == 7) == 
                       (num / 100 == 7 || (num / 10) % 10 == 7 || num % 10 == 7);
        loop assigns num;
        loop variant num;
     */
    while (num > 0)
    {
        if (num % 10 == 7)
        {
            //@ assert \true;
            return true;
        }
        num /= 10;
    }
    //@ assert \true;
    return false;
}

int main()
{
    return 0;
}
