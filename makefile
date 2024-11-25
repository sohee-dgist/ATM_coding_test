# Include directories
INCLUDE_DIRS = -I.

# Compiler and flags
CXX = g++
CXXFLAGS = -Wall -g $(INCLUDE_DIRS)

# Directories
SRCDIRS = atm bank card run
OBJDIR = obj
BINDIR = bin

# Collect all .cc source files
SRCS = $(wildcard $(addsuffix /*.cc, $(SRCDIRS)))
OBJS = $(patsubst %.cc, $(OBJDIR)/%.o, $(SRCS))

# Target executable
TARGET = $(BINDIR)/atm_system

# Default rule
all: $(TARGET)

# Link object files
$(TARGET): $(OBJS)
	mkdir -p $(BINDIR)
	$(CXX) $(CXXFLAGS) -o $@ $(OBJS)

# Compile .cc files into .o files
$(OBJDIR)/%.o: %.cc
	mkdir -p $(OBJDIR)/$(dir $*)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean build artifacts
clean:
	rm -rf $(OBJDIR) $(BINDIR)

