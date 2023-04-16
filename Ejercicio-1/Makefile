CC = g++
CFLAGS = -Wall -O2
OBJECTS = main.o operator.o system.o DTHuesped.o classHabitacion.o DTHabitacion.o DTreserva.o classHuesped.o DTReservaIndividual.o DTREservaGrupal.o classReserva.o classReservaIndividual.o classReservaGrupal.o DTFecha.o EstadoReserva.o

all: mi_programa

mi_programa: $(OBJECTS)
	$(CC) $(CFLAGS) -o mi_programa $(OBJECTS)

main.o: main.cpp system.h operator.h  # Agregar operator.h
	$(CC) $(CFLAGS) -c main.cpp

operator.o: operator.cpp operator.h DTreserva.h DTReservaIndividual.h DTREservaGrupal.h DTFecha.h  # Agregar operator.h
	$(CC) $(CFLAGS) -c operator.cpp

system.o: system.h classHuesped.h DTReservaIndividual.h DTREservaGrupal.h classReserva.h classReservaIndividual.h classReservaGrupal.h
	$(CC) $(CFLAGS) -c system.cpp

DTHuesped.o: DTHuesped.h
	$(CC) $(CFLAGS) -c DTHuesped.cpp

classHabitacion.o: classHabitacion.h
	$(CC) $(CFLAGS) -c classHabitacion.cpp

DTHabitacion.o: DTHabitacion.h
	$(CC) $(CFLAGS) -c DTHabitacion.cpp

DTreserva.o: DTreserva.h
	$(CC) $(CFLAGS) -c DTreserva.cpp

classHuesped.o: classHuesped.h
	$(CC) $(CFLAGS) -c classHuesped.cpp

DTReservaIndividual.o: DTReservaIndividual.h DTFecha.h EstadoReserva.h DTreserva.h
	$(CC) $(CFLAGS) -c DTReservaIndividual.cpp

DTReservaGrupal.o: DTREservaGrupal.h DTHuesped.h DTFecha.h EstadoReserva.h DTreserva.h
	$(CC) $(CFLAGS) -c DTReservaGrupal.cpp

classReserva.o: classReserva.h DTFecha.h classHabitacion.h classHuesped.h EstadoReserva.h
	$(CC) $(CFLAGS) -c classReserva.cpp

classReservaIndividual.o: classReservaIndividual.h classReserva.h DTHuesped.h DTFecha.h
	$(CC) $(CFLAGS) -c classReservaIndividual.cpp

classReservaGrupal.o: classReservaGrupal.h classReserva.h DTHuesped.h DTFecha.h
	$(CC) $(CFLAGS) -c classReservaGrupal.cpp

DTFecha.o: DTFecha.h
	$(CC) $(CFLAGS) -c DTFecha.cpp

EstadoReserva.o: EstadoReserva.h
	$(CC) $(CFLAGS) -c EstadoReserva.cpp

clean:
	rm -f mi_programa $(OBJECTS)