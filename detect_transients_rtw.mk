###########################################################################
## Makefile generated for component 'detect_transients'. 
## 
## Makefile     : detect_transients_rtw.mk
## Generated on : Thu Jul 04 17:34:15 2024
## Final product: ./detect_transients.a
## Product type : static-library
## 
###########################################################################

###########################################################################
## MACROS
###########################################################################

# Macro Descriptions:
# PRODUCT_NAME            Name of the system to build
# MAKEFILE                Name of this makefile
# MODELLIB                Static library target

PRODUCT_NAME              = detect_transients
MAKEFILE                  = detect_transients_rtw.mk
START_DIR                 = /home/pi/codegen_transient_detector
TGT_FCN_LIB               = ISO_C
SOLVER_OBJ                = 
CLASSIC_INTERFACE         = 0
MODEL_HAS_DYNAMICALLY_LOADED_SFCNS = 
RELATIVE_PATH_TO_ANCHOR   = ../../..
C_STANDARD_OPTS           = -fwrapv
CPP_STANDARD_OPTS         = -fwrapv
MODELLIB                  = detect_transients.a

###########################################################################
## TOOLCHAIN SPECIFICATIONS
###########################################################################

# Toolchain Name:          GNU gcc/g++ | gmake (64-bit Linux)
# Supported Version(s):    
# ToolchainInfo Version:   2023b
# Specification Revision:  1.0
# 
#-------------------------------------------
# Macros assumed to be defined elsewhere
#-------------------------------------------

# C_STANDARD_OPTS
# CPP_STANDARD_OPTS

#-----------
# MACROS
#-----------

WARN_FLAGS         = -Wall -W -Wwrite-strings -Winline -Wstrict-prototypes -Wnested-externs -Wpointer-arith -Wcast-align
WARN_FLAGS_MAX     = $(WARN_FLAGS) -Wcast-qual -Wshadow
CPP_WARN_FLAGS     = -Wall -W -Wwrite-strings -Winline -Wpointer-arith -Wcast-align
CPP_WARN_FLAGS_MAX = $(CPP_WARN_FLAGS) -Wcast-qual -Wshadow

TOOLCHAIN_SRCS = 
TOOLCHAIN_INCS = 
TOOLCHAIN_LIBS = 

#------------------------
# BUILD TOOL COMMANDS
#------------------------

# C Compiler: GNU C Compiler
CC = gcc

# Linker: GNU Linker
LD = g++

# C++ Compiler: GNU C++ Compiler
CPP = g++

# C++ Linker: GNU C++ Linker
CPP_LD = g++

# Archiver: GNU Archiver
AR = ar

# Download: Download
DOWNLOAD =

# Execute: Execute
EXECUTE = $(PRODUCT)

# Builder: GMAKE Utility
MAKE_PATH = /usr/bin
MAKE = "$(MAKE_PATH)/gmake"

#-------------------------
# Directives/Utilities
#-------------------------

CDEBUG              = -g
C_OUTPUT_FLAG       = -o
LDDEBUG             = -g
OUTPUT_FLAG         = -o
CPPDEBUG            = -g
CPP_OUTPUT_FLAG     = -o
CPPLDDEBUG          = -g
OUTPUT_FLAG         = -o
ARDEBUG             =
STATICLIB_OUTPUT_FLAG =
RM                  = @rm -f
ECHO                = @echo
MV                  = @mv
RUN                 =

#--------------------------------------
# "Faster Runs" Build Configuration
#--------------------------------------

ARFLAGS              = ruvs
CFLAGS               = -c $(C_STANDARD_OPTS) -fPIC \
                       -O3 -fno-loop-optimize -fno-aggressive-loop-optimizations
CPPFLAGS             = -c $(CPP_STANDARD_OPTS) -fPIC \
                       -O3 -fno-loop-optimize -fno-aggressive-loop-optimizations
CPP_LDFLAGS          =
CPP_SHAREDLIB_LDFLAGS  = -shared -Wl,--no-undefined
DOWNLOAD_FLAGS       =
EXECUTE_FLAGS        =
LDFLAGS              =

###########################################################################
## OUTPUT INFO
###########################################################################

PRODUCT = ./detect_transients.a
PRODUCT_TYPE = "static-library"
BUILD_TYPE = "Static Library"

###########################################################################
## INCLUDE PATHS
###########################################################################

INCLUDES_BUILDINFO = -I$(START_DIR)/codegen/lib/detect_transients -I$(START_DIR)

INCLUDES = $(INCLUDES_BUILDINFO)

###########################################################################
## DEFINES
###########################################################################

DEFINES_CUSTOM = 
DEFINES_STANDARD = -DMODEL=detect_transients

DEFINES = $(DEFINES_CUSTOM) $(DEFINES_STANDARD)

###########################################################################
## SOURCE FILES
###########################################################################

SRCS = $(START_DIR)/codegen/lib/detect_transients/detect_transients_data.c $(START_DIR)/codegen/lib/detect_transients/detect_transients_initialize.c $(START_DIR)/codegen/lib/detect_transients/detect_transients_terminate.c $(START_DIR)/codegen/lib/detect_transients/detect_transients.c $(START_DIR)/codegen/lib/detect_transients/transient_detector_func.c $(START_DIR)/codegen/lib/detect_transients/stft.c $(START_DIR)/codegen/lib/detect_transients/FFTImplementationCallback.c $(START_DIR)/codegen/lib/detect_transients/diff.c $(START_DIR)/codegen/lib/detect_transients/formatSTFTOutput.c $(START_DIR)/codegen/lib/detect_transients/detect_transients_emxutil.c $(START_DIR)/codegen/lib/detect_transients/detect_transients_emxAPI.c

ALL_SRCS = $(SRCS)

###########################################################################
## OBJECTS
###########################################################################

OBJS = detect_transients_data.o detect_transients_initialize.o detect_transients_terminate.o detect_transients.o transient_detector_func.o stft.o FFTImplementationCallback.o diff.o formatSTFTOutput.o detect_transients_emxutil.o detect_transients_emxAPI.o

ALL_OBJS = $(OBJS)

###########################################################################
## PREBUILT OBJECT FILES
###########################################################################

PREBUILT_OBJS = 

###########################################################################
## LIBRARIES
###########################################################################

LIBS = 

###########################################################################
## SYSTEM LIBRARIES
###########################################################################

SYSTEM_LIBS =  -lm -liomp5

###########################################################################
## ADDITIONAL TOOLCHAIN FLAGS
###########################################################################

#---------------
# C Compiler
#---------------

CFLAGS_OPTS = -fopenmp
CFLAGS_BASIC = $(DEFINES) $(INCLUDES)

CFLAGS += $(CFLAGS_OPTS) $(CFLAGS_BASIC)

#-----------------
# C++ Compiler
#-----------------

CPPFLAGS_OPTS = -fopenmp
CPPFLAGS_BASIC = $(DEFINES) $(INCLUDES)

CPPFLAGS += $(CPPFLAGS_OPTS) $(CPPFLAGS_BASIC)

###########################################################################
## INLINED COMMANDS
###########################################################################

###########################################################################
## PHONY TARGETS
###########################################################################

.PHONY : all build clean info prebuild download execute


all : build
	@echo "### Successfully generated all binary outputs."


build : prebuild $(PRODUCT)


prebuild : 


download : $(PRODUCT)


execute : download


###########################################################################
## FINAL TARGET
###########################################################################

#---------------------------------
# Create a static library         
#---------------------------------

$(PRODUCT) : $(OBJS) $(PREBUILT_OBJS)
	@echo "### Creating static library "$(PRODUCT)" ..."
	$(AR) $(ARFLAGS)  $(PRODUCT) $(OBJS)
	@echo "### Created: $(PRODUCT)"


###########################################################################
## INTERMEDIATE TARGETS
###########################################################################

#---------------------
# SOURCE-TO-OBJECT
#---------------------

%.o : %.c
	$(CC) $(CFLAGS) -o "$@" "$<"

%.o : %.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"

detect_transients_data.o : $(START_DIR)/codegen/lib/detect_transients/detect_transients_data.c
	$(CC) $(CFLAGS) -o "$@" "$<"

detect_transients_initialize.o : $(START_DIR)/codegen/lib/detect_transients/detect_transients_initialize.c
	$(CC) $(CFLAGS) -o "$@" "$<"

detect_transients_terminate.o : $(START_DIR)/codegen/lib/detect_transients/detect_transients_terminate.c
	$(CC) $(CFLAGS) -o "$@" "$<"

detect_transients.o : $(START_DIR)/codegen/lib/detect_transients/detect_transients.c
	$(CC) $(CFLAGS) -o "$@" "$<"

transient_detector_func.o : $(START_DIR)/codegen/lib/detect_transients/transient_detector_func.c
	$(CC) $(CFLAGS) -o "$@" "$<"

stft.o : $(START_DIR)/codegen/lib/detect_transients/stft.c
	$(CC) $(CFLAGS) -o "$@" "$<"

FFTImplementationCallback.o : $(START_DIR)/codegen/lib/detect_transients/FFTImplementationCallback.c
	$(CC) $(CFLAGS) -o "$@" "$<"

diff.o : $(START_DIR)/codegen/lib/detect_transients/diff.c
	$(CC) $(CFLAGS) -o "$@" "$<"

formatSTFTOutput.o : $(START_DIR)/codegen/lib/detect_transients/formatSTFTOutput.c
	$(CC) $(CFLAGS) -o "$@" "$<"

detect_transients_emxutil.o : $(START_DIR)/codegen/lib/detect_transients/detect_transients_emxutil.c
	$(CC) $(CFLAGS) -o "$@" "$<"

detect_transients_emxAPI.o : $(START_DIR)/codegen/lib/detect_transients/detect_transients_emxAPI.c
	$(CC) $(CFLAGS) -o "$@" "$<"

###########################################################################
## DEPENDENCIES
###########################################################################

$(ALL_OBJS) : rtw_proj.tmw $(MAKEFILE)

###########################################################################
## MISCELLANEOUS TARGETS
###########################################################################

info : 
	@echo "### PRODUCT = $(PRODUCT)"
	@echo "### PRODUCT_TYPE = $(PRODUCT_TYPE)"
	@echo "### BUILD_TYPE = $(BUILD_TYPE)"
	@echo "### INCLUDES = $(INCLUDES)"
	@echo "### DEFINES = $(DEFINES)"
	@echo "### ALL_SRCS = $(ALL_SRCS)"
	@echo "### ALL_OBJS = $(ALL_OBJS)"
	@echo "### LIBS = $(LIBS)"
	@echo "### SYSTEM_LIBS = $(SYSTEM_LIBS)"
	@echo "### TOOLCHAIN_LIBS = $(TOOLCHAIN_LIBS)"
	@echo "### CFLAGS = $(CFLAGS)"
	@echo "### LDFLAGS = $(LDFLAGS)"
	@echo "### SHAREDLIB_LDFLAGS = $(SHAREDLIB_LDFLAGS)"
	@echo "### CPPFLAGS = $(CPPFLAGS)"
	@echo "### CPP_LDFLAGS = $(CPP_LDFLAGS)"
	@echo "### CPP_SHAREDLIB_LDFLAGS = $(CPP_SHAREDLIB_LDFLAGS)"
	@echo "### ARFLAGS = $(ARFLAGS)"

clean : 
	$(ECHO) "### Deleting all derived files ..."
	$(RM) $(PRODUCT)
	$(RM) $(ALL_OBJS)
	$(ECHO) "### Deleted all derived files."
