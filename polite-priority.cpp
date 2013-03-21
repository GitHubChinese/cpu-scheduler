#include "INCLUDES/polite-priority.h"

using namespace std;

PolitePriority::PolitePriority() {
	algorithmName = "POLITE PRIORITY";
}

PolitePriority::PolitePriority( vector<Pcb> processes, int timeSlice ) : SchedulingAlgorithm(processes) {
	this->timeSlice = timeSlice;
	algorithmName = "POLITE PRIORITY";
}

int PolitePriority::selectProcess() {
	vector<Pcb> readyQueue = getReadyQueue();
	if( (getCurrentProcess().getCurrentCpuTime() >= this->timeSlice) && (getCurrentProcess().getCurrentCpuTime() % this->timeSlice == 0) ) {
		readyQueue.push_back( getCurrentProcess() );
		isCurrentProcessSet = false;
	}
	if(isCurrentProcessSet == false){
		if( readyQueue.size() > 0 ) {
			int highestPriority = readyQueue[0].getPriority();
			int selectedProcessIndex = 0;
			for( int i = 0; i < readyQueue.size(); i++ ) {
				if( readyQueue[i].getPriority() < highestPriority ) {
					highestPriority = readyQueue[i].getPriority();
					selectedProcessIndex = i;
				}
			}
			setCurrentProcess( readyQueue[selectedProcessIndex] );
			readyQueue.erase( readyQueue.begin() + selectedProcessIndex );
			isCurrentProcessSet = true;
		}
	}
	setReadyQueue( readyQueue );
	return 0;
}

int PolitePriority::getTimeSlice() { 
	return this->timeSlice;
}

void PolitePriority::setTimeSlice( int timeSlice ) {
	this->timeSlice = timeSlice;
}

/*
 * @Override verbose function
 */
void PolitePriority::printVerbose(string message)
{

	if (verbose == 1)
	{
		cout << "\n[polite-priority.cpp] " << message;
	}
}