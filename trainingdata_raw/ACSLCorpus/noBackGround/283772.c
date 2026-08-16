/*@
    requires (0 <= (a) && (a) <= 100 && 0 <= (b) && (b) <= 100);
    ensures \result >= 0;
    ensures \result == ((a) * (b)) || \result == b;
    assigns \nothing;
*/
int func(int a, int b)
{
    // Variable declarations at scope top
    int product;
    int result;
    
    //@ assert (0 <= (a) && (a) <= 100 && 0 <= (b) && (b) <= 100);
    
    //@ assert 0 <= ((a) * (b)) && ((a) * (b)) <= 10000;
    
    product = a * b;
    
    if (product > b) {
        result = product;
    } else {
        result = b;
    }
    
    //@ assert result >= 0;
    //@ assert result == ((a) * (b)) || result == b;
    
    return result;
}

int main() {
    return 0;
}
