struct account{
  int id;
  float sum;
};

struct aux_struct{
  int id;
  float sum;
};

program BANK_PROG
{
  version BANK_VERS{
    int openAccount(int) = 1;
    int closeAccount(int) = 2;
    int authAccount(int) = 3;
    int deposit(aux_struct) = 4;
    int withdraw(aux_struct) = 5;
    float checkBalance(int) = 6;
  } = 1;
} = 0x12345000;
