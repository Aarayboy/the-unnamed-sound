cmake_minimum_required(VERSION 3.5)

project(QtHW VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)
find_package(Qt6 REQUIRED COMPONENTS Widgets Multimedia)

set(PROJECT_SOURCES
        main.cpp
        mainwindow.cpp
        mainwindow.h
        mainwindow.ui
        data.cpp
        data.h
        icons.qrc
        listenapp.cpp
        listenapp.h
        login.cpp
        login.h
        login.ui
        recommends.cpp
        recommends.h
        recommends.ui
        Register.cpp
        Register.h
        Register.ui
        resourse.qrc
        search.cpp
        search.h
        search.ui
        search_music.cpp
        search_music.h
        search_music.ui
        set_skin.cpp
        set_skin.h
        set_skin.ui
        user.cpp
        user.h
        yibofang.cpp
        yibofang.h
        yibofang.ui
)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(QtHW
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
        content.h content.cpp content.ui
        choose.h choose.cpp choose.ui
        backsee.h backsee.cpp backsee.ui
    )
# Define target properties for Android with Qt 6 as:
#    set_property(TARGET QtHW APPEND PROPERTY QT_ANDROID_PACKAGE_SOURCE_DIR
#                 ${CMAKE_CURRENT_SOURCE_DIR}/android)
# For more information, see https://doc.qt.io/qt-6/qt-add-executable.html#target-creation
else()
    if(ANDROID)
        add_library(QtHW SHARED
            ${PROJECT_SOURCES}
        )
# Define properties for Android with Qt 5 after find_package() calls as:
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
    else()
        add_executable(QtHW
            ${PROJECT_SOURCES}
        )
    endif()
endif()

target_link_libraries(QtHW PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)

# Qt for iOS sets MACOSX_BUNDLE_GUI_IDENTIFIER automatically since Qt 6.1.
# If you are developing for iOS or macOS you should consider setting an
# explicit, fixed bundle identifier manually though.
if(${QT_VERSION} VERSION_LESS 6.1.0)
  set(BUNDLE_ID_OPTION MACOSX_BUNDLE_GUI_IDENTIFIER com.example.QtHW)
endif()
set_target_properties(QtHW PROPERTIES
    ${BUNDLE_ID_OPTION}
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

include(GNUInstallDirs)
install(TARGETS QtHW
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
target_link_libraries(QtHW PRIVATE Qt6::Widgets Qt6::Multimedia)
if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(QtHW)
endif()
