/* I pledge my honor that I have abided by the Stevens Honor System
 * Daniel Salerno
 */

#ifndef _MINITALK_H_
#define _MINITALK_H_

#include "my.h"
#include <unistd.h>
#include <signal.h> 
#include <sys/types.h> /*pid_t*/
#include <stdio.h> /* perror */

/* global vars */
#ifdef SERVER
	int gl_doneflag;
	pid_t gl_clientpid;
#else
	int gl_ack;
#endif

#ifdef SERVER
	void get_char(int);
	void get_client_pid(int);
	void quit();
#else
	void send_char(char, pid_t);
	void send_pid(pid_t, pid_t);
	void ack();
	void sig_alarm();
        void client_quit();
#endif


#endif
