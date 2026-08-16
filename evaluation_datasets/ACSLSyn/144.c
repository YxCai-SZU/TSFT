#include <stdint.h>
#include <stdbool.h>
#include <string.h>

/* First snippet: tool cost analysis */
struct Tool {
    char* name;
    unsigned int cost;
};

/*@ predicate is_expensive(struct Tool t) = t.cost > 1000; */

bool evaluate_tool(struct Tool* t) {
    bool result;
    
    result = t->cost > 1000;
    //@ assert result == (t->cost > 1000);
    return result;
}

/* Second snippet: number selection based on range */
/*@
    predicate in_range(integer x, integer y) =
        x <= 100 && y <= 100;

    predicate valid_result(integer ret) =
        ret == -1 || (ret >= 0 && ret <= 205);

    logic integer calculate_ans(integer x_val, integer y_val) =
        2 * (y_val + 1) - x_val;

    lemma ans_in_range:
        \forall integer x, y;
            in_range(x, y) ==>
            (x > 2 * y + 1 || y > x / 2 + 1) ==>
            valid_result(-1);

    lemma ans_calculation_range:
        \forall integer x, y, x_val, y_val, ans;
            in_range(x, y) &&
            x_val == (integer)x &&
            y_val == (integer)y &&
            !(x > 2 * y + 1 || y > x / 2 + 1) &&
            ans == calculate_ans(x_val, y_val) ==>
            ans >= 0 && ans <= 205;
*/

int32_t choose_num(uint32_t x, uint32_t y)
{
    int32_t ret;
    int32_t x_val;
    int32_t y_val;
    int32_t ans;

    ret = 0;
    x_val = 0;
    y_val = 0;
    ans = 0;

    if (x > 2 * y + 1 || y > x / 2 + 1) {
        //@ assert valid_result(-1);
        return -1;
    }

    x_val = (int32_t)x;
    y_val = (int32_t)y;
    ans = 2 * (y_val + 1) - x_val;

    //@ assert ans >= 0 && ans <= 205;
    ret = ans;

    //@ assert valid_result(ret);
    return ret;
}

/* Synthesized function: Tool budget advisor
   Scenario: A budgeting tool that recommends tool purchases based on 
   budget and tool cost. It selects a numeric budget code based on 
   budget parameters, then evaluates if the tool is expensive.
   High-level property: The tool's expensive status matches its cost.
*/
bool budget_advisor(struct Tool* tool, uint32_t budget_x, uint32_t budget_y)
{
    int32_t budget_code;
    bool is_expensive;
    
    budget_code = choose_num(budget_x, budget_y);
    
    is_expensive = evaluate_tool(tool);
    
    //@ assert is_expensive == (tool->cost > 1000);
    return is_expensive;
}
