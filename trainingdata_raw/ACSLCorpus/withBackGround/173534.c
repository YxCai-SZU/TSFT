#include <stdbool.h>

/*@
    predicate is_valid_n(integer n) = 1 <= n && n <= 10000;
    
    logic integer division_by_100(integer n, integer count) = n - 100 * count;
    
    lemma division_property:
        \forall integer n, count;
        is_valid_n(n) && 0 <= count && count <= n / 100 ==>
        division_by_100(n, count) >= 0;
*/

/*@
    requires is_valid_n(n);
    ensures \result == 0 || \result == 1;
*/
int func(int n)
{
    int rest;
    int is_pay;
    int count;
    
    rest = n;
    is_pay = 0;
    count = 0;
    
    /*@
        loop invariant 0 <= rest <= n;
        loop invariant count <= n / 100;
        loop invariant rest == n - 100 * count;
        loop invariant is_valid_n(n);
        loop assigns rest, count;
        loop variant rest;
    */
    while (rest >= 100)
    {
        //@ assert rest >= 100;
        rest -= 100;
        count += 1;
    }
    
    if (rest != 0 || count > n)
    {
        is_pay = 1;
    }
    
    if (is_pay == 0)
    {
        //@ assert is_pay == 0;
        return 0;
    }
    else
    {
        //@ assert is_pay == 1;
        return 1;
    }
}
