#include <stdbool.h>
#include <limits.h>

int main() {
    int s[3];
    int i;
    
    //@ assert \valid(&s[0]) && \valid(&s[1]) && \valid(&s[2]);
    
    i = 0;
    /*@
        loop invariant 0 <= i <= 3;
        loop invariant \forall integer j; 0 <= j < i ==> s[j] == ((3) * (j));
        loop assigns i, s[0..2];
    */
    while (i < 3) {
        s[i] = 3 * i;
        //@ assert s[i] == ((3) * (i));
        i = i + 1;
    }
    
    //@ assert s[0] == 0;
    //@ assert s[1] == 3;
    //@ assert s[2] == 6;
    //@ assert s[0] + s[1] + s[2] == 9;
    
    return 0;
}
