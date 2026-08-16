/*@
    requires (1 <= (a) && (a) <= 10) && (1 <= (b) && (b) <= 10) && (1 <= (c) && (c) <= 10);
    ensures \result == a * b * c;
    assigns \nothing;
*/
int func(int a, int b, int c)
{
    //@ assert a * b <= 100;
    //@ assert a * b * c <= 1000;
    return a * b * c;
}
