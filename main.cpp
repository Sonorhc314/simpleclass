#include <iostream>
#include <math.h>

using namespace std;

class Vector3D
{
    private:
        float x;
        float y;
        float z;
    public:

        Vector3D() :x(0), y(0), z(0)
        {
            //by default
        }
        Vector3D(const Vector3D& other) : x(other.x), y(other.y), z(other.z)
        {
            //copying
        }
        Vector3D(float dop1, float dop2, float dop3) : x(dop1), y(dop2), z(dop3)
        {
            //initializing
        }
        void showVector()
        {
            cout << x << ":" << y << ":" << z << "";
        }
        void showProizVector()
        {
            cout << x + y + z << "";
        }
        //перегрузка оператора присваивания
        Vector3D& operator= (const Vector3D &vector3D)
        {
             // Выполняем копирование значений
             x = vector3D.x;
             y = vector3D.y;
             z = vector3D.z;
             // Возвращаем текущий объект, чтобы иметь возможность связать в цепочку выполнение нескольких операций присваивания
             return *this;
        }

        float operator[](int s)
        {
            if(s==0)
            {
                return x;
            }
            else if(s==1)
            {
                return y;
            }
            else if(s==2)
            {
                return z;
            }
        }

        float norma;
        Vector3D operator+(Vector3D)const;
        Vector3D operator-(Vector3D)const;
        Vector3D operator%(Vector3D)const;
        Vector3D operator*(Vector3D)const;
        Vector3D operator/(float)const;
        Vector3D scaleVectorMN(float dop);
        Vector3D scaleVectorDIL(float dop);
        Vector3D mirrorVector();
        float normaVector();
};
//Сложение
Vector3D Vector3D :: operator+ (Vector3D d2)const
{
        float vx = x + d2.x;
        float vy = y + d2.y;
        float vz = z + d2.z;
        return Vector3D(vx,vy,vz);
}
//Сложение
Vector3D Vector3D :: operator- (Vector3D d2)const
{
        float vx = x - d2.x;
        float vy = y - d2.y;
        float vz = z - d2.z;
        return Vector3D(vx,vy,vz);
}
//Векторное произведение
Vector3D Vector3D :: operator* (Vector3D d2)const
{
        float vx = y*d2.z-z*d2.y;
        float vy = z*d2.x-x*d2.z;
        float vz = x*d2.y - y*d2.x;
        return Vector3D(vx,vy,vz);
}
//Скалярное произведение
Vector3D Vector3D :: operator% (Vector3D d2)const
{
        float vx = x*d2.x;
        float vy = y*d2.y;
        float vz = z*d2.z;
        return Vector3D((vx+vy+vz),vx*0,vy*0);
}
//масштабирование умножением
Vector3D Vector3D::scaleVectorMN(float dop)
{
    x = x*dop;
    y = y*dop;
    z = z*dop;
    return Vector3D(x, y, z);
}
//масштабирование делением
Vector3D Vector3D::scaleVectorDIL(float dop)
{
    x = x/dop;
    y = y/dop;
    z = z/dop;
    return Vector3D(x, y, z);
}
//зеркальный вектор
Vector3D Vector3D::mirrorVector()
{
    x = -x;
    y = -y;
    z = -z;
    return Vector3D(x, y, z);
}
//норма
float Vector3D::normaVector()
{
    float norma = sqrt(x*x+y*y+z*z);
    return norma;
}
//normalization
Vector3D Vector3D::operator/(float norma)const
{
    float vx = x/norma;
    float vy = y/norma;
    float vz = z/norma;
    return Vector3D(vx, vy, vz);
}

int main()
{
    float x, y, z, i, j, k;
    float norma;
    x = 3;
    y = 4;
    z = 9;
    i = 2;
    j = 1;
    k = 8;
    Vector3D a, b, c, d, e, f, g;
    a = Vector3D(x, y, z);
    b = Vector3D(i,j,k);
    c = a+b;
    d = a-b;
    e = a%b;
    f = a*b;
    cout<<"Сложение a(";a.showVector();cout<<") + b(";b.showVector();cout<<") = c(";c.showVector();cout<<")"<<endl;
    cout<<"Вычитание a(";a.showVector();cout<<") - b(";b.showVector();cout<<") = d(";d.showVector();cout<<")"<<endl;
    cout<<"Векторное произведение a(";a.showVector();cout<<") * b(";b.showVector();cout<<") = f(";f.showVector();cout<<")"<<endl;
    cout<<"Скалярное произведение a(";a.showVector();cout<<") % b(";b.showVector();cout<<") = ";e.showProizVector();cout<<endl;

    cout<<"Масштабирование a(";a.showVector();cout<<")";cout<<" умножением на 2 ";
    a.scaleVectorMN(2);
    cout<<"a(";a.showVector();cout<<")"<<endl;
    cout<<"Масштабирование a(";a.showVector();cout<<")";cout<<" делением на 2 ";
    a.scaleVectorDIL(2);
    cout<<"a(";a.showVector();cout<<")"<<endl;
    cout<<"Отражение вектора a(";a.showVector();cout<<")";
    a.mirrorVector();
    cout<<" = a(";a.showVector();cout<<")"<<endl;
    cout<<"Норма вектора а(";a.showVector();cout<<")";
    norma=a.normaVector();
    g=a/norma;
    cout<<" = a ||";cout<<norma;cout<<"||"<<endl;
    cout<<"Нормализация вектора a(";a.showVector();cout<<") = g(";g.showVector();cout<<")"<<endl;

    cout<<"Доступ к a[0] = ";cout<<a[0]<<endl;

    cout<<"Доступ к a[1] = ";cout<<a[1]<<endl;
    cout<<"Доступ к a[2] = ";cout<<a[2]<<endl;

    return 0;
}
