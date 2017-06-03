#ifndef _ENDTHREADS_H_
#define _ENDTHREADS_H_

#include <pthread.h>
#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <unistd.h>


#include "writer.h"
#include "reader.h"
#include "consoleOutput.h"
#include "initThreads.h"
#include "endThreads.h"
#include "waitForEntryReader.h"
#include "waitForEntryWriter.h"
#include "inReadingRoom.h"
#include "reader.h"

#define test_errno(msg) do{if (errno) {perror(msg); exit(EXIT_FAILURE);}} while(0)

extern int readersQueque,writersQueque,inReaders,inWriters;

extern pthread_mutex_t mutexReadersRoom,mutexReaders,mutexWriters;

extern pthread_cond_t turn;

void endThreads(int readersCounter,int writersCounter);

#endif // _ENDTHREADS_H
