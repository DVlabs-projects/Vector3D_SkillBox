#include <iostream>
#include <memory>
#include "Vector3D.h"

void normalizeVector(std::shared_ptr<Vector3D> vec) {
    vec->normalize();
}

int main() {
    // Тестирование конструктора перемещения
    Vector3D v1(1, 2, 3);
    Vector3D v2(std::move(v1));
    std::cout << "v2 after move: " << v2[0] << ", " << v2[1] << ", " << v2[2] << "\n";

    // Тестирование перемещающего присваивания
    Vector3D v3;
    v3 = Vector3D(4, 5, 6);
    std::cout << "v3 after move assignment: " << v3[0] << ", " << v3[1] << ", " << v3[2] << "\n";

    // Использование unique_ptr
    auto vecPtr = std::make_unique<Vector3D>(7, 8, 9);
    std::cout << "Original vector: " << (*vecPtr)[0] << ", " << (*vecPtr)[1] << ", " << (*vecPtr)[2] << "\n";

    std::unique_ptr<Vector3D> movedPtr = std::move(vecPtr);
    if (!vecPtr) {
        std::cout << "vecPtr is null after move\n";
    }

    // Использование shared_ptr
    auto sharedVec = std::make_shared<Vector3D>(1, 2, 3);
    std::cout << "Length before normalize: " << sharedVec->length() << "\n";
    normalizeVector(sharedVec);
    std::cout << "Normalized vector: " << (*sharedVec)[0] << ", " << (*sharedVec)[1] << ", " << (*sharedVec)[2] << "\n";

    return 0;
}