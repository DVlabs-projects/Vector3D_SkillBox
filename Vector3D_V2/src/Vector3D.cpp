#include "Vector3D.h"

Vector3D::Vector3D() : coords(std::make_unique<double[]>(3)) {
    coords[0] = 0.0;
    coords[1] = 0.0;
    coords[2] = 0.0;
}

Vector3D::Vector3D(double x, double y, double z) : coords(std::make_unique<double[]>(3)) {
    coords[0] = x;
    coords[1] = y;
    coords[2] = z;
}

Vector3D::Vector3D(const Vector3D& other) : coords(std::make_unique<double[]>(3)) {
    coords[0] = other.coords[0];
    coords[1] = other.coords[1];
    coords[2] = other.coords[2];
}

Vector3D& Vector3D::operator=(const Vector3D& other) {
    if (this != &other) {
        coords[0] = other.coords[0];
        coords[1] = other.coords[1];
        coords[2] = other.coords[2];
    }
    return *this;
}

Vector3D::Vector3D(Vector3D&& other) noexcept 
    : coords(std::move(other.coords)) {}

Vector3D& Vector3D::operator=(Vector3D&& other) noexcept {
    if (this != &other) {
        coords = std::move(other.coords);
    }
    return *this;
}

double Vector3D::operator[](size_t index) const {
    return coords[index];
}

double& Vector3D::operator[](size_t index) {
    return coords[index];
}

double Vector3D::length() const {
    return std::sqrt(coords[0]*coords[0] + coords[1]*coords[1] + coords[2]*coords[2]);
}

void Vector3D::normalize() {
    double len = length();
    if (len != 0) {
        coords[0] /= len;
        coords[1] /= len;
        coords[2] /= len;
    }
}