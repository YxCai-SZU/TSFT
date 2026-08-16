/*@
    predicate is_valid_range(integer x) = 1 <= x <= 100;

    logic integer sum_ab(integer a, integer b) = a + b;
    logic integer sum_bc(integer b, integer c) = b + c;
    logic integer sum_ca(integer c, integer a) = c + a;

    lemma sum_ab_commutative:
        \forall integer a, b; sum_ab(a, b) == sum_ab(b, a);

    lemma sum_bc_commutative:
        \forall integer b, c; sum_bc(b, c) == sum_bc(c, b);

    lemma sum_ca_commutative:
        \forall integer c, a; sum_ca(c, a) == sum_ca(a, c);
*/

/*@
    requires is_valid_range(a);
    requires is_valid_range(b);
    requires is_valid_range(c);
    ensures \result == (a + b == c || b + c == a || c + a == b);
*/
int func(int a, int b, int c)
{
    int sum1;
    int sum2;
    int sum3;
    int result;

    //@ assert sum_ab(a, b) == a + b;
    sum1 = a + b;

    //@ assert sum_bc(b, c) == b + c;
    sum2 = b + c;

    //@ assert sum_ca(c, a) == c + a;
    sum3 = c + a;

    //@ assert sum1 == sum_ab(a, b);
    //@ assert sum2 == sum_bc(b, c);
    //@ assert sum3 == sum_ca(c, a);

    result = (sum1 == c) || (sum2 == a) || (sum3 == b);
    //@ assert result == (sum_ab(a, b) == c || sum_bc(b, c) == a || sum_ca(c, a) == b);
    return result;
}
