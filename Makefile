SRC = ./
DESTDIR =
INCLUDEDIR = $(DESTDIR)/usr/include/connui
PKGCONFIGDIR = $(DESTDIR)/usr/lib/pkgconfig
LIBDIR = $(DESTDIR)/usr/lib

INSTALL = install
INSTALL_PROGRAM = $(INSTALL)

INSTALL_INCLUDES = libconnui.h net_definitions.h net_interface.xml
INSTALL_PKGCONFIG = libconnui.pc
INSTALL_LIBS = libconnui_cell.so.0.0.0 libconnui.so.0.0.0

all:

install:
	$(INSTALL_PROGRAM) -d $(INCLUDEDIR)
	$(INSTALL_PROGRAM) -m644 $(INSTALL_INCLUDES) $(INCLUDEDIR)
	$(INSTALL_PROGRAM) -d $(PKGCONFIGDIR)
	$(INSTALL_PROGRAM) -m644 $(INSTALL_PKGCONFIG) $(PKGCONFIGDIR)
	$(INSTALL_PROGRAM) -d $(LIBDIR)
	$(INSTALL_PROGRAM) -m644 $(INSTALL_LIBS) $(LIBDIR)

clean:
	$(RM) *~
