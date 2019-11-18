#include "Controller.h"
#include "Application.h"
#include "View.h"
#include "Constants.h"

#include "pluginterfaces/base/ustring.h"
#include "pluginterfaces/base/ibstream.h"
#include "base/source/fstreamer.h"
#include "FrequencyParameter.h"

namespace io::atome::wavelet {
	Controller::Controller() : 
		nbRef_(0),
		view_(nullptr)
	{
	}

	Controller::~Controller() {
		if (view_ != nullptr) {
			delete view_;
		}
	}

	tresult PLUGIN_API Controller::queryInterface(const TUID _iid, void** obj) {
		if (::Steinberg::FUnknownPrivate::iidEqual(_iid, iid)) {
			addRef();
			*obj = static_cast<IEditController*>(this);
			return ::Steinberg::kResultOk;
		}
		return kResultFalse;
	}

	uint32 PLUGIN_API Controller::addRef() {
		return ++nbRef_;
	}

	uint32 PLUGIN_API Controller::release() {
		return --nbRef_;
	}

	Steinberg::FClassID Controller::isA() const {
		return Controller::getFClassID();
	}

	tresult PLUGIN_API Controller::initialize(FUnknown* context)
	{
		//FrequencyParameter* frequencyParam = new FrequencyParameter(ParameterInfo::kCanAutomate, kFrequencyId);
		//parameters_.addParameter(frequencyParam);

		return kResultOk;
	}

	tresult PLUGIN_API Controller::terminate()
	{
		return kResultOk;
	}

	tresult PLUGIN_API Controller::setComponentState(IBStream* state)
	{
		//return kNotImplemented;
		return kResultOk;
	}

	tresult PLUGIN_API Controller::setState(IBStream* state)
	{
		//return kNotImplemented;
		return kResultOk;
	}

	tresult PLUGIN_API Controller::getState(IBStream* state)
	{
		//return kNotImplemented;
		return kResultOk;
	}

	int32 PLUGIN_API Controller::getParameterCount()
	{
		return 0;
	}

	tresult PLUGIN_API Controller::getParameterInfo(int32 paramIndex, ParameterInfo& info /*out*/)
	{
		//info = parameters_.getParameterByIndex(paramIndex)->getInfo();
		return kResultOk;
	}

	tresult PLUGIN_API Controller::getParamStringByValue(ParamID id, ParamValue valueNormalized /*in*/, String128 string /*out*/)
	{
		//Parameter* parameter = parameters_.getParameter(id);
		//parameter->toString(valueNormalized, string);
		return kResultOk;
	}

	tresult PLUGIN_API Controller::getParamValueByString(ParamID id, TChar* string /*in*/, ParamValue& valueNormalized /*out*/)
	{
		//Parameter* parameter = parameters_.getParameter(id);
		//parameter->fromString(string, valueNormalized);
		return kResultOk;
	}

	ParamValue PLUGIN_API Controller::normalizedParamToPlain(ParamID id, ParamValue valueNormalized)
	{
		//Parameter* parameter = parameters_.getParameter(id);
		//return parameter->toPlain(valueNormalized);
		return kResultOk;
	}

	ParamValue PLUGIN_API Controller::plainParamToNormalized(ParamID id, ParamValue plainValue)
	{
		//Parameter* parameter = parameters_.getParameter(id);
		//return parameter->toNormalized(plainValue);
		return kResultOk;
	}

	ParamValue PLUGIN_API Controller::getParamNormalized(ParamID id)
	{
		//Parameter* parameter = parameters_.getParameter(id);
		//return parameter->getNormalized();
		return kResultOk;
	}

	tresult PLUGIN_API Controller::setParamNormalized(ParamID id, ParamValue value)
	{
		//Parameter* parameter = parameters_.getParameter(id);
		//return parameter->setNormalized(value);
		return kResultOk;
	}

	tresult PLUGIN_API Controller::setComponentHandler(IComponentHandler* handler)
	{
		//return kNotImplemented;
		return kResultOk;
	}

	IPlugView* PLUGIN_API Controller::createView(FIDString name)
	{
		view_ = new View();
		return view_;
	}
} // namespace
