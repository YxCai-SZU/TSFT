/*@
    predicate is_nonnegative(integer x) = x >= 0;
    predicate is_within_range(integer x) = x >= 0 && x <= 100;
    logic integer square(integer x) = x * x;
    lemma square_bound: \forall integer x; is_within_range(x) ==> square(x) <= 10000;
*/

/*@
    requires is_within_range(x);
    ensures \result == square(x);
    assigns \nothing;
*/
int func(int x)
{
    //@ assert is_within_range(x);
    //@ assert square(x) <= 10000;
    return x * x;
}

/*@
    assigns \nothing;
*/
void test(void)
{
    //@ assert 25 == 25;
}

int main(void)
{
    return 0;
}
