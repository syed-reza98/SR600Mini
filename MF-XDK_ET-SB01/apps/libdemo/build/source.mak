
#library path
LIB_PATH=	
#link library
LINK_LIB=

#include 
INC_PATH=$(LINUX_PLAT_COMPONENT_LINUX) \
			$(LINUX_PLAT_COMPONENT_LINUX)/sdk/inc/
			
#source list
SRC_DIRS := $(shell find $(PROJECT_PATH)/src -maxdepth 5 -type d)
SRC_LIST := $(foreach dir,$(SRC_DIRS),$(wildcard $(dir)/*.c)) 
			