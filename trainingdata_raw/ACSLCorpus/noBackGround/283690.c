/*@
    requires ((x) != 1 && (x) != 2 && (x) != 3 && (x) != 4 && (x) != 5 &&
        (x) != 6 && (x) != 7 && (x) != 8 && (x) != 9);
    ensures \result == 10;
    assigns \nothing;
*/
int func(int x)
{
    int res;

    //@ assert ((x) != 1 && (x) != 2 && (x) != 3 && (x) != 4 && (x) != 5 &&         (x) != 6 && (x) != 7 && (x) != 8 && (x) != 9);
    res = 10;
    //@ assert res == 10;
    return res;
}
