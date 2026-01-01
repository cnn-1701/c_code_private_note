#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<math.h>

int is_num_su(int num)//����1Ϊ��0Ϊ��
{
	for (int i = 2; i <= sqrt(num); i+=2)
	// �����жϷ�����ʹ��2~i-1����ȡģ
	// �Ż��㷨��
	// ���ۣ���һ���������ܹ�дΪq*p��ʽ��2<=q<=p
	// ���б�Ȼ��һ��������2~sqrt��num��
	// ֻҪ������2~sqrt��num�����ҵ���������
	//
	//2��Ψһż���������ǿ�������������
	{
		if (num % i == 0)
		{
			return 0;
		}
		else
		{
			continue;
		}
	}
	return 1;
}

int main()
{
	int num = 0;
	printf("����������:>");
	
	do
	{
		scanf("%d", &num);
		
		if (is_num_su(num))
		{
			printf("������\n");
		}
		else
		{
			printf("��������\n");
		}
	} while (num);
	return 0;
}