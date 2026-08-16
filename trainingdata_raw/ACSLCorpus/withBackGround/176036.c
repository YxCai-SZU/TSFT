/*@
    predicate is_even(integer x) = x % 2 == 0;
    predicate in_range(integer x) = 1 <= x && x <= 100;

    lemma half_b_property:
        \forall integer b;
            in_range(b) && is_even(b) ==> b / 2 >= 0;
*/

/*@
    requires in_range(a) && in_range(b) && is_even(b);
    ensures \result == a + (b / 2);
*/
long func(long a, long b) {
    long half_b;
    long count;
    long temp_b;

    if (b >= 0) {
        count = 0;
        temp_b = b;
        /*@
            loop invariant 0 <= temp_b && temp_b <= b;
            loop invariant count <= b / 2;
            loop invariant temp_b == b - 2 * count;
            loop assigns temp_b, count;
        */
        while (temp_b >= 2) {
            temp_b -= 2;
            count += 1;
            //@ assert temp_b == b - 2 * count;
        }
        half_b = count;
    } else {
        count = 0;
        temp_b = b;
        /*@
            loop invariant temp_b <= 0 && temp_b >= b;
            loop invariant count >= b / 2;
            loop invariant temp_b == b - 2 * count;
            loop assigns temp_b, count;
        */
        while (temp_b <= -2) {
            temp_b += 2;
            count -= 1;
            //@ assert temp_b == b - 2 * count;
        }
        half_b = count;
    }

    long ans = a + half_b;
    //@ assert ans == a + (b / 2);
    return ans;
}

int main() {
    return 0;
}
