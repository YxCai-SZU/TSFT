/*@
    requires x > y;
    ensures \result > 0;
*/
int calc_example_5(int x, int y) {
    int result;
    
    //@ assert x > y;
    result = x - y;
    //@ assert result > 0;
    
    return result;
}

/*@
    requires x > y;
    ensures \result >= 1;
*/
int lemma(int x, int y) {
    int result;
    
    //@ assert x > y;
    result = x - y;
    //@ assert result > 0;
    //@ assert result >= 1;
    
    return result;
}

int main() {
    return 0;
}
