# DistributedOS

## Environments:

All tests are on Ubuntu 16.04 LTS, g++ (Ubuntu 5.4.0-6ubuntu1~16.04.12) 5.4.0 20160609.


# Project 1: A Centralized Multi-User Concurrent Bank Account Manager (Multithreading, Mutex)

The system has two important components:
1. **Bank Server**: 
The server program that services online requests for account manipulations and maintains all customer records correctly.
2. **Clients**: 
Customers are clients of the bank server and use its services to update bank accounts. The operations that can be performed on an account are: withdrawl of an amount from an account and deposit of an amount into an account. Additionally, the bank server can have it's own service that periodically deposits an interest amount to each account based on some fixed rate.

System architecture:

![](./proj1_centralized_multiuser_bank/doc/project1.jpg)

State diagram for server and client model:

![](./proj1_centralized_multiuser_bank/doc/Socket_server.png)


More assignment details [PDF here](./proj1_centralized_multiuser_bank/doc/Project_1_Fall_2021.pdf), [HTML here](http://lass.cs.umass.edu/~shenoy/courses/spring05/labs/project1.html).



## Project 1 Implementation:

Check out [this directory](proj1_centralized_multiuser_bank/src).

Phase 1 (Version 1): Socket programming (without multithreads)

Phase 2 (Version 2): Add multithreads on Phase 1.

Phase 3 (Version 3): Add mutex (lock) on Phase 2. (Add account helper functions first.) 


### References:

Socket:

1. [Socket programming example 1](https://www.geeksforgeeks.org/socket-programming-cc/?ref=lbp)
2. [Socket programming example 2](https://stackoverflow.com/a/69309213/9593219)

Multithread:

3. [pthread_join need to be outside of pthread_create loop](https://stackoverflow.com/questions/38153680/integrating-pthread-create-and-pthread-join-in-the-same-loop)

Mutex:

4. [pthread_mutex](https://stackoverflow.com/questions/34100575/c-using-mutex-in-multithreaded-client-and-server)

C++ programming tricks:

5. [use typedef for struct](https://stackoverflow.com/questions/32577808/how-to-create-a-new-instance-of-a-struct)

6. [c++ need cast the result of malloc](https://stackoverflow.com/a/52362916/9593219)

7. [c++ static cast](https://stackoverflow.com/questions/15937309/errorpe513-a-value-of-type-void-cannot-be-assigned-to-an-entity-of-type)