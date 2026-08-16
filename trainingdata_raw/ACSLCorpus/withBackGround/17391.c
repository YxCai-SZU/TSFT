/*@
    predicate in_range(integer x) = 1 <= x <= 10;

    logic integer sum_mod3(integer a, integer b, integer c) = (a + b + c) % 3;

    lemma mod3_range: \forall integer a, b, c;
        in_range(a) && in_range(b) && in_range(c) ==>
        0 <= sum_mod3(a, b, c) <= 2;
*/

/*@
    requires in_range(a) && in_range(b) && in_range(c);
    ensures \result == (sum_mod3(a, b, c) == 0);
    assigns \nothing;
*/
int func(unsigned int a, unsigned int b, unsigned int c)
{
    //@ assert in_range(a);
    //@ assert in_range(b);
    //@ assert in_range(c);
    //@ assert 0 <= sum_mod3(a, b, c) <= 2;
    return (a + b + c) % 3 == 0;
}
