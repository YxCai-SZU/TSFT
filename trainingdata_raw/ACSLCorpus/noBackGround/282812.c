/*@
    requires \valid(x) && \valid(y);
    requires *x > 2 && *y > 3;
    ensures *x + *y > 5;
    assigns \nothing;
*/
void assert_new_inequality(const unsigned int* x, const unsigned int* y)
{
    //@ assert *x > 2 && *y > 3;
    //@ assert *x + *y > 2 + 3;
    //@ assert *x + *y > 5;
}

int main()
{
    unsigned int x;
    unsigned int y;
    
    x = 3;
    y = 4;
    
    assert_new_inequality(&x, &y);
    
    return 0;
}
