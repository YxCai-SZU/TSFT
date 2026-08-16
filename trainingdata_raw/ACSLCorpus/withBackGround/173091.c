/*@
    lemma lemma_sum:
        \forall integer x, y; x > 0 && y > 0 ==> x + y > x;

    lemma calc_example_8:
        \forall integer x, y; x > 0 && y > 0 ==> x + y > x;

    lemma lemma_sum_1:
        \forall integer x, y; x > 0 && y > 0 ==> x + y > x;

    lemma lemma_sum_2:
        \forall integer x, y; x > 0 && y > 0 ==> x + y > x;

    lemma lemma_sum_3:
        \forall integer x, y; x > 0 && y > 0 ==> x + y > x;

    lemma lemma_sum_4:
        \forall integer x, y; x > 0 && y > 0 ==> x + y > x;

    lemma lemma_sum_5:
        \forall integer x, y; x > 0 && y > 0 ==> x + y > x;

    lemma lemma_sum_6:
        \forall integer x, y; x > 0 && y > 0 ==> x + y > x;

    lemma lemma_sum_7:
        \forall integer x, y; x > 0 && y > 0 ==> x + y > x;

    lemma lemma_sum_8:
        \forall integer x, y; x > 0 && y > 0 ==> x + y > x;

    lemma lemma_sum_9:
        \forall integer x, y; x > 0 && y > 0 ==> x + y > x;

    lemma lemma_sum_10:
        \forall integer x, y; x > 0 && y > 0 ==> x + y > x;

    lemma lemma_sum_11:
        \forall integer x, y; x > 0 && y > 0 ==> x + y > x;

    lemma lemma_sum_12:
        \forall integer x, y; x > 0 && y > 0 ==> x + y > x;

    lemma lemma_sum_13:
        \forall integer x, y; x > 0 && y > 0 ==> x + y > x;

    lemma lemma_sum_14:
        \forall integer x, y; x > 0 && y > 0 ==> x + y > x;

    lemma lemma_sum_15:
        \forall integer x, y; x > 0 && y > 0 ==> x + y > x;

    lemma lemma_sum_16:
        \forall integer x, y; x > 0 && y > 0 ==> x + y > x;

    lemma lemma_sum_17:
        \forall integer x, y; x > 0 && y > 0 ==> x + y > x;

    lemma lemma_sum_18:
        \forall integer x, y; x > 0 && y > 0 ==> x + y > x;

    lemma lemma_sum_19:
        \forall integer x, y; x > 0 && y > 0 ==> x + y > x;

    lemma lemma_sum_20:
        \forall integer x, y; x > 0 && y > 0 ==> x + y > x;
*/

/*@
    requires x > 0 && y > 0;
    ensures \result > x;
*/
int calc_example_8(int x, int y) {
    //@ assert x > 0 && y > 0;
    int result;
    result = x + y;
    //@ assert result > x;
    return result;
}

int main() {
    return 0;
}
