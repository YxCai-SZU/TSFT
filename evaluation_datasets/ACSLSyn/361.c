/* Scenario: In a card game scoring system, three players each pick a card (values 1-9).
   The system checks if exactly two cards match (a pair), and if so, computes a bonus score
   based on the unique card's value, then combines it with a base score calculated from
   a separate dice roll (values 1-100) to produce a final score.
   The final score must satisfy: if a pair exists, the bonus is based on the missing number
   from 1-3 (card values mapped to 1-3), and the final score is within valid bounds. */

/*@
    predicate valid_range_1_3(integer x) = 1 <= x <= 3;
    
    lemma subtraction_bound:
        \forall integer a, b;
            valid_range_1_3(a) && valid_range_1_3(b) && a != b ==>
            1 <= 6 - a - b <= 3;
*/

unsigned int func1(unsigned int a, unsigned int b)
{
    unsigned int res;
    
    //@ assert valid_range_1_3(a);
    //@ assert valid_range_1_3(b);
    //@ assert a != b;
    
    res = 6 - a - b;
    
    //@ assert res == 6 - a - b;
    //@ assert res >= 1 && res <= 3;
    
    return res;
}

/* Original func2: computes average of two numbers, each in 1-100 */
/*@
    predicate contains{L}(int *s, integer len, int e) =
        \exists integer i; 0 <= i < len && s[i] == e;

    predicate test_res{L}(int *s, integer len, int e, integer res) =
        (res != 0) <==> contains(s, len, e);
*/

int func2(int a, int b)
{
    int ans;
    //@ assert 1 <= a <= 100 && 1 <= b <= 100;
    ans = (a + b + 1) / 2;
    //@ assert ans <= 100;
    return ans;
}

/* Original func3: finds minimum sum of three out of four numbers */
/*@
    predicate valid_range_10000(integer x) = 1 <= x <= 10000;

    logic integer sum_three(integer a, integer b, integer c) = a + b + c;

    lemma ans_bounds:
        \forall integer a, b, c, d, ans;
        valid_range_10000(a) && valid_range_10000(b) && valid_range_10000(c) && valid_range_10000(d) &&
        (ans == sum_three(a,b,c) || ans == sum_three(a,b,d) ||
         ans == sum_three(a,c,d) || ans == sum_three(b,c,d)) ==>
        0 <= ans <= a + b + c + d;
*/

void func3(int a, int b, int c, int d, int *res) {
    int ans;
    int sa;
    int sc;
    int sb;
    int sd;

    ans = 2147483647;
    //@ assert valid_range_10000(a) && valid_range_10000(b) && valid_range_10000(c) && valid_range_10000(d);
    //@ assert a + b + c <= 30000;
    sa = a + b + c;
    //@ assert a + b + d <= 30000;
    sc = a + b + d;
    //@ assert a + c + d <= 30000;
    sb = a + c + d;
    //@ assert b + c + d <= 30000;
    sd = b + c + d;

    if (sa < ans) {
        ans = sa;
    }
    if (sc < ans) {
        ans = sc;
    }
    if (sb < ans) {
        ans = sb;
    }
    if (sd < ans) {
        ans = sd;
    }

    //@ assert ans <= a + b + c + d;
    *res = ans;
}

/* Original func4: checks if exactly two out of three numbers (1-9) are equal */
/*@
    predicate two_equal_not_three(integer a, integer b, integer c) =
        (a == b && a != c) ||
        (a == c && a != b) ||
        (b == c && a != b);
 */

int func4(int a, int b, int c)
{
    int is_equal;
    is_equal = 0;

    if (a == b)
    {
        is_equal = 1;
    }
    if (a == c)
    {
        is_equal = 1;
    }
    if (b == c)
    {
        is_equal = 1;
    }

    if (is_equal)
    {
        if (a != b || a != c || b != c)
        {
            //@ assert two_equal_not_three(a, b, c);
            return 1;
        }
        else
        {
            return 0;
        }
    }
    else
    {
        return 0;
    }
}

/* Synthesized function: card_game_scoring
   Input: three card values (card1, card2, card3 in 1-9) and two dice values (dice1, dice2 in 1-100)
   and a base array of four numbers (base[0..3] in 1-10000)
   Process:
     1. Check if the three cards contain exactly a pair (using func4)
     2. If a pair exists, identify the unique card value, map it to 1-3 range using modulo,
        then compute the missing number from the set {1,2,3} using func1 (requires distinct values)
     3. Compute a base score from dice values using func2
     4. Compute a minimum sum from the base array using func3
     5. Final score = base_score + (bonus if pair exists, else 0) + min_sum
   Output: final score via pointer
   High-level property: if a pair exists, the bonus is correctly computed as the missing number
   from 1-3, and the final score is non-negative and bounded by the sum of inputs. */
void card_game_scoring(int card1, int card2, int card3, int dice1, int dice2, int base[4], int *final_score)
{
    int has_pair;
    int bonus;
    int base_score;
    int min_sum;
    int unique_val;
    int mapped_val1, mapped_val2;
    
    has_pair = func4(card1, card2, card3);
    
    bonus = 0;
    if (has_pair == 1)
    {
        if (card1 == card2)
        {
            unique_val = card3;
        }
        else if (card1 == card3)
        {
            unique_val = card2;
        }
        else
        {
            unique_val = card1;
        }
        
        mapped_val1 = ((unique_val - 1) % 3) + 1;
        if (mapped_val1 == 1)
        {
            mapped_val2 = 2;
        }
        else
        {
            mapped_val2 = 1;
        }
        //@ assert 1 <= mapped_val1 <= 3 && 1 <= mapped_val2 <= 3 && mapped_val1 != mapped_val2;
        bonus = (int)func1((unsigned int)mapped_val1, (unsigned int)mapped_val2);
        //@ assert 1 <= bonus <= 3;
    }
    
    base_score = func2(dice1, dice2);
    //@ assert base_score <= 100;
    
    func3(base[0], base[1], base[2], base[3], &min_sum);
    //@ assert min_sum >= 0 && min_sum <= base[0] + base[1] + base[2] + base[3];
    
    *final_score = base_score + bonus + min_sum;
    
    //@ assert *final_score >= 0;
    //@ assert *final_score <= 100 + 3 + (base[0] + base[1] + base[2] + base[3]);
    
    /* High-level property: If there is exactly a pair among the cards, then the bonus
       is a number in 1-3 that is the missing element from the set {1,2,3} after mapping
       the unique card value, ensuring the bonus is consistent with the pair detection. */
    //@ assert (has_pair == 1) ==> (1 <= bonus <= 3);
}
