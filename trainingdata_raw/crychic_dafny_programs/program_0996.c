// Generated C + ACSL

/*@
    requires userId > 0;
    requires allTodos_len >= 0;
    requires allTodos_len > 0 ==> \valid(allTodos + (0 .. allTodos_len-1));
    requires \forall integer i; 0 <= i < allTodos_len ==> allTodos[i] > 0;
    assigns \nothing;
*/
int ProcessUserTodos(int userId, int* allTodos, int allTodos_len, int user);

/*@
    requires userId > 0;
    assigns \nothing;
*/
void WriteToFile(int userId, int processedData);

/*@
    requires userId > 0;
    requires allTodos_len >= 0;
    requires allTodos_len > 0 ==> \valid(allTodos + (0 .. allTodos_len-1));
    requires \forall integer i; 0 <= i < allTodos_len ==> allTodos[i] > 0;
    assigns \nothing;
*/
void Main(int userId, int* allTodos, int allTodos_len, int user)
{
  int processedData = ProcessUserTodos(userId, allTodos, allTodos_len, user);
  WriteToFile(userId, processedData);
}