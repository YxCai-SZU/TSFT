/*@
requires \true;
assigns \nothing;
ensures \result == 0;
*/
int main() {
    int a;
    int b;
    
    //@ ghost int ghost_a = a;
    //@ ghost int ghost_b = b;
    
    //@ assert ((ghost_a) < (ghost_b)) ==> ((ghost_b) < (ghost_a) + 3) ==> a <= a + 2;
    //@ assert ((ghost_a) < (ghost_b)) && ((ghost_b) < (ghost_a) + 3) ==> a <= b;
    
    return 0;
}
