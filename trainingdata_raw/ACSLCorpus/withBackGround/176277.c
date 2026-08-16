/*@
    logic integer sum_int(integer x, integer y) = x + y;

    lemma sum_int_positive:
        \forall integer x, y; x > 0 && y > 0 ==> sum_int(x, y) > 0;
*/

/*@
    requires x > 0 && y > 0;
    ensures \result == sum_int(x, y);
    ensures \result > 0;
    assigns \nothing;
*/
int compute_sum(int x, int y) {
    int result;
    int i;

    result = y;
    i = 0;

    /*@
        loop invariant 0 <= i <= x;
        loop invariant result == sum_int(i, y);
        loop assigns i, result;
    */
    while (i < x) {
        //@ assert result == sum_int(i, y);
        result = result + 1;
        i = i + 1;
        //@ assert result == sum_int(i, y);
    }

    //@ assert result == sum_int(x, y);
    return result;
}

/*@
    assigns \nothing;
*/
int main() {
    int a = 5;
    int b = 3;
    int total = compute_sum(a, b);
    //@ assert total == sum_int(a, b);
    return 0;
}
