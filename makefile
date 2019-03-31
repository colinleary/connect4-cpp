CXX=g++
RM=rm -f
CPPFLAGS=-g -Wall

SRCS=connect4.cpp
OBJS=$(subst .cpp,.o,$(SRCS))

all: connect4

connect4: $(OBJS)
	$(CXX) $(LDFLAGS) -o connect4 $(OBJS) $(LDLIBS)

depend: .depend

.depend: $(SRCS)
	$(RM) ./.depend
	$(CXX) $(CPPFLAGS) -MM $^>>./.depend;

clean:
	$(RM) $(OBJS)

distclean: clean
	$(RM) *~ .depend

include .depend
