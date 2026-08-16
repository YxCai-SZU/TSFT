/*@
requires \true;
assigns \nothing;
ensures \true;
*/
int main() {
    int a = 0;
    int b = 1;
    int c = 2;
    
    //@ assert (0 <= (a) && (a) < (b) && (b) < (c) && (c) <= 20);
    //@ assert 0 <= a && a < c && c <= 20;
    
    return 0;
}
