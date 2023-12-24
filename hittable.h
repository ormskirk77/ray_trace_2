//
// Created by tim on 22/12/23.
//

#ifndef RAY_TRACE_2_HITTABLE_H
#define RAY_TRACE_2_HITTABLE_H



#include "ray.h"
#include "hit_record.h"



class hittable {
public:
    virtual ~hittable() = default;

  //  virtual bool hit(const ray& r, double ray_tmin, double ray_tmax, hit_record& rec) const = 0;
    virtual bool hit(const ray& r, interval ray_t, hit_record& rec) const = 0;
};


#endif //RAY_TRACE_2_HITTABLE_H
