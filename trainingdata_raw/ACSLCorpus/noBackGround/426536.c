/*@
    requires (1 <= (x) && (x) <= 10) && (1 <= (y) && (y) <= 10) && (1 <= (z) && (z) <= 10);
    ensures \result == ( (x * y * z) % 2 != 0 );
    assigns \nothing;
*/
int func(unsigned long long x, unsigned long long y, unsigned long long z) {
    // Variable declarations at top of scope
    unsigned long long result;
    int is_odd;
    unsigned long long temp_result;

    //@ assert ((x) * (y) * (z)) <= 1000;
    result = x * y * z;

    is_odd = 0;
    temp_result = result;

    /*@
        loop invariant 0 <= temp_result <= result;
        loop invariant temp_result % 2 == result % 2;
        loop invariant is_odd == 0;
        loop assigns temp_result, is_odd;
        loop variant temp_result;
    */
    while (temp_result >= 2) {
        temp_result -= 2;
    }

    if (temp_result == 1) {
        is_odd = 1;
    }

    //@ assert is_odd == (result % 2 == 1);
    return is_odd;
}

/*@
    assigns \nothing;
*/
int main() {
    return 0;
}
