/*@
    requires \true;
    ensures \true;
*/
void main_experimenter() {
    int x;
    int y;
    
    x = 2;
    y = 5;
    
    //@ assert (0 <= (x) && (x) <= 5);
    //@ assert (0 <= (y) && (y) <= 5);
    //@ assert x != y;
}

int main() {
    main_experimenter();
    return 0;
}
