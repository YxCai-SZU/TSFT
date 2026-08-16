/*@
    requires 1 <= x && x <= 3;
    requires 1 <= y && y <= 3;
    requires 1 <= z && z <= 2;
    ensures \result <= 18;
*/
unsigned long long non_linear_arith_example4(unsigned long long x, unsigned long long y, unsigned long long z)
{
    // Variable declarations at top of scope
    unsigned long long xy_product;
    unsigned long long xyz_product;

    //@ assert (1 <= (x) && (x) <= 3);
    //@ assert (1 <= (y) && (y) <= 3);
    //@ assert (1 <= (z) && (z) <= 2);

    xy_product = x * y;
    //@ assert xy_product <= 9;

    xyz_product = xy_product * z;
    //@ assert xyz_product <= 18;

    return xyz_product;
}

int main()
{
    // Variable declarations at top of scope
    unsigned long long result;
    
    result = non_linear_arith_example4(2, 2, 2);
    return 0;
}
