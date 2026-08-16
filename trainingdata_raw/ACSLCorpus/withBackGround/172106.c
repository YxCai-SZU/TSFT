/*@
predicate x_ge_y(integer x, integer y) = x >= y;
predicate y_positive(integer y) = y > 0;
predicate x_less_1000(integer x) = x < 1000;
predicate x_nonneg(integer x) = x >= 0;

lemma complex_calc_example_lemma: \forall integer x, integer y; x_ge_y(x, y) && y_positive(y) && x_less_1000(x) ==> x_nonneg(x) && y_positive(y);
*/

/*@ requires x >= y && y > 0 && x < 1000;
    ensures x >= 0 && y > 0;
*/
void complex_calc_example(int x, int y)
{
    // Variable declarations at top of scope
    int x_local = x;
    int y_local = y;
    
    //@ assert x_local >= y_local;
    //@ assert y_local > 0;
    //@ assert x_local < 1000;
    //@ assert x_local >= 0;
}

int main() {
    return 0;
}
