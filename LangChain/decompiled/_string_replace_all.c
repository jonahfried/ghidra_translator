
void _string_replace_all(char **param_1,char *param_2,long param_3)

{
  undefined8 *puVar1;
  char *pcVar2;
  size_t sVar3;
  char *local_30;
  
  if (param_1 == (char **)0x0) {
    _fprintf(*(FILE **)PTR____stderrp_10000a038,"Error: Null String object in string_replace_all.\n"
            );
  }
  else if ((param_2 == (char *)0x0) || (param_3 == 0)) {
    _fprintf(*(FILE **)PTR____stderrp_10000a038,"Error: Null substring in string_replace_all.\n");
  }
  else {
    puVar1 = (undefined8 *)_string_create("");
    if (puVar1 == (undefined8 *)0x0) {
      _fprintf(*(FILE **)PTR____stderrp_10000a038,
               "Error: Memory allocation failed in string_replace_all.\n");
    }
    else {
      local_30 = *param_1;
      while( true ) {
        pcVar2 = _strstr(local_30,param_2);
        if (pcVar2 == (char *)0x0) break;
        *pcVar2 = '\0';
        _string_append(puVar1,local_30);
        _string_append(puVar1,param_3);
        sVar3 = _strlen(param_2);
        local_30 = pcVar2 + sVar3;
      }
      _string_append(puVar1,local_30);
      _string_assign(param_1,*puVar1);
      _string_deallocate(puVar1);
    }
  }
  return;
}

