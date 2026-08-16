/*@
    requires (1 <= (n) && (n) <= 100000);
    ensures ((((n)) % 100) < 13) ==> \result == 1;
    ensures ((((n)) % 100) < 70 && (((n)) % 100) >= 13) ==> \result == 0;
    ensures ((((n)) % 100) >= 70) ==> \result == 1;
    assigns \nothing;
*/
int func(int n)
{
    int result;
    int mod_val;

    //@ assert (1 <= (n) && (n) <= 100000);
    //@ assert n >= 0;
    mod_val = n % 100;
    //@ assert 0 <= mod_val && mod_val < 100;

    if (mod_val < 13)
    {
        result = 1;
        //@ assert ((((n)) % 100) < 13);
    }
    else if (mod_val < 70)
    {
        //@ assert ((((n)) % 100) < 70 && (((n)) % 100) >= 13);
        result = 0;
    }
    else
    {
        result = 1;
        //@ assert ((((n)) % 100) >= 70);
    }

    return result;
}
