#include <stdbool.h>

/*@
    requires (1 <= (r) <= 9) && (1 <= (g) <= 9) && (1 <= (b) <= 9);
    ensures \result == ((100 * (r) + 10 * (g) + (b)) % 4 == 0);
    assigns \nothing;
*/
bool func(unsigned long r, unsigned long g, unsigned long b) {
    unsigned long ans;
    unsigned long temp_ans;

    ans = 100 * r + 10 * g + b;
    temp_ans = ans;

    /*@
        loop invariant 0 <= temp_ans <= ans;
        loop invariant temp_ans % 4 == ans % 4;
        loop assigns temp_ans;
    */
    while (temp_ans >= 4) {
        //@ assert temp_ans >= 4;
        temp_ans -= 4;
    }

    //@ assert temp_ans == ans % 4;
    return temp_ans == 0;
}

/*@
    assigns \nothing;
*/
int main() {
    return 0;
}
