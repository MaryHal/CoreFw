# GNU Make project makefile autogenerated by Premake
ifndef config
  config=debug
endif

ifndef verbose
  SILENT = @
endif

ifndef CC
  CC = gcc
endif

ifndef CXX
  CXX = g++
endif

ifndef AR
  AR = ar
endif

ifeq ($(config),debug)
  OBJDIR     = obj/Debug/Core_Library
  TARGETDIR  = lib
  TARGET     = $(TARGETDIR)/libCoreFW64.a
  DEFINES   += -DDEBUG
  INCLUDES  += 
  CPPFLAGS  += -MMD -MP $(DEFINES) $(INCLUDES)
  CFLAGS    += $(CPPFLAGS) $(ARCH) -g -Wall
  CXXFLAGS  += $(CFLAGS) 
  LDFLAGS   += -Llib
  LIBS      += -lopenal -lsndfile -lGLEW -lGL -lX11 -lXrandr -lpthread -lm -lglfw
  RESFLAGS  += $(DEFINES) $(INCLUDES) 
  LDDEPS    += 
  LINKCMD    = $(AR) -rcs $(TARGET) $(OBJECTS)
  define PREBUILDCMDS
  endef
  define PRELINKCMDS
  endef
  define POSTBUILDCMDS
  endef
endif

ifeq ($(config),release)
  OBJDIR     = obj/Release/Core_Library
  TARGETDIR  = lib
  TARGET     = $(TARGETDIR)/libCoreFW64.a
  DEFINES   += 
  INCLUDES  += 
  CPPFLAGS  += -MMD -MP $(DEFINES) $(INCLUDES)
  CFLAGS    += $(CPPFLAGS) $(ARCH) -O2 -Wall
  CXXFLAGS  += $(CFLAGS) 
  LDFLAGS   += -s -Llib
  LIBS      += -lopenal -lsndfile -lGLEW -lGL -lX11 -lXrandr -lpthread -lm -lglfw
  RESFLAGS  += $(DEFINES) $(INCLUDES) 
  LDDEPS    += 
  LINKCMD    = $(AR) -rcs $(TARGET) $(OBJECTS)
  define PREBUILDCMDS
  endef
  define PRELINKCMDS
  endef
  define POSTBUILDCMDS
  endef
endif

ifeq ($(config),debug32)
  OBJDIR     = obj/x32/Debug/Core_Library
  TARGETDIR  = lib
  TARGET     = $(TARGETDIR)/libCoreFW32.a
  DEFINES   += -DDEBUG
  INCLUDES  += 
  CPPFLAGS  += -MMD -MP $(DEFINES) $(INCLUDES)
  CFLAGS    += $(CPPFLAGS) $(ARCH) -g -Wall -m32
  CXXFLAGS  += $(CFLAGS) 
  LDFLAGS   += -m32 -L/usr/lib32 -Llib
  LIBS      += -lopenal -lsndfile -lGLEW -lGL -lX11 -lXrandr -lpthread -lm -lglfw
  RESFLAGS  += $(DEFINES) $(INCLUDES) 
  LDDEPS    += 
  LINKCMD    = $(AR) -rcs $(TARGET) $(OBJECTS)
  define PREBUILDCMDS
  endef
  define PRELINKCMDS
  endef
  define POSTBUILDCMDS
  endef
endif

ifeq ($(config),release32)
  OBJDIR     = obj/x32/Release/Core_Library
  TARGETDIR  = lib
  TARGET     = $(TARGETDIR)/libCoreFW32.a
  DEFINES   += 
  INCLUDES  += 
  CPPFLAGS  += -MMD -MP $(DEFINES) $(INCLUDES)
  CFLAGS    += $(CPPFLAGS) $(ARCH) -O2 -Wall -m32
  CXXFLAGS  += $(CFLAGS) 
  LDFLAGS   += -s -m32 -L/usr/lib32 -Llib
  LIBS      += -lopenal -lsndfile -lGLEW -lGL -lX11 -lXrandr -lpthread -lm -lglfw
  RESFLAGS  += $(DEFINES) $(INCLUDES) 
  LDDEPS    += 
  LINKCMD    = $(AR) -rcs $(TARGET) $(OBJECTS)
  define PREBUILDCMDS
  endef
  define PRELINKCMDS
  endef
  define POSTBUILDCMDS
  endef
endif

ifeq ($(config),debug64)
  OBJDIR     = obj/x64/Debug/Core_Library
  TARGETDIR  = lib
  TARGET     = $(TARGETDIR)/libCoreFW64.a
  DEFINES   += -DDEBUG
  INCLUDES  += 
  CPPFLAGS  += -MMD -MP $(DEFINES) $(INCLUDES)
  CFLAGS    += $(CPPFLAGS) $(ARCH) -g -Wall -m64
  CXXFLAGS  += $(CFLAGS) 
  LDFLAGS   += -m64 -L/usr/lib64 -Llib
  LIBS      += -lopenal -lsndfile -lGLEW -lGL -lX11 -lXrandr -lpthread -lm -lglfw
  RESFLAGS  += $(DEFINES) $(INCLUDES) 
  LDDEPS    += 
  LINKCMD    = $(AR) -rcs $(TARGET) $(OBJECTS)
  define PREBUILDCMDS
  endef
  define PRELINKCMDS
  endef
  define POSTBUILDCMDS
  endef
endif

ifeq ($(config),release64)
  OBJDIR     = obj/x64/Release/Core_Library
  TARGETDIR  = lib
  TARGET     = $(TARGETDIR)/libCoreFW64.a
  DEFINES   += 
  INCLUDES  += 
  CPPFLAGS  += -MMD -MP $(DEFINES) $(INCLUDES)
  CFLAGS    += $(CPPFLAGS) $(ARCH) -O2 -Wall -m64
  CXXFLAGS  += $(CFLAGS) 
  LDFLAGS   += -s -m64 -L/usr/lib64 -Llib
  LIBS      += -lopenal -lsndfile -lGLEW -lGL -lX11 -lXrandr -lpthread -lm -lglfw
  RESFLAGS  += $(DEFINES) $(INCLUDES) 
  LDDEPS    += 
  LINKCMD    = $(AR) -rcs $(TARGET) $(OBJECTS)
  define PREBUILDCMDS
  endef
  define PRELINKCMDS
  endef
  define POSTBUILDCMDS
  endef
endif

OBJECTS := \
	$(OBJDIR)/Core.o \
	$(OBJDIR)/CoreRegistry.o \
	$(OBJDIR)/CoreState.o \
	$(OBJDIR)/Timer.o \
	$(OBJDIR)/BinaryHeap.o \
	$(OBJDIR)/FpsCounter.o \
	$(OBJDIR)/FileLoader.o \
	$(OBJDIR)/Ini.o \
	$(OBJDIR)/StringUtils.o \
	$(OBJDIR)/SoundLoader.o \
	$(OBJDIR)/Music.o \
	$(OBJDIR)/Sound.o \
	$(OBJDIR)/Sample.o \
	$(OBJDIR)/SoundBuffer.o \
	$(OBJDIR)/Listener.o \
	$(OBJDIR)/Random.o \
	$(OBJDIR)/Vector2.o \
	$(OBJDIR)/Math.o \
	$(OBJDIR)/Log.o \
	$(OBJDIR)/Input.o \
	$(OBJDIR)/Debug.o \
	$(OBJDIR)/ResourceCache.o \
	$(OBJDIR)/ResourceManager.o \
	$(OBJDIR)/Buffer.o \
	$(OBJDIR)/Section.o \
	$(OBJDIR)/Text.o \
	$(OBJDIR)/Drawable.o \
	$(OBJDIR)/Color.o \
	$(OBJDIR)/VertexBuffer.o \
	$(OBJDIR)/ImageLoader.o \
	$(OBJDIR)/FontLoader.o \
	$(OBJDIR)/Font.o \
	$(OBJDIR)/Texture.o \
	$(OBJDIR)/Renderer.o \
	$(OBJDIR)/stb_image.o \

RESOURCES := \

SHELLTYPE := msdos
ifeq (,$(ComSpec)$(COMSPEC))
  SHELLTYPE := posix
endif
ifeq (/bin,$(findstring /bin,$(SHELL)))
  SHELLTYPE := posix
endif

.PHONY: clean prebuild prelink

all: $(TARGETDIR) $(OBJDIR) prebuild prelink $(TARGET)
	@:

$(TARGET): $(GCH) $(OBJECTS) $(LDDEPS) $(RESOURCES)
	@echo Linking Core_Library
	$(SILENT) $(LINKCMD)
	$(POSTBUILDCMDS)

$(TARGETDIR):
	@echo Creating $(TARGETDIR)
ifeq (posix,$(SHELLTYPE))
	$(SILENT) mkdir -p $(TARGETDIR)
else
	$(SILENT) mkdir $(subst /,\\,$(TARGETDIR))
endif

$(OBJDIR):
	@echo Creating $(OBJDIR)
ifeq (posix,$(SHELLTYPE))
	$(SILENT) mkdir -p $(OBJDIR)
else
	$(SILENT) mkdir $(subst /,\\,$(OBJDIR))
endif

clean:
	@echo Cleaning Core_Library
ifeq (posix,$(SHELLTYPE))
	$(SILENT) rm -f  $(TARGET)
	$(SILENT) rm -rf $(OBJDIR)
else
	$(SILENT) if exist $(subst /,\\,$(TARGET)) del $(subst /,\\,$(TARGET))
	$(SILENT) if exist $(subst /,\\,$(OBJDIR)) rmdir /s /q $(subst /,\\,$(OBJDIR))
endif

prebuild:
	$(PREBUILDCMDS)

prelink:
	$(PRELINKCMDS)

ifneq (,$(PCH))
$(GCH): $(PCH)
	@echo $(notdir $<)
	-$(SILENT) cp $< $(OBJDIR)
	$(SILENT) $(CXX) $(CXXFLAGS) -o "$@" -c "$<"
endif

$(OBJDIR)/Core.o: src/Core/Core.cpp
	@echo $(notdir $<)
	$(SILENT) $(CXX) $(CXXFLAGS) -o "$@" -c "$<"
$(OBJDIR)/CoreRegistry.o: src/Core/CoreRegistry.cpp
	@echo $(notdir $<)
	$(SILENT) $(CXX) $(CXXFLAGS) -o "$@" -c "$<"
$(OBJDIR)/CoreState.o: src/Core/CoreState.cpp
	@echo $(notdir $<)
	$(SILENT) $(CXX) $(CXXFLAGS) -o "$@" -c "$<"
$(OBJDIR)/Timer.o: src/Utils/Timer.cpp
	@echo $(notdir $<)
	$(SILENT) $(CXX) $(CXXFLAGS) -o "$@" -c "$<"
$(OBJDIR)/BinaryHeap.o: src/Utils/BinaryHeap.cpp
	@echo $(notdir $<)
	$(SILENT) $(CXX) $(CXXFLAGS) -o "$@" -c "$<"
$(OBJDIR)/FpsCounter.o: src/Utils/FpsCounter.cpp
	@echo $(notdir $<)
	$(SILENT) $(CXX) $(CXXFLAGS) -o "$@" -c "$<"
$(OBJDIR)/FileLoader.o: src/Utils/FileLoader.cpp
	@echo $(notdir $<)
	$(SILENT) $(CXX) $(CXXFLAGS) -o "$@" -c "$<"
$(OBJDIR)/Ini.o: src/Utils/Ini.cpp
	@echo $(notdir $<)
	$(SILENT) $(CXX) $(CXXFLAGS) -o "$@" -c "$<"
$(OBJDIR)/StringUtils.o: src/Utils/StringUtils.cpp
	@echo $(notdir $<)
	$(SILENT) $(CXX) $(CXXFLAGS) -o "$@" -c "$<"
$(OBJDIR)/SoundLoader.o: src/Audio/SoundLoader.cpp
	@echo $(notdir $<)
	$(SILENT) $(CXX) $(CXXFLAGS) -o "$@" -c "$<"
$(OBJDIR)/Music.o: src/Audio/Music.cpp
	@echo $(notdir $<)
	$(SILENT) $(CXX) $(CXXFLAGS) -o "$@" -c "$<"
$(OBJDIR)/Sound.o: src/Audio/Sound.cpp
	@echo $(notdir $<)
	$(SILENT) $(CXX) $(CXXFLAGS) -o "$@" -c "$<"
$(OBJDIR)/Sample.o: src/Audio/Sample.cpp
	@echo $(notdir $<)
	$(SILENT) $(CXX) $(CXXFLAGS) -o "$@" -c "$<"
$(OBJDIR)/SoundBuffer.o: src/Audio/SoundBuffer.cpp
	@echo $(notdir $<)
	$(SILENT) $(CXX) $(CXXFLAGS) -o "$@" -c "$<"
$(OBJDIR)/Listener.o: src/Audio/Listener.cpp
	@echo $(notdir $<)
	$(SILENT) $(CXX) $(CXXFLAGS) -o "$@" -c "$<"
$(OBJDIR)/Random.o: src/Math/Random.cpp
	@echo $(notdir $<)
	$(SILENT) $(CXX) $(CXXFLAGS) -o "$@" -c "$<"
$(OBJDIR)/Vector2.o: src/Math/Vector2.cpp
	@echo $(notdir $<)
	$(SILENT) $(CXX) $(CXXFLAGS) -o "$@" -c "$<"
$(OBJDIR)/Math.o: src/Math/Math.cpp
	@echo $(notdir $<)
	$(SILENT) $(CXX) $(CXXFLAGS) -o "$@" -c "$<"
$(OBJDIR)/Log.o: src/System/Log.cpp
	@echo $(notdir $<)
	$(SILENT) $(CXX) $(CXXFLAGS) -o "$@" -c "$<"
$(OBJDIR)/Input.o: src/System/Input.cpp
	@echo $(notdir $<)
	$(SILENT) $(CXX) $(CXXFLAGS) -o "$@" -c "$<"
$(OBJDIR)/Debug.o: src/System/Debug.cpp
	@echo $(notdir $<)
	$(SILENT) $(CXX) $(CXXFLAGS) -o "$@" -c "$<"
$(OBJDIR)/ResourceCache.o: src/System/ResourceCache.cpp
	@echo $(notdir $<)
	$(SILENT) $(CXX) $(CXXFLAGS) -o "$@" -c "$<"
$(OBJDIR)/ResourceManager.o: src/System/ResourceManager.cpp
	@echo $(notdir $<)
	$(SILENT) $(CXX) $(CXXFLAGS) -o "$@" -c "$<"
$(OBJDIR)/Buffer.o: src/Memory/Buffer.cpp
	@echo $(notdir $<)
	$(SILENT) $(CXX) $(CXXFLAGS) -o "$@" -c "$<"
$(OBJDIR)/Section.o: src/Graphics/Section.cpp
	@echo $(notdir $<)
	$(SILENT) $(CXX) $(CXXFLAGS) -o "$@" -c "$<"
$(OBJDIR)/Text.o: src/Graphics/Text.cpp
	@echo $(notdir $<)
	$(SILENT) $(CXX) $(CXXFLAGS) -o "$@" -c "$<"
$(OBJDIR)/Drawable.o: src/Graphics/Drawable.cpp
	@echo $(notdir $<)
	$(SILENT) $(CXX) $(CXXFLAGS) -o "$@" -c "$<"
$(OBJDIR)/Color.o: src/Graphics/Color.cpp
	@echo $(notdir $<)
	$(SILENT) $(CXX) $(CXXFLAGS) -o "$@" -c "$<"
$(OBJDIR)/VertexBuffer.o: src/Graphics/VertexBuffer.cpp
	@echo $(notdir $<)
	$(SILENT) $(CXX) $(CXXFLAGS) -o "$@" -c "$<"
$(OBJDIR)/ImageLoader.o: src/Graphics/ImageLoader.cpp
	@echo $(notdir $<)
	$(SILENT) $(CXX) $(CXXFLAGS) -o "$@" -c "$<"
$(OBJDIR)/FontLoader.o: src/Graphics/FontLoader.cpp
	@echo $(notdir $<)
	$(SILENT) $(CXX) $(CXXFLAGS) -o "$@" -c "$<"
$(OBJDIR)/Font.o: src/Graphics/Font.cpp
	@echo $(notdir $<)
	$(SILENT) $(CXX) $(CXXFLAGS) -o "$@" -c "$<"
$(OBJDIR)/Texture.o: src/Graphics/Texture.cpp
	@echo $(notdir $<)
	$(SILENT) $(CXX) $(CXXFLAGS) -o "$@" -c "$<"
$(OBJDIR)/Renderer.o: src/Graphics/Renderer.cpp
	@echo $(notdir $<)
	$(SILENT) $(CXX) $(CXXFLAGS) -o "$@" -c "$<"
$(OBJDIR)/stb_image.o: src/stblib/stb_image.c
	@echo $(notdir $<)
	$(SILENT) $(CC) $(CFLAGS) -o "$@" -c "$<"

-include $(OBJECTS:%.o=%.d)
