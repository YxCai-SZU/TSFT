/*@
    requires (1 <= (b) && (b) <= (a) && (a) <= 20 &&
        1 <= (c) && (c) <= 20);
    ensures \result <= c;
    ensures \result >= 0;
    ensures (c < a - b) ==> \result == 0;
    ensures (c >= a - b) ==> \result == c - a + b;
    assigns \nothing;
*/
unsigned int func(unsigned int a, unsigned int b, unsigned int c)
{
    unsigned int min_val;
    unsigned int ans;

    //@ assert (1 <= (b) && (b) <= (a) && (a) <= 20 &&         1 <= (c) && (c) <= 20);

    if (a - b < c)
    {
        min_val = a - b;
    }
    else
    {
        min_val = c;
    }

    ans = c - min_val;

    //@ assert ans == ((c) - ((((a)) - ((b))) < ((c)) ? (((a)) - ((b))) : ((c))));
    //@ assert ((c) - ((((a)) - ((b))) < ((c)) ? (((a)) - ((b))) : ((c)))) <= c;
    //@ assert ((c) - ((((a)) - ((b))) < ((c)) ? (((a)) - ((b))) : ((c)))) >= 0;

    if (c < a - b)
    {
        //@ assert ans == 0;
    }
    else
    {
        //@ assert ans == c - a + b;
    }

    return ans;
}
