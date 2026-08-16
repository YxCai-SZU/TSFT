/*@
    predicate is_in_range(integer x) = 1 <= x && x <= 10;

    logic integer square(integer x) = x * x;
    logic integer cube(integer x) = x * x * x;
    logic integer target_sum(integer x) = x + square(x) + cube(x);

    lemma square_bounds: \forall integer x; is_in_range(x) ==> 1 <= square(x) && square(x) <= 100;
    lemma cube_bounds: \forall integer x; is_in_range(x) ==> 1 <= cube(x) && cube(x) <= 1000;
    lemma sum_bounds: \forall integer x; is_in_range(x) ==> 1 <= x + square(x) && x + square(x) <= 110;
*/

/*@
    requires is_in_range(a);
    ensures \result == target_sum(a);
    assigns \nothing;
*/
unsigned int func(unsigned int a)
{
    unsigned int a1;
    unsigned int a2;
    unsigned int a3;
    unsigned int res;

    a1 = a;
    //@ assert is_in_range(a1);
    //@ assert 1 <= a * a && a * a <= 100;
    a2 = a * a;
    //@ assert 1 <= a * a * a && a * a * a <= 1000;
    a3 = a2 * a;
    //@ assert 1 <= a1 + a2 && a1 + a2 <= 110;
    res = a1 + a2 + a3;
    //@ assert res == target_sum(a);
    return res;
}
