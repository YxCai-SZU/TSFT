/*@
    predicate strictly_increasing(integer A, integer B, integer C) =
        A < B && B < C ==> A < C;

    lemma calc_example_9: \forall integer a; a * a + 1 == 1 + a * a;
    lemma is_strictly_increasing: \forall integer A, B, C; strictly_increasing(A, B, C);
*/

/*@
    requires A < B && B < C;
    ensures \result == 1;
    assigns \nothing;
*/
int check_strictly_increasing(int A, int B, int C)
{
    //@ assert A < C;
    return 1;
}

int main()
{
    return 0;
}
