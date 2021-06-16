TARGET = libGLEStrace.so

rwildcard=$(foreach d,$(wildcard $(1:=/*)),$(call rwildcard,$d,$2) $(filter $(subst *,%,$2),$d))

SRCS = 
SRCS += $(call rwildcard,src,*.c)

INCLUDES  =
INCLUDES += -I.
INCLUDES += -I./src

CFLAGS    =
CFLAGS   += -DUSE_GLES_32
CFLAGS   += -Wall -O2 -fPIC

LDFLAGS   =


OBJS += $(patsubst %.cc,%.o,$(patsubst %.cpp,%.o,$(patsubst %.c,%.o,$(SRCS))))


all: $(TARGET)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -g -c $< -o $@

%.o: %.cpp
	$(CXX) $(CFLAGS) $(CXXFLAGS) $(INCLUDES) -g -c $< -o $@

%.o: %.cc
	$(CXX) $(CFLAGS) $(CXXFLAGS) $(INCLUDES) -g -c $< -o $@

$(TARGET): $(OBJS)
	$(CXX) -shared -fPIC -o $@ $(OBJS)

clean:
	for i in $(OBJS); do (if test -e "$$i"; then ( rm $$i ); fi ); done
	rm -f $(TARGET) $(LIB)

