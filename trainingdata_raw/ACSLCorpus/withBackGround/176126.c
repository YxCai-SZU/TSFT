/*@
    predicate valid_range(integer x) = 1 <= x && x <= 10;
    
    logic integer sum_ab(integer a, integer b) = a + b;
    logic integer sum_bc(integer b, integer c) = b + c;
    logic integer sum_ac(integer a, integer c) = a + c;
*/

/*@
    requires valid_range(a) && valid_range(b) && valid_range(c);
    ensures \result == sum_ab(a,b) || \result == sum_bc(b,c) || \result == sum_ac(a,c);
    assigns \nothing;
*/
int func(int a, int b, int c)
{
    int ans = 0;
    int min_ab = 0;
    
    //@ assert valid_range(a) && valid_range(b) && valid_range(c);
    
    if (a + b < b + c) {
        min_ab = a + b;
    } else {
        min_ab = b + c;
    }
    
    //@ assert min_ab == sum_ab(a,b) || min_ab == sum_bc(b,c);
    
    if (min_ab < a + c) {
        ans = min_ab;
    } else {
        ans = a + c;
    }
    
    //@ assert ans == sum_ab(a,b) || ans == sum_bc(b,c) || ans == sum_ac(a,c);
    
    return ans;
}

/*@
    requires valid_range(a) && valid_range(b) && valid_range(c);
    ensures \result == sum_ab(a,b) || \result == sum_bc(b,c) || \result == sum_ac(a,c);
    assigns \nothing;
*/
int func2(int a, int b, int c)
{
    int ans = 0;
    int min_ab = 0;
    
    //@ assert valid_range(a) && valid_range(b) && valid_range(c);
    
    if (a + b < b + c) {
        min_ab = a + b;
    } else {
        min_ab = b + c;
    }
    
    //@ assert min_ab == sum_ab(a,b) || min_ab == sum_bc(b,c);
    
    if (min_ab < a + c) {
        ans = min_ab;
    } else {
        ans = a + c;
    }
    
    //@ assert ans == sum_ab(a,b) || ans == sum_bc(b,c) || ans == sum_ac(a,c);
    
    return ans;
}
