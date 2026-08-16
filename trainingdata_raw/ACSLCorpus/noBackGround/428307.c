/*@
    requires (1 <= (a) <= 10000) && (1 <= (b) <= 10000) && (1 <= (c) <= 10000) && (1 <= (d) <= 10000);
    ensures \result == ((a) * (b)) || \result == ((c) * (d));
    ensures \result >= ((a) * (b));
    ensures \result >= ((c) * (d));
    assigns \nothing;
*/
int func(int a, int b, int c, int d)
{
    int result;
    int ab_product;
    int cd_product;

    //@ assert (1 <= (a) <= 10000);
    //@ assert (1 <= (b) <= 10000);
    //@ assert (1 <= (c) <= 10000);
    //@ assert (1 <= (d) <= 10000);
    
    ab_product = a * b;
    cd_product = c * d;
    
    //@ assert ab_product == ((a) * (b));
    //@ assert cd_product == ((c) * (d));
    
    //@ assert ab_product >= 1;
    //@ assert cd_product >= 1;
    
    //@ assert ab_product <= 100000000;
    //@ assert cd_product <= 100000000;
    
    if (ab_product > cd_product) {
        result = ab_product;
    } else {
        result = cd_product;
    }
    
    //@ assert result == ab_product || result == cd_product;
    //@ assert result >= ab_product;
    //@ assert result >= cd_product;
    
    return result;
}
