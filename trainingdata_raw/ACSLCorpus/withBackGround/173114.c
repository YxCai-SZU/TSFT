/*@
    predicate is_mod_bound(integer l) = 1 <= l <= 100000;
    predicate condition_holds(integer l) = (l % 100) * 21 >= l;
*/

/*@
    requires is_mod_bound(l);
    ensures \result == 1 <==> condition_holds(l);
    assigns \nothing;
*/
int func(int l)
{
    int result;
    int mod_result;
    int mul_result;

    //@ assert 1 <= l <= 100000;
    mod_result = l % 100;
    //@ assert 0 <= mod_result <= 99;
    mul_result = mod_result * 21;
    //@ assert 0 <= mul_result <= 2079;

    if (mul_result >= l) {
        //@ assert condition_holds(l);
        result = 1;
    } else {
        //@ assert !condition_holds(l);
        result = 0;
    }

    return result;
}
