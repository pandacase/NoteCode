#include <cstdio>
#include <cstring>
#define N 1010
int s[N][30]; 
//ÿ�д洢һ������ȡʽ���ڶ�ά�±�0~25�����������a~z
//ȡֵ 0: �ñ���û�г��֣�1: �ñ�����֣�2: �ñ��������Ϊ��

int sum0, sum1, sum2; //ʵ�ֶ�S1��S2��S3�������ϵ�ָ��
void store(char str[]) //�������ַ����浽s���飬��ǵ�S2
{
	memset(s, 0, sizeof(s));//�����ַ� 0������s��ָ����ַ�����ǰsizeof(s)���ַ�,ʹ��s��Ԫ�س�ʼ����  
	sum0 = sum1 = -1; sum2 = 0;
	int len = strlen(str);
	int i = 0; 
	while (i <= len)
	{
		if (str[i] >= 'a' && str[i] <= 'z') s[sum2][str[i] - 'a'] = 1;
		else if (str[i] == '&') sum2++;
		else if (str[i] == '!') s[sum2][str[++i] - 'a'] = 2;
		i++;
	}
}

bool same(int a[], int b[]) //�ж�������ȡʽ�Ƿ���ͬ
{
	for (int i = 0; i < 26; i++)
		if (a[i] != b[i]) return false;
	return true;
}

bool check(int c[]) //���S1��S2��S3���Ƿ����ظ�
{
	for (int i = 0; i <= sum2; i++)
		if (same(s[i], c)) return false;
	return true;
}

bool res(int a[], int b[]) //���⺯�������õ����Ӿ䣬����false�����򷵻�true
{
	int single = 0; //��������ı������
	int couple = 0; //������ı������
	for (int i = 0; i < 26; i++)
	{
		if (!a[i] && !b[i]) continue;
		if ((a[i] == 1 && b[i] == 2) || (a[i] == 2 && b[i] == 1)) couple++;
		else single++;
	}

	if (couple != 1) return true; //����������ж�Կ�������
	if (!single) return false; //ֻ��һ�Կ�������û�в�������ı���õ����Ӿ�

	int c[30]; //������
	for (int i = 0; i < 26; i++)
	{
		if ((!a[i] && !b[i]) || (a[i] + b[i] == 3)) c[i] = 0;
		else if (a[i] == 1 || b[i] == 1) c[i] = 1;
		else c[i] = 2;
	}

	if (check(c)) //���c��S0��S1��S2���Ƿ���ֹ�
	{
		sum2++; //��c����S2
		for (int i = 0; i < 26; i++) s[sum2][i] = c[i];
	}
	return true;
}


int main()
{
	char str[N];
	printf("���룺"); 
	scanf("%s", str);
	store(str);
	do
	{
		sum0 = sum1; sum1 = sum2; //��S1����S0�У���S1����S2�����S2 
		for (int i = 0; i <= sum0; i++)
			for (int j = sum0 + 1; j <= sum1; j++)
				if (!res(s[i], s[j]))
				{
					printf("NO\n");
					return 0;
				}
		for (int i = sum0 + 1; i <= sum1; i++)
			for (int j = i + 1; j <= sum1; j++)
				if (!res(s[i], s[j]))
				{
					printf("NO\n");
					return 0;
				}
	} while (sum2 > sum1); //��S2Ϊ�գ�����
	printf("YES\n");
	return 0;
}

