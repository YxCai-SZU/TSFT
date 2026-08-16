/*@
    requires (1 <= (a) <= 100) && (1 <= (b) <= 100) && (1 <= (h) <= 100) && ((h) % 2 == 0);
    ensures \result == (((h) * ((a) + (b))) / 2);
    assigns \nothing;
*/
int func(int a, int b, int h)
{
    int sum;
    int product;
    unsigned int half;

    sum = a + b;
    //@ assert 1 <= sum && sum <= 200;
    
    product = h * sum;
    //@ assert 1 <= product && product <= 20000;
    
    half = (unsigned int)product / 2U;
    return (int)half;
}
