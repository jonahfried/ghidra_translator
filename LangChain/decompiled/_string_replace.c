
void _string_replace(char **param_1,char *param_2,char *param_3)

{
  char *pcVar1;
  size_t sVar2;
  size_t sVar3;
  size_t sVar4;
  char *pcVar5;
  char *pcVar6;
  
  if (param_1 == (char **)0x0) {
    _fprintf(*(FILE **)PTR____stderrp_10000a038,
             "Error: The String object (str1) is NULL in string_replace.\n");
  }
  else if (param_2 == (char *)0x0) {
    _fprintf(*(FILE **)PTR____stderrp_10000a038,"Error: The oldStr is NULL in string_replace.\n");
  }
  else if (param_3 == (char *)0x0) {
    _fprintf(*(FILE **)PTR____stderrp_10000a038,"Error: The newStr is NULL in string_replace.\n");
  }
  else {
    pcVar1 = _strstr(*param_1,param_2);
    if (pcVar1 == (char *)0x0) {
      _fprintf(*(FILE **)PTR____stderrp_10000a038,
               "Warning: oldStr not found in str1 in string_replace.\n");
    }
    else {
      sVar2 = _strlen(param_2);
      sVar3 = _strlen(param_3);
      sVar4 = _strlen(pcVar1 + sVar2);
      pcVar5 = pcVar1 + sVar4 + (sVar3 - (long)*param_1);
      if (param_1[2] < pcVar5 + 1) {
        pcVar6 = (char *)_memory_pool_allocate(param_1[3],pcVar5 + 1);
        if (pcVar6 == (char *)0x0) {
          return;
        }
        ___memcpy_chk(pcVar6,*param_1,(long)pcVar1 - (long)*param_1,0xffffffffffffffff);
        ___memcpy_chk(pcVar6 + (long)(pcVar1 + (sVar3 - (long)*param_1)),pcVar1 + sVar2,sVar4,
                      0xffffffffffffffff);
        *param_1 = pcVar6;
        param_1[2] = pcVar5 + 1;
      }
      else {
        ___memmove_chk(pcVar1 + sVar3,pcVar1 + sVar2,sVar4,0xffffffffffffffff);
      }
      ___memcpy_chk(pcVar1,param_3,sVar3,0xffffffffffffffff);
      param_1[1] = pcVar5;
    }
  }
  return;
}

