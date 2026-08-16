#include <stdbool.h>

/* ACSL predicates for the first function */
/*@
    predicate is_multiple(integer x) =
        x % 2 == 0 && x % 3 == 0 && x % 5 == 0;

    lemma multiple_lemma:
        \forall integer x; is_multiple(x) ==> x % 30 == 0;
*/

/* ACSL predicate for the second function */
/*@ predicate within_range(integer x) = 1 <= x && x <= 13; */

/* First original function - checks all elements are multiples of 2,3,5 */
bool process_list(const unsigned int *v, unsigned int len) {
    unsigned int j = 0;
    while (j < len) {
        //@ assert is_multiple(v[j]);
        if (!(v[j] % 2 == 0 && v[j] % 3 == 0 && v[j] % 5 == 0)) {
            return false;
        }
        j++;
    }
    return true;
}

/* Second original function - checks if sum of three numbers is less than 22 */
bool func(unsigned int a, unsigned int b, unsigned int c)
{
    bool flag = false;
    unsigned int sum = 0;
    
    //@ assert within_range(a);
    //@ assert within_range(b);
    //@ assert within_range(c);
    //@ assert a + b <= 26;
    //@ assert a + b + c <= 39;
    
    if (a + b + c < 22) {
        flag = true;
    }
    
    return flag;
}

/* 
 * Synthesized function: Blackjack Hand Validator
 * 
 * Real-world scenario: In a simplified blackjack game, a hand consists of 
 * multiple cards. Each card value is a multiple of 30 (representing a 
 * transformed value), and we extract 3 specific cards from positions to 
 * check if the hand is "valid" (sum < 22, like a safe blackjack hand).
 * 
 * Data flow: 
 * 1. First, validate that all cards in the hand have proper values 
 *    (are multiples of 2,3,5) using process_list
 * 2. Then, extract three specific card values and check their sum 
 *    using func to determine if it's a safe hand
 * 3. The high-level property: if the hand is valid (all multiples) and 
 *    the three extracted cards are within the blackjack range, 
 *    then the final result correctly indicates a safe hand
 */
bool validate_blackjack_hand(const unsigned int *v, unsigned int len) {
    bool list_valid = process_list(v, len);
    //@ assert list_valid == true;
    //@ assert \forall integer i; 0 <= i < len ==> is_multiple(v[i]);
    
    //@ assert v[0] % 30 == 0 && v[1] % 30 == 0 && v[2] % 30 == 0;
    
    unsigned int card1 = v[0] / 30;
    unsigned int card2 = v[1] / 30;
    unsigned int card3 = v[2] / 30;
    
    //@ assert within_range(card1) && within_range(card2) && within_range(card3);
    
    bool hand_safe = func(card1, card2, card3);
    
    //@ assert hand_safe == (card1 + card2 + card3 < 22);
    
    //@ assert hand_safe == (v[0]/30 + v[1]/30 + v[2]/30 < 22);
    
    return hand_safe;
}

int main() {
    unsigned int hand[] = {30, 60, 90, 120, 150};  // Values: Ace(1), 2, 3, 4, 5
    unsigned int len = 5;
    bool result = validate_blackjack_hand(hand, len);
    //@ assert result == true;  // 1 + 2 + 3 = 6 < 22
    return 0;
}
