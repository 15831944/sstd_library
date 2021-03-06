
win32-msvc*{
    SOURCES              += $$PWD/msvc/botan_all.cpp
    HEADERS              += $$PWD/msvc/botan_all.h
    INCLUDEPATH          += $$PWD/msvc/build/include
    INCLUDEPATH          += $$PWD/msvc/build/include/external
    DEFINES              *= BOTAN_USE_MSVC_
    QMAKE_CXXFLAGS       += /bigobj
    DEFINES              *= _ENABLE_EXTENDED_ALIGNED_STORAGE
    DEFINES              *= _CRT_SECURE_NO_WARNINGS
    LIBS                 += user32.lib
}

win32-g++*{
    include($$PWD/mingw_gcc/botan_all.pri)
    HEADERS              += $$PWD/mingw_gcc/botan_all.h
    INCLUDEPATH          += $$PWD/mingw_gcc/build/include
    INCLUDEPATH          += $$PWD/mingw_gcc/build/include/external
    DEFINES              *= BOTAN_USE_MINGW_GCC_
    #LIBS                 += -lws2_32
    DEFINES              *= _REENTRANT
    PRECOMPILED_HEADER   += $$PWD/mingw_gcc/precompiled_botan_all.h
}

linux-g++*{
    include($$PWD/linux_gcc/botan_all.pri)
    HEADERS              += $$PWD/linux_gcc/botan_all.h
    INCLUDEPATH          += $$PWD/linux_gcc/build/include
    INCLUDEPATH          += $$PWD/linux_gcc/build/include/external
    DEFINES              *= BOTAN_USE_LINUX_GCC_
    DEFINES              *= _REENTRANT
    PRECOMPILED_HEADER   += $$PWD/linux_gcc/precompiled_botan_all.h
}

HEADERS += $$PWD/sstd_botan.hpp
SOURCES += $$PWD/sstd_botan.cpp
