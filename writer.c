#include "writer.h"

void *writer()
{

while ( 1 )
  {
	waitForEntryWriter();
	writersQueque++;
	if (inWriters==0) 
	{
	 pthread_mutex_lock(&mutexWriters);
	}	
	pthread_mutex_lock(&mutexReadersRoom);

	inWriters++;
	writersQueque--;
	consoleOutput();

	inReadingRoom();
	
	inWriters--;
	consoleOutput();
	
	if (inWriters==0) 
	{
	 pthread_mutex_unlock(&mutexWriters);
	}

	pthread_mutex_unlock(&mutexReadersRoom);


  }
}
