// Generated C + ACSL

typedef struct {
    char* code;
} Template;

typedef enum {
    Success = 0,
    Failure = 1
} Result;

int SendTemplateMessage(char* mobile, int mobile_len, Template template);

/*@
    requires mobile != \null;
    requires mobile_len >= 10;
    requires \valid_read(mobile + (0 .. mobile_len-1));
    requires \forall integer i; 0 <= i < mobile_len ==> mobile[i] != '\0' || i == mobile_len-1;
    requires smsCode != \null;
    requires smsCode_len > 0;
    requires smsCode_len <= 6;
    requires \valid_read(smsCode + (0 .. smsCode_len-1));
    requires \forall integer i; 0 <= i < smsCode_len ==> smsCode[i] != '\0' || i == smsCode_len-1;
    assigns \nothing;
    ensures \result == 0 || \result == 1;
*/
int SendSMSVerifyCode(char* mobile, int mobile_len, char* smsCode, int smsCode_len)
{
  Template template;
  template.code = smsCode;
  int result = SendTemplateMessage(mobile, mobile_len, template);
  /*@ assert result >= 0 && result <= 2147483647; */
  return result;  // Dafny implicit return
}

/*@
    requires mobile != \null;
    requires mobile_len > 0;
    requires \valid_read(mobile + (0 .. mobile_len-1));
    requires template.code != \null;
    assigns \nothing;
    ensures \result == 0 || \result == 1;
*/
int SendTemplateMessage(char* mobile, int mobile_len, Template template)
{
  int result;
  if (((mobile_len >= 10) && (template.code != "")))
  {
    result = Success;
    /*@ assert result >= 0 && result <= 2147483647; */
  }
  else
  {
    result = Failure;
  }
  return result;  // Dafny implicit return
}