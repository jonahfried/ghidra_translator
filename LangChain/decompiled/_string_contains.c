
bool _string_contains(char **param_1,char *param_2)

{
  char *pcVar1;
  bool local_9;
  
  if (param_1 == (char **)0x0) {
    _fprintf(*(FILE **)PTR____stderrp_10000a038,
             "Error: The String object is NULL in string_contains.\n");
    local_9 = false;
  }
  else if (param_2 == (char *)0x0) {
    _fprintf(*(FILE **)PTR____stderrp_10000a038,"Error: The substring is NULL in string_contains.\n"
            );
    local_9 = false;
  }
  else {
    pcVar1 = _strstr(*param_1,param_2);
    local_9 = pcVar1 != (char *)0x0;
  }
  return local_9;
}

