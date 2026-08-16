/*@
    predicate bounds(integer k, integer x) =
        1 <= k <= 100 && 1 <= x <= 100000;

    predicate ans_bounds(integer ans) =
        ans >= -1 && ans <= 1;

    predicate loop1_invariant(integer i, integer k, integer x, integer ans) =
        0 <= i <= 2 && bounds(k, x) && ans_bounds(ans);

    predicate loop2_invariant(integer k, integer x, integer i, integer temp_y) =
        bounds(k, x) && 0 <= i <= 1 && temp_y >= 0 && temp_y <= x + i;

    logic integer decreases1(integer i) = 2 - i;
    logic integer decreases2(integer temp_y) = temp_y;

    lemma loop1_decreases: \forall integer i; 0 <= i < 2 ==> decreases1(i) > decreases1(i + 1);
    lemma loop2_decreases: \forall integer k, temp_y; k > 0 && temp_y >= 5*k ==> decreases2(temp_y) > decreases2(temp_y - 5*k);
*/

/*@
    requires bounds(k, x);
    ensures ans_bounds(\result);
    assigns \nothing;
*/
int func(int k, int x) {
    int i;
    int ans;
    int y;
    int ok;
    int temp_y;

    i = 0;
    ans = -1;

    /*@
        loop invariant loop1_invariant(i, k, x, ans);
        loop assigns i, ans, y, ok, temp_y;
        loop variant decreases1(i);
    */
    while (i < 2) {
        //@ assert 1 <= x + i <= 100001;
        y = x + i;
        ok = 1;
        temp_y = y;

        /*@
            loop invariant loop2_invariant(k, x, i, temp_y);
            loop assigns temp_y;
            loop variant decreases2(temp_y);
        */
        while (temp_y >= 5 * k) {
            temp_y -= 5 * k;
        }

        if (temp_y != 0) {
            ok = 0;
        }

        if (ok) {
            ans = 1;
        }

        i += 1;
    }

    return ans;
}

int main() {
    return 0;
}
