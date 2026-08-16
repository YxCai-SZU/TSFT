#include <stdbool.h>

/*@
    requires (1 <= (a) && (a) <= 12) && (1 <= (b) && (b) <= 31);
    requires (1 <= (c) && (c) <= 12) && (1 <= (d) && (d) <= 31);
    ensures \result == 0 || \result == 1;
    assigns \nothing;
*/
int func(int a, int b, int c, int d) {
    int result;
    //@ assert (1 <= (a) && (a) <= 12) && (1 <= (b) && (b) <= 31);
    //@ assert (1 <= (c) && (c) <= 12) && (1 <= (d) && (d) <= 31);
    
    if (a == c) {
        if (b < d) {
            result = 1;
        } else {
            result = 0;
        }
    } else {
        if (b <= d) {
            result = 1;
        } else {
            result = 0;
        }
    }
    
    //@ assert result == 0 || result == 1;
    return result;
}

enum Season {
    Spring,
    Summer,
    Autumn,
    Winter
};

/*@
    requires (1 <= (month) && (month) <= 12);
    ensures ((month) == 1 || (month) == 2 || (month) == 3) ==> \result == Winter;
    ensures ((month) == 4 || (month) == 5 || (month) == 6) ==> \result == Spring;
    ensures ((month) == 7 || (month) == 8 || (month) == 9) ==> \result == Summer;
    ensures ((month) == 10 || (month) == 11 || (month) == 12) ==> \result == Autumn;
    assigns \nothing;
*/
enum Season get_season(int month) {
    enum Season season;
    //@ assert (1 <= (month) && (month) <= 12);
    
    if (month == 1 || month == 2 || month == 3) {
        //@ assert ((month) == 1 || (month) == 2 || (month) == 3);
        season = Winter;
    } else if (month == 4 || month == 5 || month == 6) {
        //@ assert ((month) == 4 || (month) == 5 || (month) == 6);
        season = Spring;
    } else if (month == 7 || month == 8 || month == 9) {
        //@ assert ((month) == 7 || (month) == 8 || (month) == 9);
        season = Summer;
    } else {
        //@ assert ((month) == 10 || (month) == 11 || (month) == 12);
        season = Autumn;
    }
    
    //@ assert (((month) == 1 || (month) == 2 || (month) == 3) ==> season == Winter);
    return season;
}
