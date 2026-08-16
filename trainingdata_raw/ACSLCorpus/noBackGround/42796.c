/*@
    requires (1 <= (a) <= 100) && (1 <= (b) <= 100) && (1 <= (c) <= 100);
    ensures \result == 1 || \result == 2 || \result == 3;
    assigns \nothing;
*/
int func(int a, int b, int c)
{
    int max;
    int l;
    int result;

    //@ assert (1 <= (a) <= 100) && (1 <= (b) <= 100) && (1 <= (c) <= 100);
    
    if (a >= b && a >= c) {
        max = a;
    } else if (b >= a && b >= c) {
        max = b;
    } else {
        max = c;
    }

    //@ assert max == (((a) >= (b) && (a) >= (c)) ? (a) :         ((b) >= (a) && (b) >= (c)) ? (b) :         (c));
    //@ assert max >= a && max >= b && max >= c;

    l = a + b + c;

    //@ assert l == a + b + c;

    if (l == max * 3) {
        //@ assert l == max * 3;
        result = 1;
    } else if (l > max * 3) {
        //@ assert l > max * 3;
        result = 2;
    } else {
        //@ assert l < max * 3;
        result = 3;
    }

    //@ assert result == 1 || result == 2 || result == 3;
    return result;
}
