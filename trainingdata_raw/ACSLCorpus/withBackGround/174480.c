/*@
predicate leq(integer x, integer y) = x <= y;

lemma arithmetic_congruence:
    \forall integer x, y, z, w;
        leq(x, y) && leq(y, z) && leq(z, w) ==> leq(x, w);

lemma arithmetic_monotonicity:
    \forall integer x, y, z;
        leq(x, y) && leq(y, z) ==> leq(x, z);

lemma arithmetic_addition:
    \forall integer x, y;
        leq(x, y) ==> leq(x + 1, y + 1);

lemma arithmetic_multiplication:
    \forall integer x, y;
        leq(x, y) && x >= 0 && y >= 0 ==> leq(2 * x, 2 * y);

lemma arithmetic_addition_mitigation:
    \forall integer x, y;
        leq(x, y) ==> leq(x + 2, y + 2);

lemma arithmetic_multiplication_mitigation:
    \forall integer x, y;
        leq(x, y) && x >= 0 && y >= 0 ==> leq(3 * x, 3 * y);
*/

/*@
    requires leq(x, y) && leq(y, z) && leq(z, w);
    ensures leq(x, w);
*/
void lemma_arithmetic_congruence(int x, int y, int z, int w)
{
    //@ assert leq(x, w);
}

/*@
    requires leq(x, y) && leq(y, z);
    ensures leq(x, z);
*/
void lemma_arithmetic_monotonicity(int x, int y, int z)
{
    //@ assert leq(x, z);
}

/*@
    requires leq(x, y);
    ensures leq(x + 1, y + 1);
*/
void lemma_arithmetic_addition(int x, int y)
{
    //@ assert leq(x + 1, y + 1);
}

/*@
    requires leq(x, y) && x >= 0 && y >= 0;
    ensures leq(2 * x, 2 * y);
*/
void lemma_arithmetic_multiplication(int x, int y)
{
    //@ assert leq(2 * x, 2 * y);
}

/*@
    requires leq(x, y);
    ensures leq(x + 2, y + 2);
*/
void lemma_arithmetic_addition_mitigation(int x, int y)
{
    //@ assert leq(x + 2, y + 2);
}

/*@
    requires leq(x, y) && x >= 0 && y >= 0;
    ensures leq(3 * x, 3 * y);
*/
void lemma_arithmetic_multiplication_mitigation(int x, int y)
{
    //@ assert leq(3 * x, 3 * y);
}
