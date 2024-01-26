cmake_minimum_required(VERSION 3.26)
project(msaa_bug)

find_package(VTK REQUIRED)

add_executable(msaa_bug main.cpp)

target_link_libraries(msaa_bug ${VTK_LIBRARIES})

vtk_module_autoinit(
        TARGETS msaa_bug
        MODULES ${VTK_LIBRARIES}
)