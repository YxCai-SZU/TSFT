/*@
    predicate bounds(integer x, integer y, integer z) =
        0 <= x && x <= 100 &&
        0 <= y && y <= 100 &&
        0 <= z && z <= 100 &&
        y + 2 * z <= 100;

    logic integer term1(integer x, integer y, integer z) = x * (y + 2 * z);
    logic integer term2(integer z) = 3 * z;

    lemma term1_bound:
        \forall integer x, y, z;
            bounds(x, y, z) ==> term1(x, y, z) <= 100 * 100;

    lemma term2_bound:
        \forall integer z;
            0 <= z && z <= 100 ==> term2(z) <= 3 * 100;

    lemma final_bound:
        \forall integer x, y, z;
            bounds(x, y, z) ==>
            term1(x, y, z) + term2(z) <= 100 * 100 + 3 * 100;
*/

/*@
    requires 0 <= x && x <= 100;
    requires 0 <= y && y <= 100;
    requires 0 <= z && z <= 100;
    requires y + 2 * z <= 100;
    ensures x * (y + 2 * z) + 3 * z <= 100 * 100 + 3 * 100;
*/
void complex_equation(int x, int y, int z)
{
    //@ assert bounds(x, y, z);
}
