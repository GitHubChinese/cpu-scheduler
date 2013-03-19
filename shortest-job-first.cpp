# include "shortest-job-first.h"
# include "string.h"
# include "string"

ShortestJobFirst::ShortestJobFirst(vector<Pcb> processes) : SchedulingAlgorithm(processes) {
}


int ShortestJobFirst::selectProcess() 
{
        vector<Pcb> readyQueue = getReadyQueue();

        int pidOfSelectedProcess = -1; 
	int indexOfProcessToBeRemoved;

	if( readyQueue.size() > 0 ) 
	{
		pidOfSelectedProcess = 0;
                
		int shortestBurst = readyQueue.front().getCpuBurst(readyQueue.front().getCurrentCpuBurst());
	               
		for( int i = 0; i < readyQueue.size(); i++) 
		{
	        	if( readyQueue[i].getCpuBurst(readyQueue[i].getCurrentCpuBurst()) < shortestBurst ) 
			{
	                	shortestBurst = readyQueue[i].getCpuBurst(readyQueue[i].getCurrentCpuBurst());
	                        pidOfSelectedProcess = readyQueue[i].getPid();
				indexOfProcessToBeRemoved = i;
	                }
                }
		setCurrentProcess(readyQueue[indexOfProcessToBeRemoved]);
		readyQueue.erase(readyQueue.begin() + indexOfProcessToBeRemoved);
		setReadyQueue(readyQueue);
        }
        else{
        	cout << "No process in the Ready Queue";
        }
        
	return pidOfSelectedProcess;
}

