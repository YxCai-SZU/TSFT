/*@
    requires x <= y;
    ensures \result == 1;
    assigns \nothing;
*/
int lemma_v_linear(int x, int y)
{
    //@ assert (2 * (x) + 3) <= (2 * (y) + 3);
    return 1;
}

/*@
    ensures \result == 1;
    assigns \nothing;
*/
int establish_forall()
{
    /*@
        loop invariant 0 <= i <= 100;
        loop invariant \forall integer x, y; (0 <= x <= i && 0 <= y <= i && x <= y) ==> (2 * (x) + 3) <= (2 * (y) + 3);
        loop assigns i;
    */
    for (int i = 0; i < 100; i++)
    {
        //@ assert \forall integer x, y; (0 <= x <= i && 0 <= y <= i && x <= y) ==> (2 * (x) + 3) <= (2 * (y) + 3);
    }
    return 1;
}

/*@
    requires 0 <= 0;
    ensures \result == 1;
    assigns \nothing;
*/
int lemma_0_le_0()
{
    //@ assert (2 * (0) + 3) <= (2 * (0) + 3);
    return 1;
}

/*@
    requires 0 <= 1;
    ensures \result == 1;
    assigns \nothing;
*/
int lemma_0_le_1()
{
    //@ assert (2 * (0) + 3) <= (2 * (1) + 3);
    return 1;
}

/*@
    requires 1 <= 1;
    ensures \result == 1;
    assigns \nothing;
*/
int lemma_1_le_1()
{
    //@ assert (2 * (1) + 3) <= (2 * (1) + 3);
    return 1;
}

int main()
{
    return 0;
}
