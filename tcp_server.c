/* A simple server in the internet domain using TCP
 * Answer the questions below in your writeup
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h> 
#include <sys/socket.h>
#include <netinet/in.h>

void error(const char *msg)
{
    perror(msg);
    exit(1);
}

int main(int argc, char *argv[])
{
    /* 1. What is argc and *argv[]?
     arge is a argument varaible of function main with a integer type
     argv is also argument varaible of function main with with a list pointer type
     */
    int sockfd, newsockfd, portno;
    /* 2. What is a UNIX file descriptor and file descriptor table?
      A file descriptor in Unix-like operating systems is an integer value that is used to represent an open file, socket, pipe, or other input/output resource.
      A file desciptot table is data structure used by the Unix-like operating systems to manage open files, sockets, pipes, and other input/output resources.
      It is table for openfiles for each process.
     */
    socklen_t clilen;

    struct sockaddr_in serv_addr, cli_addr;
    /* 3. What is a struct? What's the structure of sockaddr_in?
           A struct is composite data type that groups together variables of different data types under a single name
        
     */
    
    int n;
    if (argc < 2) {
        fprintf(stderr,"ERROR, no port provided\n");
        exit(1);
    }
    
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    /* 4. What are the input parameters and return value of socket()
        The input parameters are AF_INET and SOCK_STREAM
        The return value of socket is sockfd
     */
    
    if (sockfd < 0) 
       error("ERROR opening socket");
    bzero((char *) &serv_addr, sizeof(serv_addr));
    portno = atoi(argv[1]);
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(portno);
    
    if (bind(sockfd, (struct sockaddr *) &serv_addr,
             sizeof(serv_addr)) < 0) 
             error("ERROR on binding");
    /* 5. What are the input parameters of bind() and listen()?
     The input parameters of bind() are sockfd,(struct sockaddr *) &serv_addr,and sizeof(serv_addr)) < 0)
     The input parameters of listen() are sockfd and a integer value.
     */
    listen(sockfd,5);
    clilen = sizeof(cli_addr);
    
    while(1) {
        /* 6.  Why use while(1)? Based on the code below, what problems might occur if there are multiple simultaneous connections to handle?
        The usage of while(1) is to runs continuously until it is explicitly broken out of or the program terminates.
        In this context, the program will work continuously until it find problems during the process of multipl simultaneous connections
        The problems of reading from socket and writing to socket might occur.
        */
        
	char buffer[256];
        newsockfd = accept(sockfd, 
                    (struct sockaddr *) &cli_addr, 
                    &clilen);
	/* 7. Research how the command fork() works. How can it be applied here to better handle multiple connections?
         The command fork() works in a way that creates a new process by duplicating the calling process. The newly created process is called the child process, and the original process is referred to as the parent process.
         Since it can duplicates the entire process, including its memory space, open file descriptors, and other system resources, the mutlple connections
         may run more smoothly.  The mutiple processe can run independently, each with its own memory space and system resources if using for().
         */
        
	if (newsockfd < 0) 
             error("ERROR on accept");
	bzero(buffer,256);
        
	n = read(newsockfd,buffer,255);
        if (n < 0) 
            error("ERROR reading from socket");
        printf("Here is the message: %s\n",buffer);
        n = write(newsockfd,"I got your message",18);
        if (n < 0) 
            error("ERROR writing to socket");
        close(newsockfd);
    }
    close(sockfd);
    return 0; 
}
  
/* This program makes several system calls such as 'bind', and 'listen.' What exactly is a system call?
  the programmatic way in which a computer program requests a service from the operating system on which it is executed
 */
