#define BIORBD_API_EXPORTS
#include "Muscles/WrappingSphere.h"

#include "Utils/String.h"
#include "Utils/RotoTrans.h"

biorbd::muscles::WrappingSphere::WrappingSphere() :
    biorbd::muscles::WrappingObject (),
    m_dia(std::make_shared<double>(0))
{
    *m_typeOfNode = "WrappingSphere";
}

biorbd::muscles::WrappingSphere::WrappingSphere(
        double x,
        double y,
        double z,
        double diameter) :
    biorbd::muscles::WrappingObject (x, y, z),
    m_dia(std::make_shared<double>(diameter))

{
    *m_typeOfNode = "WrappingSphere";
}

biorbd::muscles::WrappingSphere::WrappingSphere(
        double x,
        double y,
        double z,
        double diameter,
        const biorbd::utils::String &name,
        const biorbd::utils::String &parentName) :
    biorbd::muscles::WrappingObject (x, y, z, name, parentName),
    m_dia(std::make_shared<double>(diameter))
{
    *m_typeOfNode = "WrappingSphere";
}

biorbd::muscles::WrappingSphere::WrappingSphere(
        const biorbd::utils::Node3d &v,
        double diameter) :
    biorbd::muscles::WrappingObject(v),
    m_dia(std::make_shared<double>(diameter))
{
    *m_typeOfNode = "WrappingSphere";
}

const biorbd::utils::RotoTrans& biorbd::muscles::WrappingSphere::RT(
        biorbd::rigidbody::Joints &,
        const biorbd::rigidbody::GeneralizedCoordinates &,
        bool )
{
    return *m_RT;
}

double biorbd::muscles::WrappingSphere::size() const
{
    return *m_dia;
}

void biorbd::muscles::WrappingSphere::setSize(double val)
{
    *m_dia = val;
}
