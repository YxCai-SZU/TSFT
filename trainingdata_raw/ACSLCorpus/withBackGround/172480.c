/*@
    predicate in_range(integer x) = 1 <= x <= 100;

    logic integer sum(integer a, integer b) = a + b;

    lemma sum_bounds:
        \forall integer a, b;
            in_range(a) && in_range(b) ==> sum(a, b) <= 200;
*/

/*@
    requires in_range(A) && in_range(B) && in_range(C);
    ensures \result == 1 <==> (A == sum(B, C) || B == sum(A, C) || C == sum(A, B));
    assigns \nothing;
*/
int func(unsigned int A, unsigned int B, unsigned int C)
{
    int ok = 0;

    //@ assert sum(B, C) <= 200;
    //@ assert sum(A, C) <= 200;
    //@ assert sum(A, B) <= 200;

    if (A == B + C || B == A + C || C == A + B)
    {
        ok = 1;
    }

    return ok;
}
