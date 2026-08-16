/*@
    requires 1 <= a <= 10000;
    requires 1 <= b <= 10000;
    requires 1 <= c <= 10000;
    requires 1 <= d <= 10000;
    ensures \result == 1 <==> (a - c) * (b - d) < 0;
    assigns \nothing;
*/
int func(int a, int b, int c, int d)
{
    int result;
    int ac_diff;
    int bd_diff;
    int product_val;

    //@ assert (1 <= (a) <= 10000);
    //@ assert (1 <= (b) <= 10000);
    //@ assert (1 <= (c) <= 10000);
    //@ assert (1 <= (d) <= 10000);

    ac_diff = a - c;
    bd_diff = b - d;
    
    //@ assert -9999 <= ac_diff <= 9999;
    //@ assert -9999 <= bd_diff <= 9999;

    product_val = ac_diff * bd_diff;
    
    //@ assert -99980001 <= product_val <= 99980001;
    //@ assert product_val == (a - c) * (b - d);

    result = product_val < 0;
    return result;
}
