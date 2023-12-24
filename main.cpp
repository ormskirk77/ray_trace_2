
#include <iostream>

#include "rtweekend.h"

#include "camera.h"
#include "color.h"
#include "hittable_list.h"
#include "material.h"
#include "sphere.h"



int main() {
    hittable_list world;
    auto R = cos(pi/4);
    auto ground_material = make_shared<lambertian>(color(0.5, 0.5, 0.5));
    world.add(make_shared<sphere>(point3(0,-1000,0), 1000, ground_material));

    for (int a = -11; a < 11; a++) {
        for (int b = -11; b < 11; b++) {
            auto choose_mat = random_double();
            point3 center(a + 0.9*random_double(), 0.2, b + 0.9*random_double());

            if ((center - point3(4, 0.2, 0)).length() > 0.9) {
                shared_ptr<material> sphere_material;

                if (choose_mat < 0.8) {
                    // diffuse
                    auto albedo = color::random() * color::random();
                    sphere_material = make_shared<lambertian>(albedo);
                    world.add(make_shared<sphere>(center, 0.2, sphere_material));
                } else if (choose_mat < 0.95) {
                    // metal
                    auto albedo = color::random(0.5, 1);
                    auto fuzz = random_double(0, 0.5);
                    sphere_material = make_shared<metal>(albedo, fuzz);
                    world.add(make_shared<sphere>(center, 0.2, sphere_material));
                } else {
                    // glass
                    sphere_material = make_shared<dielectric>(1.5);
                    world.add(make_shared<sphere>(center, 0.2, sphere_material));
                }
            }
        }
    }

    auto material1 = make_shared<dielectric>(1.5);
    world.add(make_shared<sphere>(point3(0, 1, 0), 1.0, material1));

    auto material2 = make_shared<lambertian>(color(0.4, 0.2, 0.1));
    world.add(make_shared<sphere>(point3(-4, 1, 0), 1.0, material2));

    auto material3 = make_shared<metal>(color(0.7, 0.6, 0.5), 0.0);
    world.add(make_shared<sphere>(point3(4, 1, 0), 1.0, material3));

//    auto material_ground = make_shared<lambertian>(color(0.8, 0.8, 0.0));
//    auto material_center = make_shared<lambertian>(color(0.1, 0.2, 0.5));
//    auto material_left   = make_shared<dielectric>(1.5);
//    auto material_right  = make_shared<metal>(color(0.8, 0.6, 0.2), 0.0);
//
//    world.add(make_shared<sphere>(point3( 0.0, -100.5, -1.0), 100.0, material_ground));
//    world.add(make_shared<sphere>(point3( 0.0,    0.0, -1.0),   0.5, material_center));
//    world.add(make_shared<sphere>(point3(-1.0,    0.0, -1.0),   0.5, material_left));
//    world.add(make_shared<sphere>(point3(-1.0,    0.0, -1.0),  -0.4, material_left));
//    world.add(make_shared<sphere>(point3( 1.0,    0.0, -1.0),   0.5, material_right));

//    auto material_ground = make_shared<lambertian>(color(0.8, 0.8, 0.0));
//    auto material_center = make_shared<lambertian>(color(0.1, 0.2, 0.5));
//    auto material_left   = make_shared<dielectric>(1.5);
//    auto material_right  = make_shared<metal>(color(0.8, 0.6, 0.2), 0.0);
//
//    world.add(make_shared<sphere>(point3( 0.0, -100.5, -1.0), 100.0, material_ground));
//    world.add(make_shared<sphere>(point3( 0.0,    0.0, -1.0),   0.5, material_center));
//    world.add(make_shared<sphere>(point3(-1.0,    0.0, -1.0),   0.5, material_left));
//    world.add(make_shared<sphere>(point3( 1.0,    0.0, -1.0),   0.5, material_right));
//
//    world.add(make_shared<sphere>(point3(0,0,-1), 0.5));
//    world.add(make_shared<sphere>(point3(0,-100.5,-1), 100));

    camera cam;

    cam.aspect_ratio      = 16.0 / 9.0;
    cam.image_width       = 1200;
    cam.samples_per_pixel = 10;
    cam.max_depth         = 50;

    cam.vfov     = 20;
    cam.lookfrom = point3(13,2,3);
    cam.lookat   = point3(0,0,0);
    cam.vup      = vec3(0,1,0);

    cam.defocus_angle = 0.6;
    cam.focus_dist    = 10.0;

    cam.render(world);
}




//#include <iostream>
//#include <GLFW/glfw3.h>
//#include "imgui-docking/imgui.h"
//#include "imgui-docking/backends/imgui_impl_glfw.h"
//#include "imgui-docking/backends/imgui_impl_opengl3.h"
//
//int main() {
//    // Initialize GLFW
//    if (!glfwInit()) {
//        return -1;
//    }
//
//
//    // Create a GLFW window
//    GLFWwindow *window = glfwCreateWindow(800, 600, "ImGui Example", nullptr, nullptr);
//    if (!window) {
//        glfwTerminate();
//        return -1;
//    }
//
//    glfwMakeContextCurrent(window);
//
//    // Initialize ImGui
//    IMGUI_CHECKVERSION();
//    ImGui::CreateContext();
//    ImGuiIO& io = ImGui::GetIO(); (void)io;
//    ImGui::StyleColorsDark();
//    ImGui_ImplGlfw_InitForOpenGL(window, true);
//    ImGui_ImplOpenGL3_Init("#version 130");
//
//    // Main loop
//    while (!glfwWindowShouldClose(window)) {
//        glfwPollEvents();
//
//        ImGui_ImplOpenGL3_NewFrame();
//        ImGui_ImplGlfw_NewFrame();
//        ImGui::NewFrame();
//
//        // Your ImGui code here
//        ImGui::Begin("Hello, world!");
//        ImGui::Text("This is a simple ImGui application.");
//        ImGui::End();
//
//        ImGui::Render();
//        int display_w, display_h;
//        glfwGetFramebufferSize(window, &display_w, &display_h);
//        glViewport(0, 0, display_w, display_h);
//        glClearColor(0.45f, 0.55f, 0.60f, 1.00f);
//        glClear(GL_COLOR_BUFFER_BIT);
//        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
//
//        glfwSwapBuffers(window);
//    }
//
//    // Cleanup
//    ImGui_ImplOpenGL3_Shutdown();
//    ImGui_ImplGlfw_Shutdown();
//    ImGui::DestroyContext();
//
//    glfwDestroyWindow(window);
//    glfwTerminate();
//
//    return 0;
//}
