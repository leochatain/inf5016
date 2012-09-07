COMPILER=G++

C = cpp
OUTPUT_PATH = out/
SOURCE_PATH = src/
BIN = $(OUTPUT_PATH)ex1

OBJS := $(patsubst %.$(C),%.$(OBJ),$(wildcard $(SOURCE_PATH)*.$(C)))

%.$(OBJ):%.$(C)
	@echo Compiling $(basename $<)...
	$(CCMD) -c $(CPPFLAGS) $(CXXFLAGS) $< $(OBJFLAG)$@

all: $(OBJS)
	@echo Linking...
	$(CCMD) $(LDFLAGS) $^ $(LIBS) $(EXEFLAG) $(BIN)

clean:
	rm -rf $(SOURCE_PATH)*.$(OBJ) $(BIN)
