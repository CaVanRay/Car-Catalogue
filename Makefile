# Compiler and flags
CXX = g++
CXXFLAGS = -Wall -Wextra -g -std=c++17
# Include directory
INCLUDES = -Iinclude

# Target executable name
TARGET = car_catalogue

# Find all cpp files in src
SRCS = $(wildcard src/*.cpp)
# Generate object file names (e.g., src/main.cpp -> src/main.o)
OBJS = $(SRCS:.cpp=.o)

# Default rule
all: $(TARGET)

# Link the executable
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(TARGET)

# Compile rule (with include path)
%.o: %.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c $< -o $@

# Clean up
clean:
	rm -f $(OBJS) $(TARGET)

.PHONY: all clean