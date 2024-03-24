# include parent_common.mk for buildsystem's defines
#use absolute path for REPO_PARENT
REPO_PARENT=$(shell /bin/pwd)/..
-include $(REPO_PARENT)/parent_common.mk

# export git tree for subdirs
GIT_VERSION ?= $(shell git describe --dirty --long --tags)
export GIT_VERSION

DIRS = kernel

.PHONY: all clean modules install modules_install $(DIRS)

all clean modules install modules_install: $(DIRS)

clean: TARGET = clean
modules: TARGET = modules
install: TARGET = install
modules_install: TARGET = modules_install

$(DIRS):
	$(MAKE) -C $@ $(TARGET)

kernel: 
