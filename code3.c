#include<stdio.h>

struct Process
{
	int processNumber;
	int burstTime;
	int arrivalTime;
	int completeTime;
	int waitTime;
	int turnaroundTime;
};

void getProcessDetails(struct Process *process,int numberOfProcess)
{
	int i;
	for(i=0;i<numberOfProcess;i++)
        {
                fprintf(stdout,"Enter the process number\n");
                fscanf(stdin,"%d",&process[i].processNumber);
                fprintf(stdout,"Enter the process burst time\n");
                fscanf(stdin,"%d",&process[i].burstTime);
                fprintf(stdout,"Enter the process arrival time\n");
                fscanf(stdin,"%d",&process[i].arrivalTime);
        }
}

float calculateWaitTimeAndReturnAverageWait(struct Process *process,int numberOfProcess)
{
	int loop,totalWait=0;
	int temp[numberOfProcess];
	float wt;
	temp[0]=0;
	process[0].waitTime=0;
	for(loop=1;loop<numberOfProcess;loop++)
	{
		temp[loop]=temp[loop-1]+process[loop-1].burstTime;
		process[loop].waitTime=temp[loop]-process[loop].arrivalTime;
		if(process[loop].waitTime<0)
			process[loop].waitTime=0;
		totalWait=totalWait+process[loop].waitTime;
	}
	wt=(totalWait/numberOfProcess);
	return wt;
}

float calculateTurnaroundTimeAndReturnAverage(struct Process *process,int numberOfProcess)
{
	int loop,totalTurnaroundTime=0;
	float tt;
	for(loop=0;loop<numberOfProcess;loop++)
	{
		process[loop].turnaroundTime=process[loop].burstTime+process[loop].waitTime;
		totalTurnaroundTime=totalTurnaroundTime+process[loop].turnaroundTime;
	}
	tt=(totalTurnaroundTime/numberOfProcess);
	return tt;
}


void calculateCompleteTime(struct Process *process,int numberOfProcess)
{
        int loop;
	process[0].completeTime=process[0].burstTime;
        for(loop=0;loop<numberOfProcess;loop++)
        {
                process[loop].completeTime=process[loop].turnaroundTime+process[loop].arrivalTime;
        }
}


void displayProcessDetails(struct Process *process,int numberOfProcess,float averageTurnaroundTime,float averageWaitTime)
{
	int loop;
	fprintf(stdout,"Process Number\tBurst Time\tArrival Time\tComplete Time\tWait Time\tTurnaround Time\n");
	for(loop=0;loop<numberOfProcess;loop++)
	{
		fprintf(stdout,"%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n",process[loop].processNumber,process[loop].burstTime,process[loop].arrivalTime,process[loop].completeTime,process[loop].waitTime,process[loop].turnaroundTime);
	}
	fprintf(stdout,"Average Turnaround Time = %f\n Average Wait Time =%f\n",averageTurnaroundTime,averageWaitTime);
}

int main()
{
	int numberOfProcess;
	float averageTurnaroundTime,averageWaitTime;
	fprintf(stdout,"Enter number of process\n");
	fscanf(stdin,"%d",&numberOfProcess);
	struct Process processArray[numberOfProcess];
	getProcessDetails(processArray,numberOfProcess);
	averageWaitTime=calculateWaitTimeAndReturnAverageWait(processArray,numberOfProcess);
	averageTurnaroundTime=calculateTurnaroundTimeAndReturnAverage(processArray,numberOfProcess);
	calculateCompleteTime(processArray,numberOfProcess);
	displayProcessDetails(processArray,numberOfProcess,averageTurnaroundTime,averageWaitTime);
	return 0;
}
