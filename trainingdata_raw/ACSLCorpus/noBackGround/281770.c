/*@
    requires (1 <= (n) && (n) <= 100);
    ensures \result == (((n) * ((n) + 1)) / 2);
*/
unsigned long func(unsigned long n) {
    unsigned long result;
    unsigned long i;
    
    //@ assert (1 <= (n) && (n) <= 100);
    
    result = 0;
    i = 1;
    
    /*@
        loop invariant 1 <= i && i <= n + 1;
        loop invariant result == (((i - 1) * ((i - 1) + 1)) / 2);
        loop invariant i <= n + 1;
        loop assigns result, i;
        loop variant n - i + 1;
    */
    while (i <= n) {
        //@ assert 0 <= i * (i + 1) && i * (i + 1) <= 100 * (100 + 1);
        
        //@ assert result + i >= result;
        
        //@ assert result + i == (((i) * ((i) + 1)) / 2);
        
        result += i;
        i += 1;
    }
    
    //@ assert result == (((n) * ((n) + 1)) / 2);
    
    return result;
}

int main() {
    return 0;
}
