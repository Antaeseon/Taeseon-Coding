#include<cstdio>
#include<algorithm>
#include<cstring>

char input[1003];
char voca[1003];


int alpahbet(char a)
{
	if (a == 'a' || a == 'b' || a == 'c')
		return 2;
	else if (a == 'd' || a == 'e' || a == 'f')
		return 3;
	else if (a == 'g' || a == 'h' || a == 'i')
		return 4;
	else if (a == 'j' || a == 'k' || a == 'l')
		return 5;
	else if (a == 'm' || a == 'n' || a == 'o')
		return 6;
	else if (a == 'p' || a == 'q' || a == 'r'||a=='s')
		return 7;
	else if (a == 't' || a == 'u' || a == 'v')
		return 8;
	else if (a == 'w' || a == 'x' || a == 'y'||a=='z')
		return 9;
}


int main() {
	int num;
	int www = 1;
	scanf("%d", &num);
	while (num--)
	{

		int innum;
		int inputlen;
		int cnt = 0;
		scanf("%s", input);
		scanf("%d", &innum);
	
		inputlen = strlen(input);

		for (int i = 0; i < innum; i++)
		{
			scanf("%s", voca);
			if (inputlen != strlen(voca))
				continue;

			for (int j = 0; j < inputlen; j++)
			{
				if (input[j] - '0' != alpahbet(voca[j]))
					break;
				if (j == inputlen - 1)
					cnt++;
			}
		}
		printf("#%d %d\n", www++, cnt);
	}
}