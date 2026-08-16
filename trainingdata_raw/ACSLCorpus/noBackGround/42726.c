/*@
    requires (-100 <= (a) <= 100) && (-100 <= (b) <= 100);
    ensures \result == ((a) + (b)) || \result == ((a) - (b)) || \result == ((a) * (b));
    ensures \result >= ((a) + (b));
    ensures \result >= ((a) - (b));
    ensures \result >= ((a) * (b));
*/
int func(int a, int b) {
    int sum;
    int diff;
    int prod;
    int ans;

    //@ assert (-100 <= (a) <= 100) && (-100 <= (b) <= 100);
    sum = a + b;
    diff = a - b;

    //@ assert -10000 <= a * b <= 10000;
    prod = a * b;

    ans = sum;

    if (diff > ans) {
        ans = diff;
    }
    if (prod > ans) {
        ans = prod;
    }

    //@ assert ans == sum || ans == diff || ans == prod;
    //@ assert ans >= sum;
    //@ assert ans >= diff;
    //@ assert ans >= prod;
    return ans;
}
