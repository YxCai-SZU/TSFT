/*@
    predicate is_valid_range(integer a) =
        1 <= a && a < 500;

    lemma multiplication_bound:
        \forall integer a, b;
        is_valid_range(a) && is_valid_range(b) ==>
        a * b < 250000;
*/

/*@
    requires 1 <= a && a < 500;
    requires 1 <= b && b < 500;
    ensures \result == ((a * b) % 2 == 0);
    assigns \nothing;
*/
_Bool func(unsigned int a, unsigned int b)
{
    // Variable declarations at top of scope
    unsigned int product;
    _Bool result;

    //@ assert 1 <= a && a < 500;
    //@ assert 1 <= b && b < 500;
    //@ assert a * b < 250000;

    product = a * b;
    result = (product % 2 == 0);
    return result;
}

int main()
{
    return 0;
}
