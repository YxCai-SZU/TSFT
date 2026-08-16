/*@
    requires x <= 30 && y <= 3;
    ensures \result <= 90;
    assigns \nothing;
*/
unsigned int check_multiplication_bound(unsigned int x, unsigned int y)
{
    //@ assert ((x) <= 30 && (y) <= 3 ==> (x) * (y) <= 90);
    return x * y;
}

/*@
    requires 0 <= x <= 10 && 0 <= y <= 10 && 0 <= z <= 10;
    ensures \result == (x * y) * z;
    ensures \result == x * (y * z);
    assigns \nothing;
*/
int multiplication_associative_proof(int x, int y, int z)
{
    //@ assert (x * y) * z == x * (y * z);
    return (x * y) * z;
}

/*@
    requires 0 <= x <= 10 && 0 <= y <= 10 && 0 <= z <= 10;
    ensures \result == x * (y + z);
    ensures \result == x * y + x * z;
    assigns \nothing;
*/
int multiplication_distributive_proof(int x, int y, int z)
{
    //@ assert x * (y + z) == x * y + x * z;
    return x * (y + z);
}

int main()
{
    unsigned int a;
    unsigned int b;
    int c;
    int d;
    int e;
    
    a = 30;
    b = 3;
    //@ assert a <= 30 && b <= 3;
    unsigned int result1 = check_multiplication_bound(a, b);
    
    c = 10;
    d = 10;
    e = 10;
    //@ assert 0 <= c <= 10 && 0 <= d <= 10 && 0 <= e <= 10;
    int result2 = multiplication_associative_proof(c, d, e);
    
    //@ assert 0 <= c <= 10 && 0 <= d <= 10 && 0 <= e <= 10;
    int result3 = multiplication_distributive_proof(c, d, e);
    
    return 0;
}
