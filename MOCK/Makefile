CXX = g++
CXXFLAGS = -Wall -g

MODEL_DIR = Model
VIEW_DIR = View
CONTROLLER_DIR = Controller

MODEL_FILES = $(wildcard $(MODEL_DIR)/*.cpp)
VIEW_FILES = $(wildcard $(VIEW_DIR)/*.cpp)
CONTROLLER_FILES = $(wildcard $(CONTROLLER_DIR)/*.cpp)
MAIN_FILE = main.cpp

OUTPUT = output

OBJ_FILES = $(MODEL_FILES:.cpp=.o) $(VIEW_FILES:.cpp=.o) $(CONTROLLER_FILES:.cpp=.o) $(MAIN_FILE:.cpp=.o)

INC_FILES = $(MODEL_FILES:.cpp=.h) $(VIEW_FILES:.cpp=.h) $(CONTROLLER_FILES:.cpp=.h)

$(OUTPUT): $(OBJ_FILES)
	$(CXX) $(CXXFLAGS) -o $@ $^

%.o: %.cpp $(INC_FILES)
	$(CXX) $(CXXFLAGS) -o $@ -c $<

clean:
	del $(MODEL_DIR)\*.o $(VIEW_DIR)\*.o $(CONTROLLER_DIR)\*.o main.o $(OUTPUT).exe