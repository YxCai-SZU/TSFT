/*@
    requires n <= 1000;
    ensures \result == n*n;
    ensures ((n)*(n) >= 0 && (n)*(n) <= 1000*1000);
*/
int find_square_num(unsigned int n) {
    int x;
    
    x = (int)n;
    
    //@ assert ((x) >= 0 && (x) <= 1000);
    
    //@ assert ((x)*(x) >= 0 && (x)*(x) <= 1000*1000);
    
    //@ assert ((x*x) == (n)*(n));
    
    return x * x;
}
