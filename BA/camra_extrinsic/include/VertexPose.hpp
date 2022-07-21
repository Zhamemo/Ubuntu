

#pragma once

#include <iostream>
#include <sophus/se3.hpp>
#include <g2o/core/base_vertex.h>

//对于用g2o来进行优化的话，首先要定义顶点和边的模板
//顶点，也就是咱们要优化的pose 用李代数表示它 6维
class VertexPose : public g2o::BaseVertex<6, Sophus::SE3d>
{
public:
    EIGEN_MAKE_ALIGNED_OPERATOR_NEW; // 表示在利用Eigen库的数据结构时new的时候 需要对齐，所以加入EIGEN特有的宏定义即可实现

    virtual void setToOriginImpl() override; // 输入优化变量初始值

    virtual void oplusImpl(const double *update) override; // 顶点的更新函数

    // 存盘和读盘：留空
    virtual bool read(std::istream &in) override;

    virtual bool write(std::ostream &out) const override;
};