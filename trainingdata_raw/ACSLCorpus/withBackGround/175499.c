/*@
    predicate is_valid_params(integer x, integer y) =
        1 <= x <= 100 &&
        1 <= y <= 100 &&
        y % 2 == 0;

    logic integer half_of(integer y) = y / 2;

    lemma half_y_property:
        \forall integer y; is_valid_params(100, y) ==> half_of(y) >= 0;
*/

/*@
    requires is_valid_params(x, y);
    ensures \result >= 0;
    ensures (x >= y/2 && \result == x - y/2) || (x < y/2 && \result == 0);
    assigns \nothing;
*/
long func(long x, long y) {
    long half_y = 0;
    long i = 0;

    /*@
        loop invariant 1 <= x <= 100;
        loop invariant 1 <= y <= 100;
        loop invariant y % 2 == 0;
        loop invariant half_y >= 0;
        loop invariant i >= 0;
        loop invariant i <= y;
        loop invariant half_y * 2 == i;
        loop invariant i % 2 == 0;
        loop assigns half_y, i;
    */
    while (i < y) {
        //@ assert i + 2 <= y;
        half_y += 1;
        i += 2;
    }

    //@ assert half_y == y / 2;
    
    if (x > half_y) {
        //@ assert x >= y/2;
        //@ assert x - half_y >= 0;
        return x - half_y;
    } else {
        //@ assert x <= y/2;
        //@ assert 0 >= 0;
        return 0;
    }
}

/*@
    assigns \nothing;
*/
int main() {
    return 0;
}
