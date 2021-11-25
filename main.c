#include <stdio.h>

int programSize = 50;
char program[50] = ">>>>>>>>>>*<<<<<<<<<<*[>*<*>]*<*[<*>*<]";
int dataSize = 20;
int data[20];
int stack[5];
int stackIndex = -1;
unsigned char debug = 1;
int jump = 0;

int main(void)
{
	int index = 0;
	int pc = 0;
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
					while((int)program[i] != 93 && i < programSize)
						i++;
				}
				else {
					index++;
					stack[index] = i;
				}
				//printf("[\ - stack=%d\r\n", stack[index]);
				break;
			case 93:
				if(index>0)
				{
					i = stack[index];
					index--;
					jump = 1;
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
