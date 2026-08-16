/*@
    requires (1 <= (a) && (a) <= 10000) && (1 <= (b) && (b) <= 10000) && (1 <= (c) && (c) <= 10000) && (1 <= (d) && (d) <= 10000);
    ensures \result <= c + d;
    assigns \nothing;
*/
unsigned int func(unsigned int a, unsigned int b, unsigned int c, unsigned int d)
{
    unsigned int result = 0;
    unsigned int min_val;
    unsigned int remaining;
    unsigned int min_val2;
    
    //@ assert (1 <= (a) && (a) <= 10000) && (1 <= (b) && (b) <= 10000) && (1 <= (c) && (c) <= 10000) && (1 <= (d) && (d) <= 10000);
    
    if (a < b) {
        min_val = a;
    } else {
        min_val = b;
    }
    
    //@ assert min_val == ((a) < (b) ? (a) : (b));
    
    if (c >= min_val) {
        result += min_val;
        remaining = c - min_val;
        
        //@ assert result <= c + d;
        
        if (remaining > 0) {
            unsigned int temp1 = a - min_val;
            unsigned int temp2 = b;
            
            if (temp1 < temp2) {
                min_val2 = temp1;
            } else {
                min_val2 = temp2;
            }
            
            if (min_val2 < remaining) {
                result += min_val2 / 2;
            } else {
                result += remaining / 2;
            }
            
            //@ assert result <= c + d;
        }
    } else {
        result += c / 2;
        //@ assert result <= c + d;
    }
    
    //@ assert result <= c + d;
    return result;
}
