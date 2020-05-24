CXX = g++
INCLUDING = -I./MQTT-SenseHAT-Utils/_libSenseHAT
CXXFLAGS = -std=c++14 -g -Wall -Wextra -Weffc++ -Wpedantic \
           -Wcast-align -Wcast-qual -Wctor-dtor-privacy \
           -Wdisabled-optimization -Wformat=2 -Winit-self -Wlogical-op \
           -Wmissing-include-dirs -Wnoexcept -Wold-style-cast \
           -Woverloaded-virtual -Wredundant-decls -Wshadow -Wsign-promo \
           -Wstrict-null-sentinel -Wstrict-overflow=5 -Wundef -Wno-unused \
           -Wno-variadic-macros -Wno-parentheses -fdiagnostics-show-option \
           -D_GLIBCXX_USE_NANOSLEEP \
           -Os $(INCLUDING)
LDFLAGS = -L/usr/local/lib -lm -pthread

EXECUTABLE = sensorDemo
SOURCES := ${wildcard *.cpp} \
           ${wildcard ../../MQTT-SenseHAT-Utils/_libSenseHAT/*.cpp} \
           ${wildcard ../../MQTT-SenseHAT-Utils/_libSenseHAT/*.c}
HEADERS := ${wildcard *.h} \
		   ${wildcard ../../MQTT-SenseHAT-Utils/_libSenseHAT/*.h}
OBJECTS := ${SOURCES:.cpp=.o}
OBJECTS := ${OBJECTS:.c=.o}

.PHONY: all
all: ${EXECUTABLE}

$(EXECUTABLE): $(OBJECTS) buildnumber.num
	$(CXX) $(CXXFLAGS) $(OBJECTS) $(LDFLAGS) -o $@ -lRTIMULib
	@echo
	@echo "-- Build: " $$(cat buildnumber.num)

# Create dependency file compiler option -MM
depend: $(SOURCES)
	$(CXX) $(CXXFLAGS) -MM  $^ > $@

-include depend

# Buildnumber in text file
buildnumber.num: $(OBJECTS)
	@echo
	@echo "-- Sources: " $(SOURCES)
	@echo
	@if ! test -f buildnumber.num; then echo 0 > buildnumber.num; fi
	@echo $$(($$(cat buildnumber.num)+1)) > buildnumber.num

# Create a clean environment
.PHONY: clean
clean:
	$(RM) $(EXECUTABLE) $(OBJECTS)

# Clean up dependency file
.PHONY: clean-depend
clean-depend: clean
	$(RM) depend

