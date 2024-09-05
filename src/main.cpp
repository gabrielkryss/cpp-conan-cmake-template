/*import std.core;*/
import MyClass;

/*#include <vulkan/vulkan.h>*/
#include <spdlog/spdlog.h>
#include <entt/entt.hpp>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

/*#include <iostream>*/
import std;

struct Position {
    float x;
    float y;
};

struct Velocity {
    float dx;
    float dy;
};

int main() {
    std::print("Hello, World!\n");

    #ifdef NDEBUG
    printf("Release configuration!\n");
    #else
    printf("Debug configuration!\n");
    #endif

    MyClass myClass;
    myClass.sayHello();

    // spdlog example
    spdlog::info("This is an info message from spdlog.");
    spdlog::warn("This is a warning message from spdlog.");
    spdlog::error("This is an error message from spdlog.");
    spdlog::debug("This is a debug message from spdlog.");
    spdlog::critical("This is a critical message from spdlog.");

    // glm example
    // Create two vectors
    glm::vec3 vec1(1.0f, 2.0f, 3.0f);
    glm::vec3 vec2(4.0f, 5.0f, 6.0f);

    // Vector addition
    glm::vec3 vecSum = vec1 + vec2;
    std::print("Vector Sum: ({}, {}, {})\n", vecSum.x, vecSum.y, vecSum.z);

    // Vector dot product
    float dotProduct = glm::dot(vec1, vec2);
    std::print("Dot Product: {}\n", dotProduct);

    // Vector cross product
    glm::vec3 crossProduct = glm::cross(vec1, vec2);
    std::print("Cross Product: ({}, {}, {})\n", crossProduct.x, crossProduct.y, crossProduct.z);

    // Matrix transformation
    glm::mat4 transform = glm::mat4(1.0f);
    transform = glm::translate(transform, glm::vec3(1.0f, 1.0f, 1.0f));
    glm::vec4 transformedVec = transform * glm::vec4(vec1, 1.0f);
    std::print("Transformed Vector: ({}, {}, {})\n", transformedVec.x, transformedVec.y, transformedVec.z);

    // entt example
    entt::registry registry;
    auto entity = registry.create();
    registry.emplace<Position>(entity, 0.0f, 0.0f);
    registry.emplace<Velocity>(entity, 1.0f, 1.0f);
    auto &pos = registry.get<Position>(entity);
    auto &vel = registry.get<Velocity>(entity);
    pos.x += vel.dx;
    pos.y += vel.dy;
    std::print("Updated Position: ({}, {})\n", pos.x, pos.y);

    return 0;
}
