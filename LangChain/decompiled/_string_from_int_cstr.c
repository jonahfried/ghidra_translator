
void * _string_from_int_cstr(undefined4 param_1)

{
  size_t sVar1;
  void *pvVar2;
  char local_1c [12];
  long local_10;
  
  local_10 = *(long *)PTR____stack_chk_guard_10000a030;
  ___sprintf_chk(local_1c,0,0xc,"%d",param_1);
  sVar1 = _strlen(local_1c);
  pvVar2 = _malloc(sVar1 + 1);
  if (pvVar2 != (void *)0x0) {
    ___strcpy_chk(pvVar2,local_1c,0xffffffffffffffff);
  }
  if (*(long *)PTR____stack_chk_guard_10000a030 == local_10) {
    return pvVar2;
  }
                    /* WARNING: Subroutine does not return */
  ___stack_chk_fail();
}

