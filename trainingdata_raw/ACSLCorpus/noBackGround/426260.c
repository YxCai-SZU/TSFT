/*@
    requires (-100 <= (A) <= 100) && (-100 <= (B) <= 100) && (-100 <= (C) <= 100) && (-100 <= (D) <= 100);
    ensures ((\result) == (A) || (\result) == (B) || (\result) == (C) || (\result) == (D));
    ensures ((\result) >= (A) || (\result) >= (B) || (\result) >= (C) || (\result) >= (D));
*/
int func(int A, int B, int C, int D)
{
    int max_ab;
    int max_bc;
    int max_cd;
    int max_ab_bc;
    int max_bc_cd;
    int max_ab_bc_cd;

    max_ab = (A > B) ? A : B;
    //@ assert max_ab == A || max_ab == B;

    max_bc = (B > C) ? B : C;
    //@ assert max_bc == B || max_bc == C;

    max_cd = (C > D) ? C : D;
    //@ assert max_cd == C || max_cd == D;

    max_ab_bc = (max_ab > max_bc) ? max_ab : max_bc;
    //@ assert max_ab_bc == A || max_ab_bc == B || max_ab_bc == C;

    max_bc_cd = (max_bc > max_cd) ? max_bc : max_cd;
    //@ assert max_bc_cd == B || max_bc_cd == C || max_bc_cd == D;

    max_ab_bc_cd = (max_ab_bc > max_bc_cd) ? max_ab_bc : max_bc_cd;
    //@ assert ((max_ab_bc_cd) == (A) || (max_ab_bc_cd) == (B) || (max_ab_bc_cd) == (C) || (max_ab_bc_cd) == (D));
    //@ assert ((max_ab_bc_cd) >= (A) || (max_ab_bc_cd) >= (B) || (max_ab_bc_cd) >= (C) || (max_ab_bc_cd) >= (D));

    return max_ab_bc_cd;
}
