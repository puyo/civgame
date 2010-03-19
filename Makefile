CC=g++
LD=g++
CXXFLAGS=`allegro-config --cppflags` -m32 -g
LDFLAGS=`allegro-config --libs` -m32
OBJS=civgame.o  map.o  terrain.o  tile.o  widget.o  window.o
PROG=civgame

$(PROG): $(OBJS)

clean:
	$(RM) $(OBJS) $(PROG)

