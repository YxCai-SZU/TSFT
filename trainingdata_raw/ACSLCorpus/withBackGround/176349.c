/*@
    predicate is_eq(integer a, integer b) = a == b;
    predicate is_gt(integer a, integer b) = a > b;
    predicate is_lt(integer a, integer b) = a < b;
    predicate is_neq(integer a, integer b) = a != b;
    predicate is_ge(integer a, integer b) = a >= b;
    predicate is_le(integer a, integer b) = a <= b;

    lemma calc_example: \forall integer a, b; a == b + 1 ==> a - 1 == b;
    lemma lemma_drop_first_and_last: \forall integer len; len > 1 ==> len - 2 >= 0;
    lemma lemma_maximum: \forall integer a, b; a == b + 1 ==> a > b;
    lemma lemma_minimum: \forall integer a, b; a == b + 1 ==> b < a;
    lemma lemma_not_equal: \forall integer a, b; a == b + 1 ==> a != b;
    lemma lemma_greater_or_equal: \forall integer a, b; a == b + 1 ==> a >= b;
    lemma lemma_less_or_equal: \forall integer a, b; a == b + 1 ==> b <= a;
    lemma lemma_not_less: \forall integer a, b; a == b + 1 ==> !(a < b);
    lemma lemma_not_greater: \forall integer a, b; a == b + 1 ==> !(b > a);
*/

/*@
    requires a == b + 1;
    ensures \result == b;
    assigns \nothing;
*/
int calc_example(int a, int b)
{
    int result;
    //@ assert a == b + 1;
    result = a - 1;
    //@ assert result == b;
    return result;
}

/*@
    requires len > 1;
    ensures \result == len - 2;
    assigns \nothing;
*/
int lemma_drop_first_and_last(int len)
{
    int result;
    //@ assert len > 1;
    result = len - 2;
    //@ assert result >= 0;
    return result;
}

/*@
    requires a == b + 1;
    ensures \result == 1;
    assigns \nothing;
*/
int lemma_maximum(int a, int b)
{
    int result;
    //@ assert a > b;
    result = 1;
    return result;
}

/*@
    requires a == b + 1;
    ensures \result == 1;
    assigns \nothing;
*/
int lemma_minimum(int a, int b)
{
    int result;
    //@ assert b < a;
    result = 1;
    return result;
}

/*@
    requires a == b + 1;
    ensures \result == 1;
    assigns \nothing;
*/
int lemma_not_equal(int a, int b)
{
    int result;
    //@ assert a != b;
    result = 1;
    return result;
}

/*@
    requires a == b + 1;
    ensures \result == 1;
    assigns \nothing;
*/
int lemma_greater_or_equal(int a, int b)
{
    int result;
    //@ assert a >= b;
    result = 1;
    return result;
}

/*@
    requires a == b + 1;
    ensures \result == 1;
    assigns \nothing;
*/
int lemma_less_or_equal(int a, int b)
{
    int result;
    //@ assert b <= a;
    result = 1;
    return result;
}

/*@
    requires a == b + 1;
    ensures \result == 1;
    assigns \nothing;
*/
int lemma_not_less(int a, int b)
{
    int result;
    //@ assert !(a < b);
    result = 1;
    return result;
}

/*@
    requires a == b + 1;
    ensures \result == 1;
    assigns \nothing;
*/
int lemma_not_greater(int a, int b)
{
    int result;
    //@ assert !(b > a);
    result = 1;
    return result;
}

int main()
{
    return 0;
}
