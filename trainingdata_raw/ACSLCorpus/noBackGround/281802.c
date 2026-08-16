/*@
    requires ((a) > 0 && (a) <= 10000);
    ensures \result == ((a) * 5);
    assigns \nothing;
*/
int perimeter_pentagon(int a)
{
    //@ assert a > 0 && a <= 10000;
    //@ assert a * 5 <= 50000;
    return a * 5;
}

/*@
    requires ((a) > 0 && (a) <= 10000);
    ensures \result == ((a) * 6);
    assigns \nothing;
*/
int perimeter_hexagon(int a)
{
    //@ assert a > 0 && a <= 10000;
    //@ assert a * 6 <= 60000;
    return a * 6;
}

/*@
    requires ((a) > 0 && (a) <= 10000);
    ensures \result == ((a) * 7);
    assigns \nothing;
*/
int perimeter_heptagon(int a)
{
    //@ assert a > 0 && a <= 10000;
    //@ assert a * 7 <= 70000;
    return a * 7;
}

/*@
    requires ((a) > 0 && (a) <= 10000);
    ensures \result == ((a) * 8);
    assigns \nothing;
*/
int perimeter_octagon(int a)
{
    //@ assert a > 0 && a <= 10000;
    //@ assert a * 8 <= 80000;
    return a * 8;
}

/*@
    requires ((a) > 0 && (a) <= 10000);
    ensures \result == ((a) * 9);
    assigns \nothing;
*/
int perimeter_nonagon(int a)
{
    //@ assert a > 0 && a <= 10000;
    //@ assert a * 9 <= 90000;
    return a * 9;
}

/*@
    requires ((a) > 0 && (a) <= 10000);
    ensures \result == ((a) * 10);
    assigns \nothing;
*/
int perimeter_decagon(int a)
{
    //@ assert a > 0 && a <= 10000;
    //@ assert a * 10 <= 100000;
    return a * 10;
}
