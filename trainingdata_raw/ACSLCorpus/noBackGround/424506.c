/*@
    requires (1 <= (b) && (b) <= (a) && (a) <= 20 &&
        1 <= (c) && (c) <= 20);
    ensures \result >= 0;
    ensures \result <= a - b + c;
    assigns \nothing;
*/
int func(int a, int b, int c)
{
    int x;
    int y;

    //@ assert a - b >= 0;
    x = a - b + c;
    
    //@ assert 0 <= x && x <= 40;
    
    if (x < 0) {
        y = 0;
        //@ assert y == 0;
    } else {
        y = x;
        //@ assert y == x;
    }
    
    //@ assert y >= 0;
    //@ assert y <= a - b + c;
    return y;
}
