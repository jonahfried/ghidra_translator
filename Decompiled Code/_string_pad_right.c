
void _string_pad_right(void **param_1,void *param_2,char param_3)

{
  void *pvVar1;
  void *pvVar2;
  void *pvVar3;
  
  if (param_1 == (void **)0x0) {
    _fprintf(*(FILE **)PTR____stderrp_10000a038,"Error: Null String object in string_pad_right.\n");
  }
  else if (param_1[1] < param_2) {
    pvVar1 = param_1[1];
    pvVar2 = (void *)((long)param_1[1] + ((long)param_2 - (long)pvVar1));
    pvVar3 = _realloc(*param_1,(long)pvVar2 + 1);
    if (pvVar3 == (void *)0x0) {
      _fprintf(*(FILE **)PTR____stderrp_10000a038,
               "Error: Failed to allocate memory in string_pad_right.\n");
    }
    else {
      ___memset_chk((long)pvVar3 + (long)param_1[1],(int)param_3,(long)param_2 - (long)pvVar1,
                    0xffffffffffffffff);
      *(undefined *)((long)pvVar3 + (long)pvVar2) = 0;
      *param_1 = pvVar3;
      param_1[1] = pvVar2;
      param_1[2] = (void *)((long)pvVar2 + 1);
    }
  }
  else {
    _fprintf(*(FILE **)PTR____stderrp_10000a038,
             "Error: Size of String object is bigger or equal that total Length in string_pad_right.\n"
            );
  }
  return;
}

