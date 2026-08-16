/*@
    predicate a_less_b(integer a, integer b) = a < b;
    predicate b_less_c(integer b, integer c) = b < c;
    predicate c_less_d(integer c, integer d) = c < d;
    predicate a_leq_c(integer a, integer c) = a <= c;
    predicate a_leq_d(integer a, integer d) = a <= d;
*/

/*@
    lemma calc_example_2: \forall integer a, b, c; a_less_b(a, b) && b_less_c(b, c) ==> a_leq_c(a, c);
    lemma example: \forall integer a, b, c, d; a_less_b(a, b) && b_less_c(b, c) && c_less_d(c, d) ==> a_leq_d(a, d);
*/

/*@
    predicate in_range(integer x) = 1 <= x && x <= 100;
    logic integer func_result(integer a, integer b, integer c) = (a <= b && b <= c) ? 1 : 0;
*/

/*@
    requires in_range(a) && in_range(b) && in_range(c);
    ensures \result == func_result(a, b, c);
    assigns \nothing;
*/
int func(int a, int b, int c)
{
    //@ assert in_range(a);
    //@ assert in_range(b);
    //@ assert in_range(c);
    return (a <= b && b <= c) ? 1 : 0;
}

int main()
{
    return 0;
}
