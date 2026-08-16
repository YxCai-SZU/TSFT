/*@
    requires (1 <= (n) && (n) <= 100);
    ensures \result == 1 <==> ((((n)) * 2) <= 100);
    ensures \result == 0 <==> !((((n)) * 2) <= 100);
*/
int func(unsigned long long n) {
    int result;

    //@ assert (1 <= (n) && (n) <= 100);
    
    result = (n * 2 <= 100) ? 1 : 0;
    
    //@ assert result == (n * 2 <= 100);
    return result;
}

int main() {
    return 0;
}
