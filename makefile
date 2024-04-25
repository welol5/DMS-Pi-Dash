CC=g++
CFLAGS=
LDFLAGS=
SOURCES=Main.cpp PiDash.cpp PiDash.h
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=DMSPiDash
GTKLIB=gtkmm-4.0

gauge.o: Gauge.h Gauge.cpp
	$(CC) $(CFLAGS) -c Gauge.cpp -o target/gauge.o $(shell pkg-config $(GTKLIB) --cflags --libs)

gaugecluster.o: GaugeCluster.h GaugeCluster.cpp gauge.o
	$(CC) $(CFLAGS) -c GaugeCluster.cpp -o target/gaugecluster.o $(shell pkg-config $(GTKLIB) --cflags --libs)

pidash.o: PiDash.h PiDash.cpp gaugecluster.o
	$(CC) $(CFLAGS) -c PiDash.cpp -o target/pidash.o $(shell pkg-config $(GTKLIB) --cflags --libs)

main: Main.cpp pidash.o gaugecluster.o gauge.o
	$(CC) $(CFLAGS) Main.cpp target/pidash.o target/gaugecluster.o target/gauge.o -o main $(shell pkg-config $(GTKLIB) --cflags --libs)

clean:
	rm *.o
	rm target/*.o