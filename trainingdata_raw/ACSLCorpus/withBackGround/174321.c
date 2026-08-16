/*@
    predicate valid_range(integer x) = 1 <= x <= 10000;

    logic integer product(integer a, integer b) = a * b;

    lemma product_bounds:
        \forall integer a, b;
            valid_range(a) && valid_range(b) ==>
                product(a, b) >= 1 && product(a, b) <= 10000 * 10000;
*/

/*@
    requires valid_range(A) && valid_range(B) && valid_range(C) && valid_range(D);
    ensures \result == product(A, B) || \result == product(C, D);
    ensures \result >= 1;
    assigns \nothing;
*/
int func(int A, int B, int C, int D)
{
    // Variable declarations at scope top
    int S1;
    int S2;
    int res;

    //@ assert valid_range(A) && valid_range(B);
    //@ assert product(A, B) >= 1 && product(A, B) <= 10000 * 10000;
    S1 = A * B;

    //@ assert valid_range(C) && valid_range(D);
    //@ assert product(C, D) >= 1 && product(C, D) <= 10000 * 10000;
    S2 = C * D;

    if (S1 > S2) {
        res = S1;
    } else {
        res = S2;
    }

    //@ assert res == S1 || res == S2;
    //@ assert res >= 1;

    return res;
}
