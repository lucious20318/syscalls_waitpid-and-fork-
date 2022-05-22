all: ques1_fork.o q_thread
	
	gcc -o ques1_fork ques1_fork.o
	./ques1_fork

ques1_fork.o: ques1_fork.s
	gcc -c ques1_fork.s -o ques1_fork.o

ques1_fork.s: ques1_fork.c
	gcc -S ques1_fork.c
	
q_thread: ques1_thread.c
	gcc ques1_thread.c -lpthread -o q_thread
	./q_thread
