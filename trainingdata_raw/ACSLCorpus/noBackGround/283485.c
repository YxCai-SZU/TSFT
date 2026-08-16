/*@
    requires a != 0 || b != 0;
    ensures \result != 0 <==> (((a) != 0 && (b) == 0) || ((a) == 0 && (b) != 0) ? 1 : 0) != 0;
    assigns \nothing;
*/
int exclusive_or_func(int a, int b) {
    int result;
    //@ assert a != 0 || b != 0;
    result = (a && !b) || (!a && b);
    //@ assert result != 0 <==> (((a) != 0 && (b) == 0) || ((a) == 0 && (b) != 0) ? 1 : 0) != 0;
    return result;
}

int main() {
    int a, b, c;
    
    a = 1; b = 1; c = 1;
    //@ assert ((a) != 0 && (b) != 0 && (c) != 0);
    
    a = 1; b = 0; c = 1;
    //@ assert !((a) != 0 && (b) != 0 && (c) != 0);
    
    a = 0; b = 1; c = 0;
    //@ assert ((a) != 0 || (b) != 0 || (c) != 0);
    
    return 0;
}
