To check shm shared memory:
g++ -fpermissive -w -Wall -o shmwrite shmwrite.cpp
g++ -fpermissive -w -Wall -o shmread shmread.cpp

And:
//Write to shared memory shm
./shmwrite string_want_write
//Read shared memory shm
./shmread