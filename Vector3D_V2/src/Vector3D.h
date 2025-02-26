#ifndef VECTOR3D_H
#define VECTOR3D_H

#include <memory>
#include <cmath>

class Vector3D {
public:
    Vector3D();
    Vector3D(double x, double y, double z);
    Vector3D(const Vector3D& other);
    Vector3D& operator=(const Vector3D& other);
    Vector3D(Vector3D&& other) noexcept;
    Vector3D& operator=(Vector3D&& other) noexcept;
    ~Vector3D() = default;

    double operator[](size_t index) const;
    double& operator[](size_t index);
    void normalize();
    double length() const;

private:
    std::unique_ptr<double[]> coords;
};

#endif // VECTOR3D_H