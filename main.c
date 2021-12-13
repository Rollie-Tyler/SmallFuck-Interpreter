#include <stdio.h>

//int programSize = 50;
#define programSize 50
char program[programSize] = ">>>>>>>>>>*<<<<<<<<<<*[>*<*>]*<*[<*>*<]";
//char program[programSize] = "*>>*>*>";
int dataSize = 20;
int data[20];
int stack[5];
int stackIndex = -1;
unsigned char debug = 1;
int jump = 0;

typedef struct openClose {
	int open;
	int close;
} stOpenClose;

int main(void)
{
	int indexOpen = -1;
	int indexClose = 0;
	stOpenClose bracket[programSize];

	int index = 0;
	int pc = 0;

	for(int i=0; i<programSize;i++)
	{
		bracket[i].open = 0;
		bracket[i].close = 0;
	}

	for(int i=0; i<programSize;i++)
	{
		switch((int)program[i])
		{
			case 91:
				indexOpen++;
				bracket[indexOpen].open = i;
				break;
			case 93:
				indexClose = indexOpen;
				while(bracket[indexClose].close != 0)
					indexClose--;
				bracket[indexClose].close = i;
				break;
		}
	}


	for(int i=0; i<programSize;jump?jump=0:i++)
	{
		char c = program[i];
		switch((int)c)
		{
			case 42:
				data[pc] = !data[pc];
				//printf("*\r\n");
				break;
			case 62:
				pc = pc < dataSize ?pc+1:0;
				//printf("> pc=%d\r\n", pc);
				break;
			case 60:
				pc = pc>0?pc-1:dataSize ;
				//printf("< pc=%d\r\n", pc);
				break;
			case 91:
				if(!data[pc])
				{
					//while((int)program[i] != 93 && i < programSize)
					//	i++;
					for(int k=0;k<programSize;k++)
					{
						if(bracket[k].open == i)
						{
							i = bracket[k].close;
							break;
						}
					}
				}
				else {
					//index++;
					//stack[index] = i;
					//i = bracket[index];
				}
				break;
			case 93:
				for(int k=0;k<programSize;k++)
				{
					if(bracket[k].close == i)
					{
						i = bracket[k].open;
						jump = 1;
						break;
					}
				}
				//printf("] - stack=%d\r\n", i);
				break;
			case 20:
			default:
				return 0;
				break;
		}

		if(debug)
		{
			for(int k=0; k<dataSize;k++)
			{
				printf("%d ", data[k]);
			}
			printf("\r\n");
			for(int k=0; k<dataSize;k++)
			{
				pc == k?printf("^ "):printf("  ");
			}
			printf("\r\n");
		}
	}
	return 0;
}
