#include <stdbool.h>

/*@
    predicate check_number(integer n, integer k) = n == k;
*/

/*@
    lemma test_check_number:
        check_number(10, 10) && !check_number(10, 20);
*/

/*@
    lemma test_check_number_2:
        check_number(0, 0) && !check_number(0, 15);
*/

/*@
    requires 1 <= n <= 9;
    ensures \result == (n == 7 || n == 5 || n == 3);
*/
bool func(int n)
{
    bool result;
    
    //@ assert 1 <= n <= 9;
    
    if (n == 7 || n == 5 || n == 3)
    {
        result = true;
    }
    else
    {
        result = false;
    }
    
    //@ assert result == (n == 7 || n == 5 || n == 3);
    return result;
}
