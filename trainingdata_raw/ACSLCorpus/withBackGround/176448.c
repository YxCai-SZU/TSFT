#include <limits.h>

/*@
    predicate X_in_range(integer X) = 1 <= X <= 100;
    predicate Y_in_range(integer Y) = 1 <= Y <= 100;
    predicate Y_even(integer Y) = Y % 2 == 0;
*/

/*@
    logic integer half_of(integer Y) = Y / 2;
*/

/*@
    lemma half_of_range: \forall integer Y; Y_in_range(Y) && Y_even(Y) ==> 0 <= half_of(Y) <= 50;
*/

/*@
    requires X_in_range(X) && Y_in_range(Y) && Y_even(Y);
    ensures \result == X + (Y / 2);
    ensures \result <= 150;
*/
int func(int X, int Y) {
    int half_Y;
    int count;
    int temp_Y;
    
    //@ assert X_in_range(X) && Y_in_range(Y) && Y_even(Y);
    
    if (Y >= 0) {
        count = 0;
        temp_Y = Y;
        
        /*@
            loop invariant 0 <= temp_Y <= Y;
            loop invariant 0 <= count <= Y / 2;
            loop invariant temp_Y == Y - 2 * count;
            loop invariant X_in_range(X) && Y_in_range(Y) && Y_even(Y);
            loop assigns temp_Y, count;
            loop variant temp_Y;
        */
        while (temp_Y >= 2) {
            temp_Y -= 2;
            count += 1;
        }
        half_Y = count;
    } else {
        count = 0;
        temp_Y = Y;
        
        /*@
            loop invariant Y <= temp_Y <= 0;
            loop invariant Y / 2 <= count <= 0;
            loop invariant temp_Y == Y - 2 * count;
            loop invariant X_in_range(X) && Y_in_range(Y) && Y_even(Y);
            loop assigns temp_Y, count;
            loop variant -temp_Y;
        */
        while (temp_Y <= -2) {
            temp_Y += 2;
            count -= 1;
        }
        half_Y = count;
    }
    
    //@ assert half_Y == Y / 2;
    //@ assert X + half_Y <= 150;
    
    return X + half_Y;
}

int main() {
    return 0;
}
