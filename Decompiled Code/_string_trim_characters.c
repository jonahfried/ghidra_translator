
void _string_trim_characters(char **param_1,char *param_2)

{
  char *pcVar1;
  bool bVar2;
  char *local_28;
  char *local_20;
  
  if (param_1 == (char **)0x0) {
    _fprintf(*(FILE **)PTR____stderrp_10000a038,
             "Error: The String object is NULL in string_trim_characters.\n");
  }
  else if (*param_1 == (char *)0x0) {
    _fprintf(*(FILE **)PTR____stderrp_10000a038,
             "Error: The dataStr of String object is NULL in string_trim_characters.\n");
  }
  else if (param_2 == (char *)0x0) {
    _fprintf(*(FILE **)PTR____stderrp_10000a038,
             "Error: The chars parameter is NULL in string_trim_characters.\n");
  }
  else {
    local_20 = *param_1;
    local_28 = *param_1 + (long)param_1[1] + -1;
    while( true ) {
      bVar2 = false;
      if (local_20 <= local_28) {
        pcVar1 = _strchr(param_2,(int)*local_20);
        bVar2 = pcVar1 != (char *)0x0;
      }
      if (!bVar2) break;
      local_20 = local_20 + 1;
    }
    while( true ) {
      bVar2 = false;
      if (local_20 < local_28) {
        pcVar1 = _strchr(param_2,(int)*local_28);
        bVar2 = pcVar1 != (char *)0x0;
      }
      if (!bVar2) break;
      local_28 = local_28 + -1;
    }
    local_28 = local_28 + (1 - (long)local_20);
    ___memmove_chk(*param_1,local_20,local_28,0xffffffffffffffff);
    (*param_1)[(long)local_28] = '\0';
    param_1[1] = local_28;
  }
  return;
}

