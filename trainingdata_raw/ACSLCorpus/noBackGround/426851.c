/*@
    requires (1 <= (a) && (a) <= 100) && (1 <= (b) && (b) <= 100) && (1 <= (c) && (c) <= 100) && (1 <= (d) && (d) <= 100);
    ensures \result == ((a) * (c)) || \result == ((a) * (d)) || 
            \result == ((b) * (c)) || \result == ((b) * (d));
    ensures \result >= 1;
    assigns \nothing;
*/
int func(int a, int b, int c, int d)
{
    // Variable declarations at top of scope
    int max_val;
    int b_c;
    int a_d;
    int b_d;
    
    //@ assert (1 <= (a) && (a) <= 100);
    //@ assert (1 <= (b) && (b) <= 100);
    //@ assert (1 <= (c) && (c) <= 100);
    //@ assert (1 <= (d) && (d) <= 100);
    
    //@ assert 1 <= ((a) * (c)) && ((a) * (c)) <= 10000;
    //@ assert 1 <= ((a) * (d)) && ((a) * (d)) <= 10000;
    //@ assert 1 <= ((b) * (c)) && ((b) * (c)) <= 10000;
    //@ assert 1 <= ((b) * (d)) && ((b) * (d)) <= 10000;
    
    max_val = a * c;
    
    b_c = b * c;
    //@ assert 1 <= b_c && b_c <= 10000;
    max_val = (max_val > b_c) ? max_val : b_c;
    
    a_d = a * d;
    //@ assert 1 <= a_d && a_d <= 10000;
    max_val = (max_val > a_d) ? max_val : a_d;
    
    b_d = b * d;
    //@ assert 1 <= b_d && b_d <= 10000;
    max_val = (max_val > b_d) ? max_val : b_d;
    
    //@ assert max_val >= 1;
    return max_val;
}

int main()
{
    return 0;
}
