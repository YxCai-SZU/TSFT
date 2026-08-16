struct Rectangle {
    unsigned int width;
    unsigned int height;
};

/*@
    requires \true;
    ensures \result == 1;
*/
int landscape_check(void) {
    int result = 1;
    //@ assert result == 1;
    return result;
}

int main(void) {
    struct Rectangle r;
    r.width = 4;
    r.height = 4;
    
    //@ assert ((r.width) == (r.height) ==> (r.width) > 0);
    
    return 0;
}
