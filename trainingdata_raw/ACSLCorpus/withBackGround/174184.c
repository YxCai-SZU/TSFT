/*@
    predicate is_eq_two(integer a) = a == 2;
    predicate is_eq_three(integer a) = a == 3;
    logic integer triple(integer x) = x * 3;

    lemma proof_chain_int: \forall integer a; is_eq_two(a) ==> triple(a) == 6;
    lemma proof_chain_int2: \forall integer a; is_eq_three(a) ==> triple(a) == 9;
*/

int main()
{
    int a;
    int b;
    int result_a;
    int result_b;

    a = 2;
    b = 3;

    //@ assert is_eq_two(a);
    //@ assert triple(a) == 6;

    result_a = a * 3;

    //@ assert is_eq_three(b);
    //@ assert triple(b) == 9;

    result_b = b * 3;

    return 0;
}
