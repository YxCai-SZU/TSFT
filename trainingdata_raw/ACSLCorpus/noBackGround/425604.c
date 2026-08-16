/*@
    requires (1 <= (n) && (n) <= 100000);
    ensures \result == (((n) / 500) * 1000 + (((n) % 500) / 5) * 5);
    assigns \nothing;
*/
unsigned int func(unsigned int n)
{
    unsigned int res;
    unsigned int n_temp;
    unsigned int num_500s;
    unsigned int num_5s;

    res = 0;
    n_temp = n;

    // Calculate the number of 500s
    num_500s = n_temp / 500;
    res = res + num_500s * 1000;
    n_temp = n_temp % 500;

    // Calculate the number of 5s
    num_5s = n_temp / 5;
    res = res + num_5s * 5;

    //@ assert res == (n / 500) * 1000 + ((n % 500) / 5) * 5;
    return res;
}
