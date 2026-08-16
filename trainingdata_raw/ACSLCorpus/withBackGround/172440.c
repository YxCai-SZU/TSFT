#include <stdbool.h>

/*@
    predicate valid_range(integer r) = 1 <= r && r <= 100;
    predicate pi_const(integer pi) = pi == 314;
    
    logic integer division_result(integer r) = (2 * r * 314) / 100;
    
    lemma division_correctness:
        \forall integer r; valid_range(r) ==> division_result(r) == (2 * r * 314) / 100;
*/

/*@
    requires valid_range(r);
    ensures \result == division_result(r);
    assigns \nothing;
*/
int func(int r)
{
    int pi;
    int res;
    int temp;
    int count;
    
    //@ assert valid_range(r);
    pi = 314;
    //@ assert pi_const(pi);
    res = 0;
    temp = r * 2 * pi;
    count = 0;
    
    /*@
        loop invariant 1 <= r && r <= 100;
        loop invariant pi == 314;
        loop invariant temp >= 0;
        loop invariant temp == r * 2 * pi - 100 * count;
        loop invariant count >= 0;
        loop assigns temp, count;
        loop variant temp;
    */
    while (temp >= 100)
    {
        //@ assert temp >= 100;
        temp -= 100;
        count += 1;
        //@ assert temp == r * 2 * pi - 100 * count;
    }
    
    res = count;
    //@ assert res == division_result(r);
    return res;
}
