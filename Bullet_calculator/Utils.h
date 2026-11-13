#pragma once

#include <initializer_list>
#include <cmath>
#include <stdexcept>

/**
 * @brief Пространство имён математических операций и объектов
 * 
 */
namespace maths
{
/**
 * @brief математический вектор из 3-х координат
 * 
 */
class vec3
{
public:
    double x, y, z;

    /**
     * @brief Создаёт объект типа vec3
     *  
     * @param elements перечисление компонент x, y, z
     */
    vec3(std::initializer_list<double> elements);

    /**
     * @brief Создаёт объект типа vec3 со значениями 0, 0, 0
     * 
     */
    vec3();

    /**
     * @brief Создаёт объект типа vec3 со значениями other вектора
     * 
     * @param другой вектор
     */
    vec3(const vec3& other);

    vec3& operator=(const vec3& other);

    /**
     * @brief Сложение двух векторов
     * 
     * @param lhs первое слагаемое
     * @param rhs второе слагаемое
     * @return vec3 сумма двух векторов - новый вектор
     */
    friend vec3 operator+(vec3 lhs, const vec3& rhs);

    /**
     * @brief Разность двух векторов
     * 
     * @param lhs
     * @param rhs
     * @return vec3 разность двух векторов - новый вектор
     */
    friend vec3 operator-(vec3 lhs, const vec3& rhs);

    /**
     * @brief Скалярное произведение двух векторов
     * 
     * @param lhs
     * @param rhs
     * @return vec3 скалярное произведение двух векторов - новый вектор
     */
    friend double operator*(const vec3& lhs, const vec3& rhs);

    /**
     * @brief Умножение вектора на число number
     * 
     * @param vec вектор
     * @param number число
     * @return vec3
     */
    friend vec3 operator*(vec3 vec, double number);
    
    vec3& operator+=(const vec3& rhs);
    vec3& operator-=(const vec3& rhs);
    vec3& operator*=(double number);
};

vec3 operator+(vec3 lhs, const vec3& rhs);
vec3 operator-(vec3 lhs, const vec3& rhs);
double operator*(const vec3& lhs, const vec3& rhs);
vec3 operator*(vec3 vec, double number);

/**
 * @brief Вычисление модуля вектора
 * 
 * @param vec 
 * @return длина вектора 
 */
double length(const vec3& vec);
}