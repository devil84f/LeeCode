#include <iostream>
#include <cmath> // 用于sin/cos函数

class Matrix {
    float data[4][4]; // 4x4矩阵，用于2D/3D变换
    
public:
    // 构造函数 - 初始化为单位矩阵
    Matrix() {
        for (int i = 0; i < 4; ++i) {
            for (int j = 0; j < 4; ++j) {
                data[i][j] = (i == j) ? 1.0f : 0.0f;
            }
        }
    }
    
    // 打印矩阵内容
    void print() const {
        for (int i = 0; i < 4; ++i) {
            for (int j = 0; j < 4; ++j) {
                std::cout << data[i][j] << " ";
            }
            std::cout << "\n";
        }
    }
    
    // 矩阵乘法(用于组合变换)
    Matrix& multiply(const Matrix& other) {
        Matrix result;
        for (int i = 0; i < 4; ++i) {
            for (int j = 0; j < 4; ++j) {
                result.data[i][j] = 0;
                for (int k = 0; k < 4; ++k) {
                    result.data[i][j] += data[i][k] * other.data[k][j];
                }
            }
        }
        *this = result;
        return *this;
    }

    // 旋转变换(返回引用以支持链式调用)
    Matrix& rotate(float degrees) {
        Matrix rotation;
        float radians = degrees * M_PI / 180.0f;
        float c = cos(radians);
        float s = sin(radians);
        
        rotation.data[0][0] = c;
        rotation.data[0][1] = -s;
        rotation.data[1][0] = s;
        rotation.data[1][1] = c;
        
        return multiply(rotation); // 组合变换并返回自身引用
    }
    
    // 缩放变换
    Matrix& scale(float factor) {
        return scale(factor, factor, factor);
    }
    
    Matrix& scale(float x, float y, float z = 1.0f) {
        Matrix scaling;
        scaling.data[0][0] = x;
        scaling.data[1][1] = y;
        scaling.data[2][2] = z;
        
        return multiply(scaling);
    }
    
    // 平移变换
    Matrix& translate(float x, float y, float z = 0.0f) {
        Matrix translation;
        translation.data[0][3] = x;
        translation.data[1][3] = y;
        translation.data[2][3] = z;
        
        return multiply(translation);
    }
};

int main() {
    Matrix m;
    m.print();
    
    // 链式调用
    m.rotate(45).scale(2.0).translate(10, 20);
    
    std::cout << "Final transformation matrix:\n";
    m.print();
    
    return 0;
}