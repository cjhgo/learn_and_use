#include <iostream>
#include <vector>
#include <Eigen/Dense>

using Eigen::MatrixXi;
typedef Eigen::Matrix< int , 10, 1> Vector_type;

int main(int argc, char const *argv[])
{
    MatrixXi m(2,2);
    m(0,0)=3;
    m(1,0)=2.5;
    m(0,1)=1;
    m(1,1)=m(1,0)+m(0,1);
    std::cout<<m<<std::endl<<std::endl;
    Vector_type w,x;
    Eigen::Vector4d a(1,2,3,4), b(1,1,1,1);
    std::cout<<a.dot(b)<<std::endl;
    w=Eigen::MatrixXi::Constant(10,1,2);
    x=Eigen::MatrixXi::Constant(10,1,1);
    std::cout<<w.transpose()<<std::endl<<std::endl;
    std::cout<<x.transpose()<<std::endl<<std::endl;
    std::cout<<w.dot(x)<<std::endl<<std::endl;
    std::cout<<w[0]<<std::endl;
    a<<1,2,3,4;
    return 0;
}