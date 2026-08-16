/*@
    predicate is_mod_zero(integer x) = x % 3 == 0;
    logic integer mod_sum(integer a, integer b) = (a + b) % 3;
*/

/*@
    requires 1 <= a <= 100;
    requires 1 <= b <= 100;
    ensures \result == 1 <==> (is_mod_zero(b) || is_mod_zero(a) || is_mod_zero(a + b));
    assigns \nothing;
*/
int func(int a, int b)
{
    int result;
    //@ assert a + b <= 200;
    result = (b % 3 == 0) || (a % 3 == 0) || ((a + b) % 3 == 0);
    return result;
}
