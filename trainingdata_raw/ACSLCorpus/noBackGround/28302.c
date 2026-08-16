/*@
    requires (1 <= (l) && (l) <= 1000) && ((l) % 3 == 0);
    ensures \result == (((l) * 3) / 3);
    assigns \nothing;
*/
int func(int l) {
    int l2;
    int ans;
    int count;
    int is_negative;
    
    l2 = l * 3;
    ans = 0;
    count = 0;
    is_negative = 0;

    if (l2 < 0) {
        is_negative = 1;
        l2 = -l2;
    }

    /*@
        loop invariant 0 <= l2 <= l * 3;
        loop invariant ans == (l * 3 - l2) / 3;
        loop invariant count == (l * 3 - l2) / 3;
        loop invariant ans == count;
        loop invariant l2 % 3 == 0;
        loop assigns l2, ans, count;
        loop variant l2;
    */
    while (l2 >= 3) {
        l2 -= 3;
        ans += 1;
        count += 1;
    }

    if (is_negative) {
        ans = -ans;
    }

    //@ assert ans == (l * 3) / 3;
    return ans;
}

int main() {
    return 0;
}
