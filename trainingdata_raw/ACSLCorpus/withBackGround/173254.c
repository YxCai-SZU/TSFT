#include <stdbool.h>

/*@ predicate is_func_result(integer n, bool result) = result == (n >= 30); */

/*@ requires -40 <= n <= 40;
    ensures \result == (n >= 30);
    assigns \nothing;
*/
bool func(int n)
{
    bool result;
    //@ assert -40 <= n <= 40;
    result = (n >= 30);
    //@ assert is_func_result(n, result);
    return result;
}

/*@ predicate is_func2_result(integer n, integer m, bool result) = result == (n == m); */

/*@ requires 1 <= n <= 100 && 0 <= m <= n;
    ensures \result == (n == m);
    assigns \nothing;
*/
bool func2(int n, int m)
{
    bool result;
    //@ assert 1 <= n <= 100 && 0 <= m <= n;
    result = (n == m);
    //@ assert is_func2_result(n, m, result);
    return result;
}

/*@ logic integer func3_result(integer n) = (n == 0) ? 1 : 0; */

/*@ lemma func3_case_zero: \forall integer n; n == 0 ==> func3_result(n) == 1; */
/*@ lemma func3_case_one: \forall integer n; n == 1 ==> func3_result(n) == 0; */

/*@ requires 0 <= n <= 1;
    ensures (n == 0 ==> \result == 1) && (n == 1 ==> \result == 0);
    assigns \nothing;
*/
int func3(int n)
{
    int result;
    //@ assert 0 <= n <= 1;
    
    if (n == 1) {
        //@ assert n == 1;
        result = 0;
    } else {
        //@ assert n == 0;
        result = 1;
    }
    //@ assert result == func3_result(n);
    return result;
}
