
int _string_find(long *param_1,char *param_2,ulong param_3)

{
  char *pcVar1;
  int local_c;
  
  if ((param_1 == (long *)0x0) || (*param_1 == 0)) {
    _fprintf(*(FILE **)PTR____stderrp_10000a038,
             "Error: The String object or its data is NULL in string_find.\n");
    local_c = -1;
  }
  else if (param_2 == (char *)0x0) {
    _fprintf(*(FILE **)PTR____stderrp_10000a038,"Error: The buffer is NULL in string_find.\n");
    local_c = -1;
  }
  else if (param_3 < (ulong)param_1[1]) {
    pcVar1 = _strstr((char *)(*param_1 + param_3),param_2);
    if (pcVar1 == (char *)0x0) {
      local_c = -1;
    }
    else {
      local_c = (int)pcVar1 - (int)*param_1;
    }
  }
  else {
    _fprintf(*(FILE **)PTR____stderrp_10000a038,"Error: Position out of bounds in string_find.\n");
    local_c = -1;
  }
  return local_c;
}

