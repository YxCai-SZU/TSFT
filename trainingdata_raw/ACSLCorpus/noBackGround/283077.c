#include <limits.h>

/*@
    requires (0 <= (x) <= 1000000000);
    ensures ((\result) >= 0);
    ensures \result == (1000 * ((x) / 1000) + 
        100 * (((x) % 1000) / 100) + 
        10 * ((((x) % 1000) % 100) / 10) + 
        (((x) % 1000) % 100) % 10);
*/
int func(int x) {
    int result;
    int value;
    int thousands;
    int hundreds;
    int tens;
    int ones;
    
    result = 0;
    value = x;
    thousands = 0;
    
    //@ assert value == x;
    
    /*@
        loop invariant 0 <= value <= x;
        loop invariant 0 <= thousands <= x / 1000;
        loop invariant value == x - 1000 * thousands;
        loop assigns value, thousands;
    */
    while (value >= 1000) {
        //@ assert value >= 1000;
        value -= 1000;
        thousands += 1;
        //@ assert value == x - 1000 * thousands;
    }
    //@ assert value == x - 1000 * thousands;
    
    result += thousands * 1000;
    //@ assert result == 1000 * thousands;
    
    hundreds = 0;
    
    /*@
        loop invariant 0 <= value <= x;
        loop invariant 0 <= hundreds <= (x - 1000 * thousands) / 100;
        loop invariant value == x - 1000 * thousands - 100 * hundreds;
        loop assigns value, hundreds;
    */
    while (value >= 100) {
        //@ assert value >= 100;
        value -= 100;
        hundreds += 1;
        //@ assert value == x - 1000 * thousands - 100 * hundreds;
    }
    //@ assert value == x - 1000 * thousands - 100 * hundreds;
    
    result += hundreds * 100;
    //@ assert result == 1000 * thousands + 100 * hundreds;
    
    tens = 0;
    
    /*@
        loop invariant 0 <= value <= x;
        loop invariant 0 <= tens <= (x - 1000 * thousands - 100 * hundreds) / 10;
        loop invariant value == x - 1000 * thousands - 100 * hundreds - 10 * tens;
        loop assigns value, tens;
    */
    while (value >= 10) {
        //@ assert value >= 10;
        value -= 10;
        tens += 1;
        //@ assert value == x - 1000 * thousands - 100 * hundreds - 10 * tens;
    }
    //@ assert value == x - 1000 * thousands - 100 * hundreds - 10 * tens;
    
    result += tens * 10;
    //@ assert result == 1000 * thousands + 100 * hundreds + 10 * tens;
    
    ones = value;
    result += ones;
    
    //@ assert result == 1000 * thousands + 100 * hundreds + 10 * tens + ones;
    //@ assert result == (1000 * ((x) / 1000) +          100 * (((x) % 1000) / 100) +          10 * ((((x) % 1000) % 100) / 10) +          (((x) % 1000) % 100) % 10);
    
    return result;
}
