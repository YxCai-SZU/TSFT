#include <stdint.h>

/*@
    predicate is_valid_n(integer n) = 1 <= n && n <= 100000;

    logic integer multiply_21(integer n) = n * 21;

    lemma multiplication_bound: \forall integer n; is_valid_n(n) ==> multiply_21(n) <= 2100000;
*/

/*@
    requires is_valid_n(n);
    ensures \result == 0 || \result == 1;
    ensures \result == 0 ==> (n * 21) % 100 > 50;
    ensures \result == 1 ==> (n * 21) % 100 <= 50;
*/
uint64_t func(uint64_t n)
{
    // Variable declarations at scope top
    uint64_t num;
    uint64_t is_bear;
    uint64_t temp_num;
    uint64_t remainder;

    //@ assert is_valid_n(n);
    //@ assert multiply_21(n) <= 2100000;
    
    num = n * 21;
    
    is_bear = 0;
    temp_num = num;
    
    /*@
        loop invariant 1 <= n && n <= 100000;
        loop invariant temp_num >= 0;
        loop invariant num == n * 21;
        loop invariant temp_num + 100 * is_bear == num;
        loop invariant temp_num == num % 100 + 100 * (temp_num / 100);
        loop assigns temp_num, is_bear;
        loop variant temp_num;
    */
    while (temp_num >= 100)
    {
        //@ assert temp_num >= 100;
        temp_num -= 100;
        is_bear += 1;
        //@ assert temp_num + 100 * is_bear == num;
    }
    
    remainder = temp_num;
    
    if (remainder > 50)
    {
        //@ assert remainder == (n * 21) % 100;
        //@ assert remainder > 50;
        return 0;
    }
    else
    {
        //@ assert remainder == (n * 21) % 100;
        //@ assert remainder <= 50;
        return 1;
    }
}
