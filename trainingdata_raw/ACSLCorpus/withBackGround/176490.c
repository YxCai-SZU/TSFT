/*@
predicate prop_1_pre(integer x, integer y, integer z) =
    0 <= x && x <= y && y <= z && z <= 10;

predicate prop_1_post(integer x, integer y, integer z) =
    0 <= z && z <= 10;

lemma prop_1:
    \forall integer x, y, z;
    prop_1_pre(x, y, z) ==> prop_1_post(x, y, z);

predicate lemma_2_pre(integer a, integer b, integer c) =
    a < b && b < c;

predicate lemma_2_post(integer a, integer b, integer c) =
    a < c;

lemma lemma_2:
    \forall integer a, b, c;
    lemma_2_pre(a, b, c) ==> lemma_2_post(a, b, c);

predicate lemma_3_pre(integer d, integer e, integer f) =
    d <= e && e <= f;

predicate lemma_3_post(integer d, integer e, integer f) =
    d <= f;

lemma lemma_3:
    \forall integer d, e, f;
    lemma_3_pre(d, e, f) ==> lemma_3_post(d, e, f);
*/

int main() {
    return 0;
}
