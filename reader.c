#include "reader.h"

void *reader()

{

while ( 1 )
  {
	waitForEntryReader();
	readersQueque++;
	consoleOutput();

		pthread_mutex_lock(&mutexWriters);
		pthread_mutex_unlock(&mutexWriters);

	pthread_mutex_lock(&mutexReaders);
	if (inReaders==0)
	{
	 pthread_mutex_lock(&mutexReadersRoom);
	}
	
	readersQueque--;
	inReaders++;
	consoleOutput();

	pthread_mutex_unlock(&mutexReaders);
	inReadingRoom();

	pthread_mutex_lock(&mutexReaders);

	inReaders--;
	consoleOutput();

	if (inReaders==0)
	{
	 pthread_mutex_unlock(&mutexReadersRoom);
	}

	pthread_mutex_unlock(&mutexReaders);

  }
}

