#include <limits.h>

/*@
    predicate valid_a(integer a) = 1 <= a <= 9;
    predicate valid_result(integer r) = 1 <= r <= 729;
*/

/*@
    logic integer cube(integer a) = a * a * a;
*/

/*@
    lemma cube_bounds: \forall integer a; valid_a(a) ==> valid_result(cube(a));
*/

/*@
    requires valid_a(a);
    ensures \result == cube(a);
    ensures valid_result(\result);
    assigns \nothing;
*/
int func(int a)
{
    int result;
    
    //@ assert valid_a(a);
    //@ assert 1 <= a && a <= 9;
    
    //@ assert 1 * 1 * 1 <= a * a * a && a * a * a <= 9 * 9 * 9;
    
    result = a * a * a;
    
    //@ assert result == cube(a);
    //@ assert valid_result(result);
    
    return result;
}

int main()
{
    return 0;
}
