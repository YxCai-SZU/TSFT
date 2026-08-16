/*@
    predicate is_even(integer x) = 0 <= x && x < 10 && (x == 0 || x == 2 || x == 4 || x == 6 || x == 8);
    predicate is_odd(integer x) = 0 <= x && x < 10 && (x == 1 || x == 3 || x == 5 || x == 7 || x == 9);
*/

/*@
    requires 0 <= x <= 9;
    requires 0 <= a <= 9;
    ensures (x < a ==> \result == 0);
    ensures (x >= a ==> \result == 10);
*/
int func(int x, int a)
{
    int ans;
    //@ assert 0 <= x <= 9 && 0 <= a <= 9;
    if (x < a) {
        ans = 0;
        //@ assert ans == 0;
    } else {
        ans = 10;
        //@ assert ans == 10;
    }
    return ans;
}

/*@
    requires 0 <= x <= 9;
    requires 0 <= a <= 9;
    ensures (x < a ==> \result == 0);
    ensures (x >= a ==> \result == 10);
*/
int func2(int x, int a)
{
    int ans;
    //@ assert 0 <= x <= 9 && 0 <= a <= 9;
    if (x < a) {
        ans = 0;
        //@ assert ans == 0;
    } else {
        ans = 10;
        //@ assert ans == 10;
    }
    return ans;
}

/*@
    requires 0 <= x <= 9;
    requires 0 <= a <= 9;
    ensures (x < a ==> \result == 0);
    ensures (x >= a ==> \result == 10);
*/
int func3(int x, int a)
{
    int ans;
    //@ assert 0 <= x <= 9 && 0 <= a <= 9;
    if (x < a) {
        ans = 0;
        //@ assert ans == 0;
    } else {
        ans = 10;
        //@ assert ans == 10;
    }
    return ans;
}
