/*@
    predicate is_within_range(integer a) = 1 <= a && a <= 10;
    logic integer square(integer a) = a * a;
    lemma square_bound: \forall integer a; is_within_range(a) ==> square(a) <= 100;
*/

/*@
    requires is_within_range(a);
    ensures \result == square(a);
    assigns \nothing;
*/
unsigned int func(unsigned int a)
{
    unsigned int result;
    //@ assert is_within_range(a);
    //@ assert square(a) <= 100;
    result = a * a;
    //@ assert result == square(a);
    return result;
}
