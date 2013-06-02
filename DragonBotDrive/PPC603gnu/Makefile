# Wind River Workbench generated Makefile.
# Do not edit!!!
#
# The file ".wrmakefile" is the template used by the Wind River Workbench to
# generate the makefiles of this project. Add user-specific build targets and
# make rules only(!) in this project's ".wrmakefile" file. These will then be
# automatically dumped into the makefiles.

WIND_HOME := $(subst \,/,$(WIND_HOME))
WIND_BASE := $(subst \,/,$(WIND_BASE))
WIND_USR := $(subst \,/,$(WIND_USR))

all : pre_build main_all post_build

_clean ::
	@echo "make: removing targets and objects of `pwd`"

TRACE=0
TRACEON=$(TRACE:0=@)
TRACE_FLAG=$(TRACEON:1=)

MAKEFILE := Makefile

FLEXIBLE_BUILD := 1

BUILD_SPEC = PPC603gnu
DEBUG_MODE = 1
ifeq ($(DEBUG_MODE),1)
MODE_DIR := Debug
else
MODE_DIR := NonDebug
endif
OBJ_DIR := .
WS_ROOT_DIR := C:/Users/Scott/Documents/Code/DragonBot
PRJ_ROOT_DIR := $(WS_ROOT_DIR)/DragonBotDrive



#Global Build Macros
PROJECT_TYPE = DKM
DEFINES = 
EXPAND_DBG = 0


#BuildSpec specific Build Macros
VX_CPU_FAMILY = ppc
CPU = PPC603
TOOL_FAMILY = gnu
TOOL = gnu
TOOL_PATH = 
CC_ARCH_SPEC = -mcpu=603 -mstrict-align -mno-implicit-fp -mlongcall
LIBPATH = 
LIBS = 

IDE_INCLUDES = -I$(WIND_BASE)/target/h/WPILib -I$(WIND_BASE)/target/h -I$(WIND_BASE)/target/h/wrn/coreip 

IDE_LIBRARIES = $(WIND_BASE)/target/lib/WPILib.a 

IDE_DEFINES = 



#BuildTool flags
ifeq ($(DEBUG_MODE),1)
DEBUGFLAGS_C-Compiler = -g
DEBUGFLAGS_C++-Compiler = -g
DEBUGFLAGS_Linker = -g
DEBUGFLAGS_Partial-Image-Linker = 
DEBUGFLAGS_Librarian = 
DEBUGFLAGS_Assembler = -g
else
DEBUGFLAGS_C-Compiler = -O2 -fstrength-reduce -fno-builtin
DEBUGFLAGS_C++-Compiler = -O2 -fstrength-reduce -fno-builtin
DEBUGFLAGS_Linker = -O2 -fstrength-reduce -fno-builtin
DEBUGFLAGS_Partial-Image-Linker = 
DEBUGFLAGS_Librarian = 
DEBUGFLAGS_Assembler = -O2 -fstrength-reduce -fno-builtin
endif


#Project Targets
PROJECT_TARGETS = DragonBotDrive/$(MODE_DIR)/DragonBotDrive.out \
	 DragonBotDrive_partialImage/$(MODE_DIR)/DragonBotDrive_partialImage.o


#Rules

# DragonBotDrive
ifeq ($(DEBUG_MODE),1)
DragonBotDrive/$(MODE_DIR)/% : DEBUGFLAGS_C-Compiler = -g
DragonBotDrive/$(MODE_DIR)/% : DEBUGFLAGS_C++-Compiler = -g
DragonBotDrive/$(MODE_DIR)/% : DEBUGFLAGS_Linker = -g
DragonBotDrive/$(MODE_DIR)/% : DEBUGFLAGS_Partial-Image-Linker = 
DragonBotDrive/$(MODE_DIR)/% : DEBUGFLAGS_Librarian = 
DragonBotDrive/$(MODE_DIR)/% : DEBUGFLAGS_Assembler = -g
else
DragonBotDrive/$(MODE_DIR)/% : DEBUGFLAGS_C-Compiler = -O2 -fstrength-reduce -fno-builtin
DragonBotDrive/$(MODE_DIR)/% : DEBUGFLAGS_C++-Compiler = -O2 -fstrength-reduce -fno-builtin
DragonBotDrive/$(MODE_DIR)/% : DEBUGFLAGS_Linker = -O2 -fstrength-reduce -fno-builtin
DragonBotDrive/$(MODE_DIR)/% : DEBUGFLAGS_Partial-Image-Linker = 
DragonBotDrive/$(MODE_DIR)/% : DEBUGFLAGS_Librarian = 
DragonBotDrive/$(MODE_DIR)/% : DEBUGFLAGS_Assembler = -O2 -fstrength-reduce -fno-builtin
endif
DragonBotDrive/$(MODE_DIR)/% : IDE_INCLUDES = -I$(WIND_BASE)/target/h/WPILib -I$(WIND_BASE)/target/h -I$(WIND_BASE)/target/h/wrn/coreip 
DragonBotDrive/$(MODE_DIR)/% : IDE_LIBRARIES = $(WIND_BASE)/target/lib/WPILib.a 
DragonBotDrive/$(MODE_DIR)/% : IDE_DEFINES = 
DragonBotDrive/$(MODE_DIR)/% : PROJECT_TYPE = DKM
DragonBotDrive/$(MODE_DIR)/% : DEFINES = 
DragonBotDrive/$(MODE_DIR)/% : EXPAND_DBG = 0
DragonBotDrive/$(MODE_DIR)/% : VX_CPU_FAMILY = ppc
DragonBotDrive/$(MODE_DIR)/% : CPU = PPC603
DragonBotDrive/$(MODE_DIR)/% : TOOL_FAMILY = gnu
DragonBotDrive/$(MODE_DIR)/% : TOOL = gnu
DragonBotDrive/$(MODE_DIR)/% : TOOL_PATH = 
DragonBotDrive/$(MODE_DIR)/% : CC_ARCH_SPEC = -mcpu=603 -mstrict-align -mno-implicit-fp -mlongcall
DragonBotDrive/$(MODE_DIR)/% : LIBPATH = 
DragonBotDrive/$(MODE_DIR)/% : LIBS = 
DragonBotDrive/$(MODE_DIR)/% : OBJ_DIR := DragonBotDrive/$(MODE_DIR)

OBJECTS_DragonBotDrive = DragonBotDrive_partialImage/$(MODE_DIR)/DragonBotDrive_partialImage.o

DragonBotDrive/$(MODE_DIR)/DragonBotDrive.out : $(OBJECTS_DragonBotDrive)
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@";rm -f "$@";nmppc $(OBJECTS_DragonBotDrive) $(IDE_LIBRARIES) | tclsh $(WIND_BASE)/host/resource/hutils/tcl/munch.tcl -c ppc > $(OBJ_DIR)/ctdt.c; $(TOOL_PATH)ccppc $(DEBUGFLAGS_Linker) $(CC_ARCH_SPEC) -fdollars-in-identifiers -Wall $(ADDED_CFLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES)  -o $(OBJ_DIR)/ctdt.o -c $(OBJ_DIR)/ctdt.c; $(TOOL_PATH)ccppc -r -nostdlib -Wl,-X -T $(WIND_BASE)/target/h/tool/gnu/ldscripts/link.OUT -o "$@" $(OBJ_DIR)/ctdt.o $(OBJECTS_DragonBotDrive) $(IDE_LIBRARIES) $(LIBPATH) $(LIBS)  $(ADDED_LIBPATH) $(ADDED_LIBS) && if [ "$(EXPAND_DBG)" = "1" ]; then plink "$@";fi

DragonBotDrive/$(MODE_DIR)/DragonBotDrive_compile_file : $(FILE) ;

_clean :: DragonBotDrive/$(MODE_DIR)/DragonBotDrive_clean

DragonBotDrive/$(MODE_DIR)/DragonBotDrive_clean : 
	$(TRACE_FLAG)if [ -d "DragonBotDrive" ]; then cd "DragonBotDrive"; rm -rf $(MODE_DIR); fi


# DragonBotDrive_partialImage
ifeq ($(DEBUG_MODE),1)
DragonBotDrive_partialImage/$(MODE_DIR)/% : DEBUGFLAGS_C-Compiler = -g
DragonBotDrive_partialImage/$(MODE_DIR)/% : DEBUGFLAGS_C++-Compiler = -g
DragonBotDrive_partialImage/$(MODE_DIR)/% : DEBUGFLAGS_Linker = -g
DragonBotDrive_partialImage/$(MODE_DIR)/% : DEBUGFLAGS_Partial-Image-Linker = 
DragonBotDrive_partialImage/$(MODE_DIR)/% : DEBUGFLAGS_Librarian = 
DragonBotDrive_partialImage/$(MODE_DIR)/% : DEBUGFLAGS_Assembler = -g
else
DragonBotDrive_partialImage/$(MODE_DIR)/% : DEBUGFLAGS_C-Compiler = -O2 -fstrength-reduce -fno-builtin
DragonBotDrive_partialImage/$(MODE_DIR)/% : DEBUGFLAGS_C++-Compiler = -O2 -fstrength-reduce -fno-builtin
DragonBotDrive_partialImage/$(MODE_DIR)/% : DEBUGFLAGS_Linker = -O2 -fstrength-reduce -fno-builtin
DragonBotDrive_partialImage/$(MODE_DIR)/% : DEBUGFLAGS_Partial-Image-Linker = 
DragonBotDrive_partialImage/$(MODE_DIR)/% : DEBUGFLAGS_Librarian = 
DragonBotDrive_partialImage/$(MODE_DIR)/% : DEBUGFLAGS_Assembler = -O2 -fstrength-reduce -fno-builtin
endif
DragonBotDrive_partialImage/$(MODE_DIR)/% : IDE_INCLUDES = -I$(WIND_BASE)/target/h/WPILib -I$(WIND_BASE)/target/h -I$(WIND_BASE)/target/h/wrn/coreip 
DragonBotDrive_partialImage/$(MODE_DIR)/% : IDE_LIBRARIES = $(WIND_BASE)/target/lib/WPILib.a 
DragonBotDrive_partialImage/$(MODE_DIR)/% : IDE_DEFINES = 
DragonBotDrive_partialImage/$(MODE_DIR)/% : PROJECT_TYPE = DKM
DragonBotDrive_partialImage/$(MODE_DIR)/% : DEFINES = 
DragonBotDrive_partialImage/$(MODE_DIR)/% : EXPAND_DBG = 0
DragonBotDrive_partialImage/$(MODE_DIR)/% : VX_CPU_FAMILY = ppc
DragonBotDrive_partialImage/$(MODE_DIR)/% : CPU = PPC603
DragonBotDrive_partialImage/$(MODE_DIR)/% : TOOL_FAMILY = gnu
DragonBotDrive_partialImage/$(MODE_DIR)/% : TOOL = gnu
DragonBotDrive_partialImage/$(MODE_DIR)/% : TOOL_PATH = 
DragonBotDrive_partialImage/$(MODE_DIR)/% : CC_ARCH_SPEC = -mcpu=603 -mstrict-align -mno-implicit-fp -mlongcall
DragonBotDrive_partialImage/$(MODE_DIR)/% : LIBPATH = 
DragonBotDrive_partialImage/$(MODE_DIR)/% : LIBS = 
DragonBotDrive_partialImage/$(MODE_DIR)/% : OBJ_DIR := DragonBotDrive_partialImage/$(MODE_DIR)

DragonBotDrive_partialImage/$(MODE_DIR)/Objects/DragonBotDrive/DragonBotDriveTrain.o : $(PRJ_ROOT_DIR)/DragonBotDriveTrain.cpp $(FORCE_FILE_BUILD)
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)ccppc $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -Wall  -MD -MP -mlongcall $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"


DragonBotDrive_partialImage/$(MODE_DIR)/Objects/DragonBotDrive/Gamepad.o : $(PRJ_ROOT_DIR)/Gamepad.cpp $(FORCE_FILE_BUILD)
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)ccppc $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -Wall  -MD -MP -mlongcall $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"


OBJECTS_DragonBotDrive_partialImage = DragonBotDrive_partialImage/$(MODE_DIR)/Objects/DragonBotDrive/DragonBotDriveTrain.o \
	 DragonBotDrive_partialImage/$(MODE_DIR)/Objects/DragonBotDrive/Gamepad.o

DragonBotDrive_partialImage/$(MODE_DIR)/DragonBotDrive_partialImage.o : $(OBJECTS_DragonBotDrive_partialImage)
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)ccppc -r -nostdlib -Wl,-X  -o "$@" $(OBJECTS_DragonBotDrive_partialImage) $(LIBPATH) $(LIBS) $(ADDED_LIBPATH) $(ADDED_LIBS)  && if [ "$(EXPAND_DBG)" = "1" ]; then plink "$@";fi

DragonBotDrive_partialImage/$(MODE_DIR)/DragonBotDrive_partialImage_compile_file : $(FILE) ;

_clean :: DragonBotDrive_partialImage/$(MODE_DIR)/DragonBotDrive_partialImage_clean

DragonBotDrive_partialImage/$(MODE_DIR)/DragonBotDrive_partialImage_clean : 
	$(TRACE_FLAG)if [ -d "DragonBotDrive_partialImage" ]; then cd "DragonBotDrive_partialImage"; rm -rf $(MODE_DIR); fi

force : 

DEP_FILES := DragonBotDrive_partialImage/$(MODE_DIR)/Objects/DragonBotDrive/DragonBotDriveTrain.d DragonBotDrive_partialImage/$(MODE_DIR)/Objects/DragonBotDrive/Gamepad.d
-include $(DEP_FILES)



-include $(PRJ_ROOT_DIR)/*.makefile

-include *.makefile

main_all : external_build $(PROJECT_TARGETS)
	@echo "make: built targets of `pwd`"

# entry point for extending the build
external_build ::
	@echo ""

# main entry point for pre processing prior to the build
pre_build :: $(PRE_BUILD_STEP) generate_sources
	@echo ""

# entry point for generating sources prior to the build
generate_sources ::
	@echo ""

# main entry point for post processing after the build
post_build :: $(POST_BUILD_STEP) deploy_output
	@echo ""

# entry point for deploying output after the build
deploy_output ::
	@echo ""

clean :: external_clean $(CLEAN_STEP) _clean

# entry point for extending the build clean
external_clean ::
	@echo ""
