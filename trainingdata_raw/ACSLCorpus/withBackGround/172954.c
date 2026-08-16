/*@
    predicate a_less_b(integer a, integer b) = a < b;

    lemma calc_example:
        \forall integer a, b; a_less_b(a, b) ==> a_less_b(a, b);

    lemma calc_example_2:
        \forall integer a, b; a_less_b(a, b) ==> a + 1 < b + 2;

    lemma calc_example_3:
        \forall integer a, b; a_less_b(a, b) ==> a < b + 3;

    lemma calc_example_4:
        \forall integer a, b; a_less_b(a, b) ==> a * 2 < b * 2;

    lemma calc_example_5:
        \forall integer a, b; a_less_b(a, b) ==> (a + 1) * 2 < (b + 2) * 2;
*/

void main()
{
    int a;
    int b;
    
    //@ assert a < b ==> a < b;
    //@ assert a < b ==> a + 1 < b + 2;
    //@ assert a < b ==> a < b + 3;
    //@ assert a < b ==> a * 2 < b * 2;
    //@ assert a < b ==> (a + 1) * 2 < (b + 2) * 2;
}
