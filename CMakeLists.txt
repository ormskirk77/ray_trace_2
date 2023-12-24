cmake_minimum_required(VERSION 3.26)
project(ray_trace_2)

set(CMAKE_CXX_STANDARD 17)

set(IMGUI_SOURCE_DIR "imgui-docking/")

include_directories(${IMGUI_SOURCE_DIR})

find_package(OpenGL REQUIRED)
find_package(glfw3 3.3 REQUIRED)

add_executable(ray_trace_2 main.cpp
        vec3.h
        color.h
        ray.h
        hittable.h
        sphere.h
        hit_record.h
        hittable_list.h
        rtweekend.h
        interval.h
        camera.h
        material.h)

target_link_libraries(ray_trace_2
        ${OPENGL_LIBRARIES}
        glfw
        dl
)

target_sources(ray_trace_2 PRIVATE
        ${IMGUI_SOURCE_DIR}/imgui.cpp
        ${IMGUI_SOURCE_DIR}/imgui_draw.cpp
        ${IMGUI_SOURCE_DIR}/imgui_widgets.cpp
        ${IMGUI_SOURCE_DIR}/imgui_tables.cpp
        ${IMGUI_SOURCE_DIR}/backends/imgui_impl_opengl3.cpp
        ${IMGUI_SOURCE_DIR}/backends/imgui_impl_glfw.cpp
        # Add other ImGui source files if needed
)
