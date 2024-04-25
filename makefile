CC=g++
CFLAGS=
LDFLAGS=
SOURCES=Main.cpp PiDash.cpp PiDash.h
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=DMSPiDash
GTKLIB=gtkmm-4.0

target/gauge.o: Gauge.h Gauge.cpp
	$(CC) $(CFLAGS) -c Gauge.cpp -o target/gauge.o $(shell pkg-config $(GTKLIB) --cflags --libs)

target/gaugecluster.o: GaugeCluster.h GaugeCluster.cpp target/gauge.o
	$(CC) $(CFLAGS) -c GaugeCluster.cpp -o target/gaugecluster.o $(shell pkg-config $(GTKLIB) --cflags --libs)

target/pidash.o: PiDash.h PiDash.cpp target/gaugecluster.o
	$(CC) $(CFLAGS) -c PiDash.cpp -o target/pidash.o $(shell pkg-config $(GTKLIB) --cflags --libs)

main: Main.cpp target/pidash.o
	$(CC) $(CFLAGS) Main.cpp target/pidash.o target/gaugecluster.o target/gauge.o -o main $(shell pkg-config $(GTKLIB) --cflags --libs)

clean:
	rm *.o
	rm target/*.o