/*@
    requires (1 <= (k) <= 100 && 1 <= (x) <= 100000);
    ensures \result == ((500 * (k)) >= x);
    assigns \nothing;
*/
int func(long long k, long long x) {
    long long max_money;
    int result;

    max_money = 500 * k;
    result = 0;

    //@ assert max_money == (500 * (k));

    if (max_money >= x) {
        result = 1;
    } else {
        //@ assert max_money < x;
        result = 0;
    }

    return result;
}
