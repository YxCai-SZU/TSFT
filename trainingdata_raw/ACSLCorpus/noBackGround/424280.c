/*@
    requires (1 <= (A) <= 10000) && (1 <= (B) <= 10000) && (1 <= (C) <= 10000) && (1 <= (D) <= 10000);
    ensures \result == A * B || \result == C * D;
    ensures \result >= A * B && \result >= C * D;
    assigns \nothing;
*/
int func(int A, int B, int C, int D)
{
    int product1;
    int product2;
    int result;

    //@ assert (1 <= (A) <= 10000);
    //@ assert (1 <= (B) <= 10000);
    //@ assert (1 <= (C) <= 10000);
    //@ assert (1 <= (D) <= 10000);
    //@ assert A * B <= 10000 * 10000;
    //@ assert C * D <= 10000 * 10000;

    product1 = A * B;
    product2 = C * D;

    if (product1 > product2) {
        result = product1;
    } else {
        result = product2;
    }

    //@ assert result == ((product1) > (product2) ? (product1) : (product2));
    return result;
}
