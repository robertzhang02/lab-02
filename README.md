# Lab 2
[Fork](https://docs.github.com/en/get-started/quickstart/fork-a-repo) this repo and clone it to your machine to get started!

## Team Members
- Robert Zhang
- Jiansong Li

## Lab Question Answers

Answer for Question 1: 

...





Answers for the question in tcp_server.c:
1. What is argc and *argv[]?
    argc is the number of arguments on the command line (including the program name itself)
    argv is an array of C-style strings (character arrays, with a null character at the end of each string)

2. What is a UNIX file descriptor and file descriptor table?
      A file descriptor in Unix-like operating systems is an integer value that is used to represent an open file, socket, pipe, or other input/output resource.
      A file desciptot table is data structure used by the Unix-like operating systems to manage open files, sockets, pipes, and other input/output resources.
      It is table for openfiles for each process.
      
3. What is a struct? What's the structure of sockaddr_in?
      A struct is composite data type that groups together variables of different data types under a single name
      The structure of sockaddr_in is addresses for the Internet address family. 
       It includes:sa_family_t     sin_family   AF_INET. 
       in_port_t       sin_port     Port number. 
       struct in_addr  sin_addr     IP address.
       
4. What are the input parameters and return value of socket()
      The input parameters are AF_INET and SOCK_STREAM
      The return value of socket is sockfd
      
5. What are the input parameters of bind() and listen()?
     The input parameters of bind() are sockfd,(struct sockaddr *) &serv_addr,and sizeof(serv_addr)) < 0)
     The input parameters of listen() are sockfd and a integer value.

6.  Why use while(1)? Based on the code below, what problems might occur if there are multiple simultaneous connections to handle?
      The usage of while(1) is to runs continuously until it is explicitly broken out of or the program terminates.
      In this context, the program will work continuously until it find problems during the process of multipl simultaneous connections
      The problems of reading from socket and writing to socket might occur.

7. Research how the command fork() works. How can it be applied here to better handle multiple connections?
       The command fork() works in a way that creates a new process by duplicating the calling process. The newly created process is called the child process, and the original process is referred to as the parent process.
       Since it can duplicates the entire process, including its memory space, open file descriptors, and other system resources, the mutlple connections
       may run more smoothly.  The mutiple processe can run independently, each with its own memory space and system resources if using for().

8. Final question:
    This program makes several system calls such as 'bind', and 'listen.' What exactly is a system call?
    It is the programmatic way in which a computer program requests a service from the operating system on which it is executed.
           
