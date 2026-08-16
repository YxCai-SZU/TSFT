/*@
requires \true;
ensures \result == 0;
assigns \nothing;
*/
int main() {
    int a;
    int b;
    int c;
    
    a = 2 * 3;
    //@ assert a <= 6;
    
    b = a + 2;
    //@ assert b <= 8;
    
    c = b + 1;
    //@ assert c <= 9;
    
    return 0;
}
