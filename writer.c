#include "writer.h"

void *writer()
{

while ( 1 )
  {
	waitForEntryWriter();
	writersQueque++;
	consoleOutput();

	pthread_mutex_lock(&mutexMutex);

		 pthread_mutex_trylock(&mutexWriters);

	pthread_mutex_lock(&mutexReadersRoom);

	inWriters++;
	writersQueque--;
	consoleOutput();

	pthread_mutex_unlock(&mutexMutex);

	inReadingRoom();

	inWriters--;
	consoleOutput();

	if (writersQueque==0) 
	{
		pthread_mutex_unlock(&mutexWriters);
	}

	pthread_mutex_unlock(&mutexReadersRoom);


  }
}
