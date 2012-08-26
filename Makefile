#############################################################################
# Makefile for building: BKPaint2
# Generated by qmake (2.01a) (Qt 4.8.2) on: Sun Aug 26 09:00:36 2012
# Project:  BKPaint2.pro
# Template: app
# Command: /usr/bin/qmake -spec /usr/share/qt/mkspecs/linux-g++ CONFIG+=debug CONFIG+=declarative_debug -o Makefile BKPaint2.pro
#############################################################################

####### Compiler, tools and options

CC            = gcc
CXX           = g++
DEFINES       = -DQT_GUI_LIB -DQT_CORE_LIB -DQT_SHARED
CFLAGS        = -pipe -g -Wall -W -D_REENTRANT $(DEFINES)
CXXFLAGS      = -pipe -std=c++11 -g -Wall -W -D_REENTRANT $(DEFINES)
INCPATH       = -I/usr/share/qt/mkspecs/linux-g++ -I. -I/usr/include/QtCore -I/usr/include/QtGui -I/usr/include -I. -I.
LINK          = g++
LFLAGS        = -Wl,-O1,--sort-common,--as-needed,-z,relro
LIBS          = $(SUBLIBS)  -L/usr/lib -lQtGui -lQtCore -lpthread 
AR            = ar cqs
RANLIB        = 
QMAKE         = /usr/bin/qmake
TAR           = tar -cf
COMPRESS      = gzip -9f
COPY          = cp -f
SED           = sed
COPY_FILE     = $(COPY)
COPY_DIR      = $(COPY) -r
STRIP         = strip
INSTALL_FILE  = install -m 644 -p
INSTALL_DIR   = $(COPY_DIR)
INSTALL_PROGRAM = install -m 755 -p
DEL_FILE      = rm -f
SYMLINK       = ln -f -s
DEL_DIR       = rmdir
MOVE          = mv -f
CHK_DIR_EXISTS= test -d
MKDIR         = mkdir -p

####### Output directory

OBJECTS_DIR   = ./

####### Files

SOURCES       = main.cpp \
		mainwindow.cpp \
		canvas.cpp \
		paintoperation.cpp \
		addline.cpp \
		addrect.cpp \
		addimage.cpp \
		changeline.cpp \
		changerect.cpp \
		player.cpp \
		mousepress.cpp moc_mainwindow.cpp \
		moc_canvas.cpp \
		moc_player.cpp
OBJECTS       = main.o \
		mainwindow.o \
		canvas.o \
		paintoperation.o \
		addline.o \
		addrect.o \
		addimage.o \
		changeline.o \
		changerect.o \
		player.o \
		mousepress.o \
		moc_mainwindow.o \
		moc_canvas.o \
		moc_player.o
DIST          = /usr/share/qt/mkspecs/common/unix.conf \
		/usr/share/qt/mkspecs/common/linux.conf \
		/usr/share/qt/mkspecs/common/gcc-base.conf \
		/usr/share/qt/mkspecs/common/gcc-base-unix.conf \
		/usr/share/qt/mkspecs/common/g++-base.conf \
		/usr/share/qt/mkspecs/common/g++-unix.conf \
		/usr/share/qt/mkspecs/qconfig.pri \
		/usr/share/qt/mkspecs/modules/qt_phonon.pri \
		/usr/share/qt/mkspecs/modules/qt_webkit_version.pri \
		/usr/share/qt/mkspecs/features/qt_functions.prf \
		/usr/share/qt/mkspecs/features/qt_config.prf \
		/usr/share/qt/mkspecs/features/exclusive_builds.prf \
		/usr/share/qt/mkspecs/features/default_pre.prf \
		/usr/share/qt/mkspecs/features/debug.prf \
		/usr/share/qt/mkspecs/features/default_post.prf \
		/usr/share/qt/mkspecs/features/declarative_debug.prf \
		/usr/share/qt/mkspecs/features/unix/gdb_dwarf_index.prf \
		/usr/share/qt/mkspecs/features/warn_on.prf \
		/usr/share/qt/mkspecs/features/qt.prf \
		/usr/share/qt/mkspecs/features/unix/thread.prf \
		/usr/share/qt/mkspecs/features/moc.prf \
		/usr/share/qt/mkspecs/features/resources.prf \
		/usr/share/qt/mkspecs/features/uic.prf \
		/usr/share/qt/mkspecs/features/yacc.prf \
		/usr/share/qt/mkspecs/features/lex.prf \
		/usr/share/qt/mkspecs/features/include_source_dir.prf \
		BKPaint2.pro
QMAKE_TARGET  = BKPaint2
DESTDIR       = 
TARGET        = BKPaint2

first: all
####### Implicit rules

.SUFFIXES: .o .c .cpp .cc .cxx .C

.cpp.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.cc.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.cxx.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.C.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.c.o:
	$(CC) -c $(CFLAGS) $(INCPATH) -o "$@" "$<"

####### Build rules

all: Makefile $(TARGET)

$(TARGET): ui_mainwindow.h ui_canvas.h $(OBJECTS)  
	$(LINK) $(LFLAGS) -o $(TARGET) $(OBJECTS) $(OBJCOMP) $(LIBS)
	{ test -n "$(DESTDIR)" && DESTDIR="$(DESTDIR)" || DESTDIR=.; } && test $$(gdb --version | sed -e 's,[^0-9]\+\([0-9]\)\.\([0-9]\).*,\1\2,;q') -gt 72 && gdb --nx --batch --quiet -ex 'set confirm off' -ex "save gdb-index $$DESTDIR" -ex quit '$(TARGET)' && test -f $(TARGET).gdb-index && objcopy --add-section '.gdb_index=$(TARGET).gdb-index' --set-section-flags '.gdb_index=readonly' '$(TARGET)' '$(TARGET)' && rm -f $(TARGET).gdb-index || true

Makefile: BKPaint2.pro  /usr/share/qt/mkspecs/linux-g++/qmake.conf /usr/share/qt/mkspecs/common/unix.conf \
		/usr/share/qt/mkspecs/common/linux.conf \
		/usr/share/qt/mkspecs/common/gcc-base.conf \
		/usr/share/qt/mkspecs/common/gcc-base-unix.conf \
		/usr/share/qt/mkspecs/common/g++-base.conf \
		/usr/share/qt/mkspecs/common/g++-unix.conf \
		/usr/share/qt/mkspecs/qconfig.pri \
		/usr/share/qt/mkspecs/modules/qt_phonon.pri \
		/usr/share/qt/mkspecs/modules/qt_webkit_version.pri \
		/usr/share/qt/mkspecs/features/qt_functions.prf \
		/usr/share/qt/mkspecs/features/qt_config.prf \
		/usr/share/qt/mkspecs/features/exclusive_builds.prf \
		/usr/share/qt/mkspecs/features/default_pre.prf \
		/usr/share/qt/mkspecs/features/debug.prf \
		/usr/share/qt/mkspecs/features/default_post.prf \
		/usr/share/qt/mkspecs/features/declarative_debug.prf \
		/usr/share/qt/mkspecs/features/unix/gdb_dwarf_index.prf \
		/usr/share/qt/mkspecs/features/warn_on.prf \
		/usr/share/qt/mkspecs/features/qt.prf \
		/usr/share/qt/mkspecs/features/unix/thread.prf \
		/usr/share/qt/mkspecs/features/moc.prf \
		/usr/share/qt/mkspecs/features/resources.prf \
		/usr/share/qt/mkspecs/features/uic.prf \
		/usr/share/qt/mkspecs/features/yacc.prf \
		/usr/share/qt/mkspecs/features/lex.prf \
		/usr/share/qt/mkspecs/features/include_source_dir.prf \
		/usr/lib/libQtGui.prl \
		/usr/lib/libQtCore.prl
	$(QMAKE) -spec /usr/share/qt/mkspecs/linux-g++ CONFIG+=debug CONFIG+=declarative_debug -o Makefile BKPaint2.pro
/usr/share/qt/mkspecs/common/unix.conf:
/usr/share/qt/mkspecs/common/linux.conf:
/usr/share/qt/mkspecs/common/gcc-base.conf:
/usr/share/qt/mkspecs/common/gcc-base-unix.conf:
/usr/share/qt/mkspecs/common/g++-base.conf:
/usr/share/qt/mkspecs/common/g++-unix.conf:
/usr/share/qt/mkspecs/qconfig.pri:
/usr/share/qt/mkspecs/modules/qt_phonon.pri:
/usr/share/qt/mkspecs/modules/qt_webkit_version.pri:
/usr/share/qt/mkspecs/features/qt_functions.prf:
/usr/share/qt/mkspecs/features/qt_config.prf:
/usr/share/qt/mkspecs/features/exclusive_builds.prf:
/usr/share/qt/mkspecs/features/default_pre.prf:
/usr/share/qt/mkspecs/features/debug.prf:
/usr/share/qt/mkspecs/features/default_post.prf:
/usr/share/qt/mkspecs/features/declarative_debug.prf:
/usr/share/qt/mkspecs/features/unix/gdb_dwarf_index.prf:
/usr/share/qt/mkspecs/features/warn_on.prf:
/usr/share/qt/mkspecs/features/qt.prf:
/usr/share/qt/mkspecs/features/unix/thread.prf:
/usr/share/qt/mkspecs/features/moc.prf:
/usr/share/qt/mkspecs/features/resources.prf:
/usr/share/qt/mkspecs/features/uic.prf:
/usr/share/qt/mkspecs/features/yacc.prf:
/usr/share/qt/mkspecs/features/lex.prf:
/usr/share/qt/mkspecs/features/include_source_dir.prf:
/usr/lib/libQtGui.prl:
/usr/lib/libQtCore.prl:
qmake:  FORCE
	@$(QMAKE) -spec /usr/share/qt/mkspecs/linux-g++ CONFIG+=debug CONFIG+=declarative_debug -o Makefile BKPaint2.pro

dist: 
	@$(CHK_DIR_EXISTS) .tmp/BKPaint21.0.0 || $(MKDIR) .tmp/BKPaint21.0.0 
	$(COPY_FILE) --parents $(SOURCES) $(DIST) .tmp/BKPaint21.0.0/ && $(COPY_FILE) --parents mainwindow.h canvas.h paintoperation.h addline.h addrect.h addimage.h changeline.h changerect.h player.h mousepress.h .tmp/BKPaint21.0.0/ && $(COPY_FILE) --parents main.cpp mainwindow.cpp canvas.cpp paintoperation.cpp addline.cpp addrect.cpp addimage.cpp changeline.cpp changerect.cpp player.cpp mousepress.cpp .tmp/BKPaint21.0.0/ && $(COPY_FILE) --parents mainwindow.ui canvas.ui .tmp/BKPaint21.0.0/ && (cd `dirname .tmp/BKPaint21.0.0` && $(TAR) BKPaint21.0.0.tar BKPaint21.0.0 && $(COMPRESS) BKPaint21.0.0.tar) && $(MOVE) `dirname .tmp/BKPaint21.0.0`/BKPaint21.0.0.tar.gz . && $(DEL_FILE) -r .tmp/BKPaint21.0.0


clean:compiler_clean 
	-$(DEL_FILE) $(OBJECTS)
	-$(DEL_FILE) *~ core *.core


####### Sub-libraries

distclean: clean
	-$(DEL_FILE) $(TARGET) 
	-$(DEL_FILE) Makefile


check: first

mocclean: compiler_moc_header_clean compiler_moc_source_clean

mocables: compiler_moc_header_make_all compiler_moc_source_make_all

compiler_moc_header_make_all: moc_mainwindow.cpp moc_canvas.cpp moc_player.cpp
compiler_moc_header_clean:
	-$(DEL_FILE) moc_mainwindow.cpp moc_canvas.cpp moc_player.cpp
moc_mainwindow.cpp: mainwindow.h
	/usr/bin/moc $(DEFINES) $(INCPATH) mainwindow.h -o moc_mainwindow.cpp

moc_canvas.cpp: canvas.h
	/usr/bin/moc $(DEFINES) $(INCPATH) canvas.h -o moc_canvas.cpp

moc_player.cpp: player.h
	/usr/bin/moc $(DEFINES) $(INCPATH) player.h -o moc_player.cpp

compiler_rcc_make_all:
compiler_rcc_clean:
compiler_image_collection_make_all: qmake_image_collection.cpp
compiler_image_collection_clean:
	-$(DEL_FILE) qmake_image_collection.cpp
compiler_moc_source_make_all:
compiler_moc_source_clean:
compiler_uic_make_all: ui_mainwindow.h ui_canvas.h
compiler_uic_clean:
	-$(DEL_FILE) ui_mainwindow.h ui_canvas.h
ui_mainwindow.h: mainwindow.ui \
		canvas.h
	/usr/bin/uic mainwindow.ui -o ui_mainwindow.h

ui_canvas.h: canvas.ui
	/usr/bin/uic canvas.ui -o ui_canvas.h

compiler_yacc_decl_make_all:
compiler_yacc_decl_clean:
compiler_yacc_impl_make_all:
compiler_yacc_impl_clean:
compiler_lex_make_all:
compiler_lex_clean:
compiler_clean: compiler_moc_header_clean compiler_uic_clean 

####### Compile

main.o: main.cpp mainwindow.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o main.o main.cpp

mainwindow.o: mainwindow.cpp mainwindow.h \
		ui_mainwindow.h \
		canvas.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o mainwindow.o mainwindow.cpp

canvas.o: canvas.cpp canvas.h \
		ui_canvas.h \
		player.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o canvas.o canvas.cpp

paintoperation.o: paintoperation.cpp paintoperation.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o paintoperation.o paintoperation.cpp

addline.o: addline.cpp addline.h \
		paintoperation.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o addline.o addline.cpp

addrect.o: addrect.cpp addrect.h \
		paintoperation.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o addrect.o addrect.cpp

addimage.o: addimage.cpp addimage.h \
		paintoperation.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o addimage.o addimage.cpp

changeline.o: changeline.cpp changeline.h \
		paintoperation.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o changeline.o changeline.cpp

changerect.o: changerect.cpp changerect.h \
		paintoperation.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o changerect.o changerect.cpp

player.o: player.cpp player.h \
		canvas.h \
		paintoperation.h \
		addline.h \
		addrect.h \
		changeline.h \
		changerect.h \
		mousepress.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o player.o player.cpp

mousepress.o: mousepress.cpp mousepress.h \
		paintoperation.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o mousepress.o mousepress.cpp

moc_mainwindow.o: moc_mainwindow.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_mainwindow.o moc_mainwindow.cpp

moc_canvas.o: moc_canvas.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_canvas.o moc_canvas.cpp

moc_player.o: moc_player.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_player.o moc_player.cpp

####### Install

install:   FORCE

uninstall:   FORCE

FORCE:

