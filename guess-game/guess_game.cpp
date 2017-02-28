// guess_game.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
const int N_MAX = 1e3;

int btoi(char* boolstr)
{
  int n = strlen(boolstr);
  int ans = 0;
  for (int i = 0; i < n; ++i){
    assert(boolstr[i] == '0' || boolstr[i] == '1');
    ans += (boolstr[i] - 48) << n - 1 - i;
  }
  return ans;
}

void reverse(char* origin)
{
  int len = strlen(origin), temp = origin[0];
  //printf("len = %d, ", len);
  for (int i = 0; i < len/2; ++i){
    temp = origin[i];
    origin[i] = origin[len - 1 - i];
    origin[len - 1 - i] = temp;
  }
  return ;
}

void complete(char* str, int n)
{
  for (int i = 0; i < n; ++i){
    if (str[i] != '0' && str[i] != '1'){
      str[i] = '0';
    }
  }
  str[n] = 0;
  return ;
}

int _tmain(int argc, _TCHAR* argv[])
{
  int max = 0, ansnum = 0;
  puts("������������ݷ�Χ��");
  scanf_s("%d", &max);
  getchar();
  // max �Ķ�����λ��
  int bits = 0;
  while (max){
    max /= 2;
    ++ bits;
  }
  //printf("%d\n", bits);
  
  // ���Ӵ���ÿһλ������Ϊ'1'��������
  for (int i = 0; i < bits; ++i){
    printf("����ѡ������Ƿ�����ڵ� %d �ű��У�������1��������0��\n", i + 1);
    char jstr[200] = {0}, showstr[200] = {0};  
    for (int j = 0; j < (1 << bits - 1); ++j){
      _itoa_s(j, jstr, 2);  // ��������������ı�ǰbitsλ�����Ὣ�������ַ��ĳɲ���\0
      reverse(jstr);
      complete(jstr, bits - 1);
      // generate showstr[]
      for (int k = 0; k < bits; ++k){
        if (k == i){
          showstr[k] = '1';
        } else if (k < i){
          showstr[k] = jstr[k];
        } else { // k > i
          showstr[k] = jstr[k - 1];
        }
      }
      reverse(showstr);
      //printf("%s ", showstr);
      printf("%d ", btoi(showstr));
    }
    printf("\n�����룺");
    // ����
    char input;
    while (scanf_s("%c", &input)!= EOF){
      //if = 0 or 1
      if (input == '0' || input == '1'){
        if (input == '1'){
          ansnum += 1 << i;
        }
        break;
      } else {
        printf("�����������������!\n������1��������0");
      }
    }
    while ((input = getchar()) != EOF && input != '\n'){}

  }
  printf("��ѡ�������� %d\n", ansnum);
  system("pause");
	return 0;
}

