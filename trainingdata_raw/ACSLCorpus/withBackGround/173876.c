/*@
    predicate in_range(integer x) = 1 <= x <= 100000;

    logic integer func_spec(integer x) =
        (x / 500) * 1000 + ((x % 500) / 5) * 5;

    lemma mul_bound1: \forall integer x, temp;
        in_range(x) && temp == x / 500 ==> temp * 1000 <= 100000 * 1000;

    lemma mul_bound2: \forall integer x, x_mod_500, temp;
        in_range(x) && x_mod_500 == x % 500 && temp == x_mod_500 / 5 ==>
        temp * 5 <= 100000 * 5;
*/

/*@
    requires 1 <= x <= 100000;
    ensures \result == func_spec(x);
    assigns \nothing;
*/
unsigned int func(unsigned int x)
{
    unsigned int result;
    unsigned int temp;
    unsigned int x_mod_500;

    result = 0;
    temp = x / 500;
    //@ assert temp * 1000 <= 100000 * 1000;
    result += temp * 1000;
    x_mod_500 = x % 500;
    temp = x_mod_500 / 5;
    //@ assert temp * 5 <= 100000 * 5;
    result += temp * 5;
    return result;
}
