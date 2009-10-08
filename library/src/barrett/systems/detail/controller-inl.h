/*
 * controller-inl.h
 *
 *  Created on: Oct 6, 2009
 *      Author: dc
 */


namespace Systems {


template<typename InputType, typename OutputType>
inline System::Input<InputType>*
Controller<InputType, OutputType>::getReferenceInput()
{
	return &referenceInput;
}

template<typename InputType, typename OutputType>
inline System::Input<InputType>*
Controller<InputType, OutputType>::getFeedbackInput()
{
	return &feedbackInput;
}

template<typename InputType, typename OutputType>
void Controller<InputType, OutputType>::operate()
{
	// TODO(dc): stub
}


}
