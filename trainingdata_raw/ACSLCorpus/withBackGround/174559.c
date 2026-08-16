/*@
    predicate dimensions_positive(integer l, integer w, integer h) =
        l > 0 && w > 0 && h > 0;

    predicate within_int32_range(integer l, integer w, integer h) =
        l <= 2147483647 && w <= 2147483647 && h <= 2147483647;

    predicate product_within_int32_range(integer l, integer w, integer h) =
        (long long)l * (long long)w * (long long)h <= 2147483647;

    lemma product_positive: \forall integer l, w, h;
        dimensions_positive(l, w, h) ==> l * w * h > 0;
*/

/*@
    requires dimensions_positive(l, w, h);
    requires within_int32_range(l, w, h);
    requires product_within_int32_range(l, w, h);
    ensures \result == l * w * h;
    ensures \result > 0;
*/
int volume_rect_prism(int l, int w, int h) {
    //@ assert dimensions_positive(l, w, h);
    //@ assert product_within_int32_range(l, w, h);
    //@ assert l * w * h > 0;
    return l * w * h;
}

int main() {
    return 0;
}
