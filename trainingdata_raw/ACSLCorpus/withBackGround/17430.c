/*@
    predicate bounds(integer A, integer B) =
        1 <= A && A <= 100 &&
        1 <= B && B <= 100;

    lemma product_bounds:
        \forall integer A, B;
        bounds(A, B) ==> A * B <= 10000;
*/

/*@
    requires bounds(A, B);
    ensures \result == A * B;
    assigns \nothing;
*/
int func(int A, int B)
{
    //@ assert bounds(A, B);
    //@ assert A * B <= 10000;
    int ans = A * B;
    //@ assert ans == A * B;
    return ans;
}
