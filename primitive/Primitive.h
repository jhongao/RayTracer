//
// Created by 诸谦 on 15/12/28.
//

#ifndef RAYTRACER_PRIMITIVE_H
#define RAYTRACER_PRIMITIVE_H


#include "../base/Vector3.h"
#include "../material/Material.h"
#include "../material/Matte.h"
#include <memory>
using namespace std;

class Primitive {
protected:
    Vector3 mPosition;//图元位置
    Material* mMaterial;//图元使用的材质
    bool mShadow;//是否投射阴影
public:

    Primitive(const Vector3 &mPosition=Vector3(0,0,0), Material *mMaterial=NULL, bool mShadow=true) ;

    void setMaterial(Material* material);
    /*返回交点处的法线 要求标准化后*/
    virtual Vector3 getNormal(const Vector3& point) const=0;

    /*判断与法线的碰撞*/
    virtual bool hit(const Ray& ray,double& distance,ShadeRec& sr)=0;
    virtual bool shadowHit(const Ray& ray,double& distance) const=0;

    bool castShadow() const;
    void setCastShadow(bool s);

    const static double EPSILON;
};


#endif //RAYTRACER_PRIMITIVE_H