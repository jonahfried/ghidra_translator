
int _string_find_last_of(char **param_1,char *param_2,char *param_3)

{
  bool bVar1;
  char *local_38;
  int local_2c;
  int local_c;
  
  if ((param_1 == (char **)0x0) || (*param_1 == (char *)0x0)) {
    _fprintf(*(FILE **)PTR____stderrp_10000a038,
             "Error: The String object or its data is NULL in string_find_last_of.\n");
    local_c = -1;
  }
  else if (param_2 == (char *)0x0) {
    _fprintf(*(FILE **)PTR____stderrp_10000a038,
             "Error: The buffer is NULL in string_find_last_of.\n");
    local_c = -1;
  }
  else if (param_3 < param_1[1]) {
    local_2c = -1;
    local_38 = _strstr(*param_1,param_2);
    while( true ) {
      bVar1 = false;
      if (local_38 != (char *)0x0) {
        bVar1 = local_38 + -(long)*param_1 <= param_3;
      }
      if (!bVar1) break;
      local_2c = (int)local_38 - (int)*param_1;
      local_38 = _strstr(local_38 + 1,param_2);
    }
    local_c = local_2c;
  }
  else {
    _fprintf(*(FILE **)PTR____stderrp_10000a038,
             "Error: Position out of bounds in string_find_last_of.\n");
    local_c = -1;
  }
  return local_c;
}

