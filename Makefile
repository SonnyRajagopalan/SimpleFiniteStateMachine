all: all1 all2

all1: main1.cpp Session.h Session.cpp \
	SFSMBaseState.h SFSMBaseState.cpp SFSMDormantState.h SFSMDormantState.cpp \
	SFSMWaitForAuthState.h SFSMWaitForAuthState.cpp SFSMConnectedState.h SFSMConnectedState.cpp \
	SFSMClosedState.h SFSMClosedState.cpp Mutex.h

	g++ -Wall -g -o sfsm1 main1.cpp Session.cpp SFSMBaseState.cpp \
	SFSMDormantState.cpp SFSMWaitForAuthState.cpp \
	SFSMConnectedState.cpp SFSMClosedState.cpp

all2: main1.cpp Session.h Session.cpp \
	SFSMBaseState.h SFSMBaseState.cpp SFSMDormantState.h SFSMDormantState.cpp \
	SFSMWaitForAuthState.h SFSMWaitForAuthState.cpp SFSMConnectedState.h SFSMConnectedState.cpp \
	SFSMClosedState.h SFSMClosedState.cpp Mutex.h

	g++ -Wall -g -o sfsm2 main2.cpp Session.cpp SFSMBaseState.cpp \
	SFSMDormantState.cpp SFSMWaitForAuthState.cpp \
	SFSMConnectedState.cpp SFSMClosedState.cpp

tar: main1.cpp main2.cpp Session.h Session.cpp \
	SFSMBaseState.h SFSMBaseState.cpp SFSMDormantState.h SFSMDormantState.cpp \
	SFSMWaitForAuthState.h SFSMWaitForAuthState.cpp SFSMConnectedState.h SFSMConnectedState.cpp \
	SFSMClosedState.h SFSMClosedState.cpp Mutex.h

	tar -cvzf tareqsQuestion.tgz *.h *.cpp Makefile

clean:
	rm -rf sfsm1 sfsm2
