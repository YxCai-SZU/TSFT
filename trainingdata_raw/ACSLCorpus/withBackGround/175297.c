#include <stdint.h>

/*@
    predicate is_valid_n(integer n) = 1 <= n && n <= 100;

    logic integer div15(integer n) = n / 15;
    logic integer mod15(integer n) = n % 15;
    logic integer div6(integer n) = n / 6;

    logic integer expected_result(integer n) = 
        n * 800 - (div15(n) * 200) - (div6(mod15(n)) * 80);

    lemma div15_property:
        \forall integer n; is_valid_n(n) ==> 0 <= div15(n) && div15(n) <= 6;

    lemma mod15_property:
        \forall integer n; is_valid_n(n) ==> 0 <= mod15(n) && mod15(n) <= 14;

    lemma div6_mod15_property:
        \forall integer n; is_valid_n(n) ==> 0 <= div6(mod15(n)) && div6(mod15(n)) <= 2;
*/

/*@
    requires is_valid_n(n);
    ensures \result == expected_result(n);
*/
int64_t func(int64_t n)
{
    int64_t result;
    int64_t count;
    int64_t temp;
    
    //@ assert is_valid_n(n);
    result = n * 800;
    count = 0;
    temp = n;
    
    // First loop: division by 15
    /*@
        loop invariant 1 <= n && n <= 100;
        loop invariant 0 <= temp;
        loop invariant 0 <= count;
        loop invariant temp == n - 15 * count;
        loop assigns temp, count;
        loop variant temp;
    */
    while (temp >= 15)
    {
        //@ assert temp >= 15;
        temp -= 15;
        count += 1;
    }
    
    //@ assert count == div15(n);
    result -= count * 200;
    
    // Second loop: division by 6 on remainder
    count = 0;
    /*@
        loop invariant 1 <= n && n <= 100;
        loop invariant 0 <= temp;
        loop invariant 0 <= count;
        loop invariant temp == n - 15 * div15(n) - 6 * count;
        loop assigns temp, count;
        loop variant temp;
    */
    while (temp >= 6)
    {
        //@ assert temp >= 6;
        temp -= 6;
        count += 1;
    }
    
    //@ assert count == div6(mod15(n));
    result -= count * 80;
    
    //@ assert result == expected_result(n);
    return result;
}
