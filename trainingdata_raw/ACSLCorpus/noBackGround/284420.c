/*@
    requires \valid(x) && \valid(y);
    requires 0 <= *x && *x <= 8;
    requires 0 <= *y && *y <= 8;
    ensures *x * *y <= 64;
*/
void verify_mult_upper_bound_c(int* x, int* y)
{
    //@ assert (0 <= (*x) && (*x) <= 8);
    //@ assert (0 <= (*y) && (*y) <= 8);
    //@ assert *x * *y <= 64;
}

/*@
    requires \valid(x) && \valid(y);
    ensures *x + *y == *y + *x;
*/
void verify_addition_commutative_c(int* x, int* y)
{
    //@ assert *x + *y == *y + *x;
}

int main()
{
    int x;
    int y;
    
    x = 5;
    y = 6;
    verify_mult_upper_bound_c(&x, &y);
    
    x = 3;
    y = 7;
    verify_addition_commutative_c(&x, &y);
    
    return 0;
}
