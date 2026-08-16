/*@
requires (1 <= (r) && (r) <= 100);
ensures \result == (2 * (r) * 3);
assigns \nothing;
*/
int func(int r)
{
    int pi;
    int circumference;
    
    pi = 3;
    circumference = 2 * r * pi;
    
    //@ assert circumference == 2 * r * 3;
    
    return circumference;
}

