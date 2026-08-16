/*@
    requires (1 <= (a) && (a) <= 100) && (1 <= (b) && (b) <= 100);
    ensures ((\result) >= 0);
    ensures ((\result) == (((a)) - ((((b))) * 2)) || (\result) == 0);
    assigns \nothing;
*/
int func(int a, int b)
{
    int res;
    //@ assert ((b) * 2) <= 200;
    //@ assert ((a) - (((b)) * 2)) <= 100 - 2 * 1;
    //@ assert ((a) - (((b)) * 2)) >= 1 - 2 * 100;
    res = a - b * 2;
    if (res > 0) {
        return res;
    } else {
        return 0;
    }
}
