/*
 * tool_force_to_joint_torques.h
 *
 *  Created on: Jan 18, 2010
 *      Author: dc
 */

#ifndef BARRETT_SYSTEMS_TOOL_FORCE_TO_JOINT_TORQUES_H_
#define BARRETT_SYSTEMS_TOOL_FORCE_TO_JOINT_TORQUES_H_


#include <gsl/gsl_blas.h>

#include <barrett/detail/ca_macro.h>
#include <barrett/units.h>
#include <barrett/math/kinematics.h>
#include <barrett/systems/abstract/single_io.h>
#include <barrett/systems/kinematics_base.h>


namespace barrett {
namespace systems {


template<size_t DOF>
class ToolForceToJointTorques : public SingleIO<units::CartesianForce::type, typename units::JointTorques<DOF>::type>, public KinematicsInput<DOF> {
public:
	ToolForceToJointTorques() :
		SingleIO<units::CartesianForce::type, typename units::JointTorques<DOF>::type>(), KinematicsInput<DOF>(this) {}
	virtual ~ToolForceToJointTorques() {}

protected:
	virtual void operate() {
		typename units::JointTorques<DOF>::type jt;

		// Multiply by the Jacobian-transpose at the tool
		gsl_blas_dgemv(CblasTrans, 1.0, this->kinInput.getValue()->impl->tool_jacobian_linear,
					this->input.getValue().asGslType(), 1.0, jt.asGslType());

		this->outputValue->setValue(jt);
	}

private:
	DISALLOW_COPY_AND_ASSIGN(ToolForceToJointTorques);
};


}
}


#endif /* BARRETT_SYSTEMS_TOOL_FORCE_TO_JOINT_TORQUES_H_ */