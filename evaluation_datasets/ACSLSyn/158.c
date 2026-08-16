#include <stdbool.h>

/*@
    predicate valid_range(integer x) = 1 <= x <= 13;
    predicate valid_range2(integer a, integer b, integer low, integer high) =
        low <= a <= high && low <= b <= high;
    predicate same_season(integer a, integer c) =
        (a <= 5 && c <= 5) || (a > 5 && c > 5);

    logic integer sum(integer a, integer b, integer c) = a + b + c;

    predicate valid_date_range(integer month, integer day) =
        1 <= month <= 12 && 1 <= day <= 31;

    predicate valid_hand(integer card1, integer card2, integer card3) =
        valid_range(card1) && valid_range(card2) && valid_range(card3);

    predicate valid_season_hand(integer month1, integer day1, integer month2, integer day2) =
        valid_date_range(month1, day1) && valid_date_range(month2, day2) && same_season(month1, month2);
*/

bool card_game_func(unsigned long a, unsigned long b, unsigned long c)
{
    unsigned long d;

    //@ assert valid_range(a);
    //@ assert valid_range(b);
    //@ assert valid_range(c);
    
    d = a + b + c;
    
    //@ assert d == sum(a, b, c);
    
    return d < 22;
}

int date_game_func(int a, int b, int c, int d)
{
    bool is_valid_date;
    
    //@ assert valid_range2(a, c, 1, 12);
    //@ assert valid_range2(b, d, 1, 31);
    
    if (a <= 5 && c <= 5) {
        is_valid_date = true;
    } else if (a > 5 && c > 5) {
        is_valid_date = true;
    } else {
        is_valid_date = false;
    }
    
    if (is_valid_date) {
        //@ assert is_valid_date == true;
        return 1;
    } else {
        //@ assert is_valid_date == false;
        return 0;
    }
}

int seasonal_card_game(unsigned long card1, unsigned long card2, unsigned long card3,
                       int month1, int day1, int month2, int day2)
{
    bool hand_valid = card_game_func(card1, card2, card3);
    int date_valid = date_game_func(month1, day1, month2, day2);
    
    /*@
        assert (hand_valid == (sum(card1, card2, card3) < 22)) &&
               (date_valid == 1 ==> (same_season(month1, month2) && 
                valid_range2(month1, month2, 1, 12) && valid_range2(day1, day2, 1, 31)));
    */
    
    if (hand_valid && date_valid == 1) {
        return 1;
    } else {
        return 0;
    }
}
