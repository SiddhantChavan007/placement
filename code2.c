#include<stdio.h>

int isPrime(int element)
{
	int flag=0,loop;
	for(loop=2;loop<=element/2;loop++)
	{
		if(element%loop==0)
		{
			flag=1;
			break;
		}
	}

	if(flag==0)
		return 0;
	else
		return 1;
}


void printAlternatePrime(int array[],int numberOfElement)
{
	int position,counter=1;
	for(position=0;position<numberOfElement;position++)
	{
		if(isPrime(array[position])==0)
		{
			if(counter%2!=0)
			{
				fprintf(stdout,"%d\t",array[position]);
			}
			counter++;
		}

	}
}

int main()
{
	int numberOfElement,position;
	fprintf(stdout,"Enter number of element in an array\n");
	fscanf(stdin,"%d",&numberOfElement);
	int array[numberOfElement];
	fprintf(stdout,"Enter array element\n");
	for(position=0;position<numberOfElement;position++)
	{
		fscanf(stdin,"%d",&array[position]);
	}
	printAlternatePrime(array,numberOfElement);
	
	return 0;
}

