/*@
    predicate base_nonneg(integer b) = b >= 0;
    predicate height_nonneg(integer h) = h >= 0;
    predicate area_nonneg(integer a) = a >= 0;

    logic integer area_parallelogram(integer base, integer height) =
        base <= 0 ? 0 : base * height;

    lemma area_parallelogram_nonneg:
        \forall integer base, height;
        base_nonneg(base) && height_nonneg(height) ==>
        area_nonneg(area_parallelogram(base, height));
*/

/*@
    requires base >= 0;
    requires height >= 0;
    ensures \result >= 0;
    ensures \result == area_parallelogram(base, height);
    assigns \nothing;
*/
int compute_area(int base, int height) {
    int result;
    int local_base;

    local_base = base;
    result = 0;

    /*@
        loop invariant 0 <= local_base <= base;
        loop invariant result == (base - local_base) * height;
        loop invariant result >= 0;
        loop assigns local_base, result;
    */
    while (local_base > 0) {
        //@ assert local_base * height >= 0;
        result = result + height;
        local_base = local_base - 1;
    }

    //@ assert result == base * height;
    return result;
}

/*@
    assigns \nothing;
*/
int main() {
    return 0;
}
