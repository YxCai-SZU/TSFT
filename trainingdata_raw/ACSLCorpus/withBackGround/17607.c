/*@
    predicate is_in_range(integer l) = 1 <= l && l <= 1000;

    logic integer cube(integer l) = l * l * l;

    lemma cube_bounds:
        \forall integer l; is_in_range(l) ==> 0 <= cube(l) && cube(l) <= 1000000000;

    lemma division_property:
        \forall integer l, integer res, integer temp;
            is_in_range(l) && cube(l) == l * l * l &&
            temp == cube(l) - res * 27 && 0 <= temp && temp < 27 ==>
            res == cube(l) / 27;
*/

/*@
    requires 1 <= l && l <= 1000;
    ensures \result == (l * l * l) / 27;
    assigns \nothing;
*/
long func(long l) {
    long l_cubed;
    long res;
    long temp;
    long divisor;

    //@ assert is_in_range(l);
    //@ assert 0 <= l * l && l * l <= 1000000;
    //@ assert 0 <= l * l * l && l * l * l <= 1000000000;

    l_cubed = l * l * l;
    res = 0;
    temp = l_cubed;
    divisor = 27;

    /*@
        loop invariant is_in_range(l);
        loop invariant l_cubed == l * l * l;
        loop invariant 0 <= res && res <= l_cubed / 27;
        loop invariant temp == l_cubed - res * 27;
        loop invariant 0 <= temp && temp <= 1000000000;
        loop assigns res, temp;
        loop variant temp;
    */
    while (temp >= divisor) {
        temp -= divisor;
        res += 1;
    }

    //@ assert res == l_cubed / 27;
    return res;
}
