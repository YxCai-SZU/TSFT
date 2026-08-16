/*@
predicate is_greater(integer x, integer y) = x > y;
predicate is_greater_or_equal(integer x, integer y) = x >= y;
predicate is_less(integer x, integer y) = x < y;
predicate is_less_or_equal(integer x, integer y) = x <= y;

lemma calc_example_5: \forall integer x, y; is_greater(x, y) ==> x - y > 0;
lemma reverse_greater_or_equal: \forall integer x, y; is_greater_or_equal(x, y) ==> is_less_or_equal(y, x);
lemma reverse_greater: \forall integer x, y; is_greater(x, y) ==> is_less(y, x);
*/

/*@
requires x > y;
ensures \result > 0;
*/
int calc_example_5(int x, int y) {
    int result;
    result = x - y;
    //@ assert result > 0;
    return result;
}

/*@
requires x >= y;
ensures \result == 1;
*/
int reverse_greater_or_equal(int x, int y) {
    int check;
    check = (y <= x) ? 1 : 0;
    //@ assert check == 1;
    return check;
}

/*@
requires x > y;
ensures \result == 1;
*/
int reverse_greater(int x, int y) {
    int check;
    check = (y < x) ? 1 : 0;
    //@ assert check == 1;
    return check;
}

int main() {
    return 0;
}
