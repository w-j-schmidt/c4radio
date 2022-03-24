cmake_minimum_required(VERSION 3.16)

project(QtQuickStartTutorial VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOMOC ON)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 6.2 COMPONENTS Quick REQUIRED)

find_package(Qt6 COMPONENTS Bluetooth REQUIRED)


qt_add_executable(appQtQuickStartTutorial
    main.cpp backend.h backend.cpp c4btservice.h c4btservice.cpp
)

qt_add_qml_module(appQtQuickStartTutorial
    URI QtQuickStartTutorial
    VERSION 1.0
    QML_FILES
        main.qml
        Page.qml
    SOURCES
        backend.h
        c4btservice.h
    RESOURCES
        qt-logo.png
)

target_compile_definitions(appQtQuickStartTutorial
    PRIVATE $<$<OR:$<CONFIG:Debug>,$<CONFIG:RelWithDebInfo>>:QT_QML_DEBUG>)
target_link_libraries(appQtQuickStartTutorial
    PRIVATE Qt6::Quick)
target_link_libraries(appQtQuickStartTutorial
    PRIVATE Qt6::Bluetooth)
