/*@
    predicate pos_and_bounded(integer x, integer y) =
        x > 0 && y > 0 && x <= 64 && y <= 64;

    lemma non_linear_arith_example2:
        \forall integer x, y;
            pos_and_bounded(x, y) ==> x * y <= 64 * 64;
    lemma non_linear_arith_example2_2:
        \forall integer x, y;
            pos_and_bounded(x, y) ==> x * y >= 0;
*/

/*@
    requires \valid(out);
    requires x > 0 && y > 0 && x <= 64 && y <= 64;
    ensures *out == x * y;
    ensures *out <= 64 * 64;
    ensures *out >= 0;
*/
void compute_product(unsigned int x, unsigned int y, unsigned int *out) {
    unsigned int result;
    result = x * y;
    
    //@ assert pos_and_bounded(x, y);
    //@ assert result == x * y;
    //@ assert result <= 64 * 64;
    //@ assert result >= 0;
    
    *out = result;
}

int main() {
    unsigned int x = 10;
    unsigned int y = 20;
    unsigned int product;
    
    compute_product(x, y, &product);
    return 0;
}
