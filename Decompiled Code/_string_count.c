
long _string_count(char **param_1,char *param_2)

{
  size_t sVar1;
  char *local_30;
  long local_28;
  long local_10;
  
  if (param_1 == (char **)0x0) {
    _fprintf(*(FILE **)PTR____stderrp_10000a038,"Error: Null String object in string_count.\n");
    local_10 = 0;
  }
  else if (param_2 == (char *)0x0) {
    _fprintf(*(FILE **)PTR____stderrp_10000a038,"Error: Null substring in string_count.\n");
    local_10 = 0;
  }
  else if (*param_1 == (char *)0x0) {
    _fprintf(*(FILE **)PTR____stderrp_10000a038,
             "Error: Null data string in String object in string_count.\n");
    local_10 = 0;
  }
  else {
    local_28 = 0;
    local_30 = *param_1;
    while( true ) {
      local_30 = _strstr(local_30,param_2);
      if (local_30 == (char *)0x0) break;
      local_28 = local_28 + 1;
      sVar1 = _strlen(param_2);
      local_30 = local_30 + sVar1;
    }
    local_10 = local_28;
  }
  return local_10;
}

