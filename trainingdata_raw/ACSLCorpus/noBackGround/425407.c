/*@
    requires x1 == x2 || x2 == x3 || x1 == x3;
    ensures \result <= x1 && \result <= x2 && \result <= x3;
*/
int min_tuplex_concrete(int x1, int x2, int x3) {
    int result;
    
    if (x1 <= x2 && x1 <= x3) {
        result = x1;
    } else if (x2 <= x1 && x2 <= x3) {
        result = x2;
    } else {
        result = x3;
    }
    
    //@ assert result == (((x1) <= (x2) && (x1) <= (x3)) ? (x1) :         ((x2) <= (x1) && (x2) <= (x3)) ? (x2) : (x3));
    
    return result;
}

int main() {
    int a, b, c;
    
    a = 1; b = 1; c = 1;
    //@ assert a == b && b == c && a == c;
    min_tuplex_concrete(a, b, c);
    
    a = 1; b = 2; c = 2;
    //@ assert b == c;
    min_tuplex_concrete(a, b, c);
    
    a = 2; b = 1; c = 1;
    //@ assert b == c;
    min_tuplex_concrete(a, b, c);
    
    return 0;
}
