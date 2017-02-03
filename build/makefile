CC = g++ -std=c++0x

INC = -I/usr/local/include
LIBS = -L/usr/local/lib -lm

# Make rules

OBJECTS_general = utils.o dateutils.o csv.o transaction_file.o time_series.o
OBJECTMAIN = main.o 
OBJECTMAP = stl.o 

.PHONY: all
all: main main_map

main: $(OBJECTS_general) $(OBJECTMAIN)
	$(CC) $(OBJECTS_general) $(OBJECTMAIN) $(LIBS) -o ../$@

main_map: $(OBJECTMAP)
	$(CC) $(OBJECTMAP) $(LIBS) -o ../$@

clean:
	-rm -rf $(OBJECTS_general) $(OBJECTMAIN) $(OBJECTMAP) ../main ../main_map

%.o: ../src/%.cpp
	$(CC) -c $(INC) $< -o $@
