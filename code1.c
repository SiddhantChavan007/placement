#include<stdio.h>

int main()
{
	int counter=0,outer,inner,sizeOfArray;
	fprintf(stdout,"Enter array element\n");
	fscanf(stdin,"%d",&sizeOfArray);
	int array[sizeOfArray];
	for(outer=0;outer<sizeOfArray;outer++)
		fscanf(stdin,"%d",&array[outer]);
	for(outer=0;outer<sizeOfArray;outer++)
	{
		for(inner=0;inner<sizeOfArray;inner++)
		{
			if(array[outer]<array[inner])
				counter++;
			if(counter==2)
				break;
		}
		if(counter==2)
			fprintf(stdout,"%d\t",array[outer]);
		counter=0;
	}
}

