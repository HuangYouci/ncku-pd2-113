# ===============================================
# Makefile for NCKU PD2 Simple Online Judge System
# ===============================================

# Compiler
CXX = g++

# Compiler flags
# -Wall: Enable all standard warning messages
# -Wextra: Enable extra warning messages
# -std=c++11: Use C++11 standard (as seen in your code)
CXXFLAGS = -Wall -Wextra -std=c++11

# Linker flags (optional, for libraries if needed later)
LDFLAGS =

# Output executable name
TARGET = judge_system

# Source directory
SRCDIR = ./src

# Build directory for object files (keeps source directory clean)
OBJDIR = build

# Include paths
INC = -I$(SRCDIR)

# Find all source files in the source directory
SOURCES = $(wildcard $(SRCDIR)/*.cpp)

# Generate object file paths based on source files
# e.g., HW5/src/main.cpp -> build/main.o
OBJECTS = $(patsubst $(SRCDIR)/%.cpp, $(OBJDIR)/%.o, $(SOURCES))

# Phony targets: these are not actual files, but commands
.PHONY: all clean run

# Default target: builds the executable
all: $(TARGET)

# Rule to build the executable
# It depends on all object files.
# $@: target name (judge_system)
# $^: all prerequisites (all .o files)
$(TARGET): $(OBJECTS)
	@echo "Linking $(TARGET)..."
	$(CXX) $(CXXFLAGS) $(LDFLAGS) $(OBJECTS) -o $@

# Pattern rule to compile each .cpp file into a .o file
# $(OBJDIR)/%.o: target object file path (e.g., build/main.o)
# $(SRCDIR)/%.cpp: prerequisite source file path (e.g., HW5/src/main.cpp)
# $@: target name (e.g., build/main.o)
# $<: first prerequisite (e.g., HW5/src/main.cpp)
$(OBJDIR)/%.o: $(SRCDIR)/%.cpp
	@mkdir -p $(OBJDIR) # Create the object directory if it doesn't exist
	@echo "Compiling $< to $@..."
	$(CXX) $(CXXFLAGS) $(INC) -c $< -o $@

# Clean target: removes generated files
clean:
	@echo "Cleaning project..."
	@rm -f $(TARGET) # Remove the executable
	@rm -rf $(OBJDIR) # Remove the object file directory and its contents

# Run target: builds and then executes the program
run: $(TARGET)
	@echo "Running $(TARGET)..."
	./$(TARGET)