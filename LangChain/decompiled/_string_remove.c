
void _string_remove(char **param_1,char *param_2)

{
  size_t sVar1;
  size_t sVar2;
  char *local_28;
  
  if (param_1 == (char **)0x0) {
    _fprintf(*(FILE **)PTR____stderrp_10000a038,"Error: Null String object in string_remove.\n");
  }
  else if (param_2 == (char *)0x0) {
    _fprintf(*(FILE **)PTR____stderrp_10000a038,"Error: Null substring in string_remove.\n");
  }
  else if (*param_1 == (char *)0x0) {
    _fprintf(*(FILE **)PTR____stderrp_10000a038,
             "Error: Null data string in String object in string_remove.\n");
  }
  else {
    sVar1 = _strlen(param_2);
    if (sVar1 == 0) {
      _fprintf(*(FILE **)PTR____stderrp_10000a038,"Error: Empty substring in string_remove.\n");
    }
    else {
      sVar1 = _strlen(param_2);
      local_28 = *param_1;
      while( true ) {
        local_28 = _strstr(local_28,param_2);
        if (local_28 == (char *)0x0) break;
        sVar2 = _strlen(local_28 + sVar1);
        ___memmove_chk(local_28,local_28 + sVar1,sVar2 + 1,0xffffffffffffffff);
      }
    }
  }
  return;
}

