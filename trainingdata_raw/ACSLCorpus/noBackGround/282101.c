#include <stdbool.h>

/*@
    requires (10 <= (n) && (n) <= 99);
    ensures \result <==> (n / 10 == 9 || n % 10 == 9);
*/
bool func(int n) {
    int num;
    int tens;
    int ones;
    int temp;
    
    num = n;
    tens = 0;
    ones = 0;
    
    temp = num;
    /*@
        loop invariant 10 <= n && n <= 99;
        loop invariant 0 <= temp && temp <= n;
        loop invariant 0 <= tens && tens <= n / 10;
        loop invariant temp == n - tens * 10;
        loop assigns temp, tens;
    */
    while (temp >= 10) {
        temp -= 10;
        tens += 1;
    }
    tens *= 10;
    
    ones = num - tens;
    
    //@ assert tens == 90 || ones == 9 <==> (n / 10 == 9 || n % 10 == 9);
    return tens == 90 || ones == 9;
}
