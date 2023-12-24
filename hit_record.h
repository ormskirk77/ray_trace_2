//
// Created by tim on 22/12/23.
//

#ifndef RAY_TRACE_2_HIT_RECORD_H
#define RAY_TRACE_2_HIT_RECORD_H
#include "vec3.h"
#include "ray.h"
#include "rtweekend.h"

class material;

class hit_record {
public:
    point3 p;
    vec3 normal;
    shared_ptr<material> mat;
    double t;
    bool front_face;

    void set_face_normal(const ray& r, const vec3& outward_normal) {
        // Sets the hit record normal vector.
        // NOTE: the parameter `outward_normal` is assumed to have unit length.

        front_face = dot(r.direction(), outward_normal) < 0;
        normal = front_face ? outward_normal : -outward_normal;
    }
};
//class hit_record {
//public:
//    point3 p;
//    vec3 normal;
//    double t;
//    bool front_face;
//
//    void set_face_normal(const ray& r, const vec3& outward_normal) {
//        // Sets the hit record normal vector.
//        // NOTE: the parameter `outward_normal` is assumed to have unit length.
//
//        front_face = dot(r.direction(), outward_normal) < 0;
//        normal = front_face ? outward_normal : -outward_normal;
//    }
//
//
//
//};


#endif //RAY_TRACE_2_HIT_RECORD_H
