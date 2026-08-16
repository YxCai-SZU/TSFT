/*@
    predicate in_range(integer v) = -100 <= v <= 100;
    predicate product_in_range(integer p) = -10000 <= p <= 10000;
    logic integer max_of_six(integer ab, integer ac, integer ad, integer bc, integer bd, integer cd) =
        (ab >= ac && ab >= ad && ab >= bc && ab >= bd && ab >= cd) ? ab :
        (ac >= ad && ac >= bc && ac >= bd && ac >= cd) ? ac :
        (ad >= bc && ad >= bd && ad >= cd) ? ad :
        (bc >= bd && bc >= cd) ? bc :
        (bd >= cd) ? bd : cd;
    lemma max_is_product:
        \forall integer a,b,c,d,ab,ac,ad,bc,bd,cd;
        in_range(a) && in_range(b) && in_range(c) && in_range(d) &&
        ab == a * b && ac == a * c && ad == a * d &&
        bc == b * c && bd == b * d && cd == c * d ==>
        max_of_six(ab,ac,ad,bc,bd,cd) == a * b ||
        max_of_six(ab,ac,ad,bc,bd,cd) == a * c ||
        max_of_six(ab,ac,ad,bc,bd,cd) == a * d ||
        max_of_six(ab,ac,ad,bc,bd,cd) == b * c ||
        max_of_six(ab,ac,ad,bc,bd,cd) == b * d ||
        max_of_six(ab,ac,ad,bc,bd,cd) == c * d;
    lemma max_ge_all:
        \forall integer ab,ac,ad,bc,bd,cd;
        max_of_six(ab,ac,ad,bc,bd,cd) >= ab &&
        max_of_six(ab,ac,ad,bc,bd,cd) >= ac &&
        max_of_six(ab,ac,ad,bc,bd,cd) >= ad &&
        max_of_six(ab,ac,ad,bc,bd,cd) >= bc &&
        max_of_six(ab,ac,ad,bc,bd,cd) >= bd &&
        max_of_six(ab,ac,ad,bc,bd,cd) >= cd;
*/

/*@
    requires -100 <= a <= 100;
    requires -100 <= b <= 100;
    requires -100 <= c <= 100;
    requires -100 <= d <= 100;
    ensures \result == a * b || \result == a * c || \result == a * d ||
            \result == b * c || \result == b * d || \result == c * d;
    ensures \result >= a * b;
    ensures \result >= a * c;
    ensures \result >= a * d;
    ensures \result >= b * c;
    ensures \result >= b * d;
    ensures \result >= c * d;
*/
int func(int a, int b, int c, int d)
{
    int ab, ac, ad, bc, bd, cd;
    int max_val;

    //@ assert -100 <= a && a <= 100;
    //@ assert -100 <= b && b <= 100;
    //@ assert -100 <= c && c <= 100;
    //@ assert -100 <= d && d <= 100;

    //@ assert -10000 <= a * b && a * b <= 10000;
    //@ assert -10000 <= a * c && a * c <= 10000;
    //@ assert -10000 <= a * d && a * d <= 10000;
    //@ assert -10000 <= b * c && b * c <= 10000;
    //@ assert -10000 <= b * d && b * d <= 10000;
    //@ assert -10000 <= c * d && c * d <= 10000;

    ab = a * b;
    ac = a * c;
    ad = a * d;
    bc = b * c;
    bd = b * d;
    cd = c * d;

    max_val = ab;
    if (ac > max_val) {
        max_val = ac;
    }
    if (ad > max_val) {
        max_val = ad;
    }
    if (bc > max_val) {
        max_val = bc;
    }
    if (bd > max_val) {
        max_val = bd;
    }
    if (cd > max_val) {
        max_val = cd;
    }

    //@ assert max_val >= a * b;
    //@ assert max_val >= a * c;
    //@ assert max_val >= a * d;
    //@ assert max_val >= b * c;
    //@ assert max_val >= b * d;
    //@ assert max_val >= c * d;

    return max_val;
}
