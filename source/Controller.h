#pragma once

#include "public.sdk/source/vst/vsteditcontroller.h"
#include "pluginterfaces/vst/ivstnoteexpression.h"
#include "pluginterfaces/vst/vsttypes.h"
#include "base/source/fobject.h"

using namespace Steinberg;
using namespace Steinberg::Vst;

namespace io::atome::wavelet {
	class Controller : public IEditController
	{
	public:
		static inline Steinberg::FClassID getFClassID() {
			return ("Controller");
		}

		static FUnknown* createInstance(void* context)
		{
			return (IEditController*) new Controller;
		}

		Controller();
		~Controller();

		tresult PLUGIN_API queryInterface(const TUID _iid, void** obj) SMTG_OVERRIDE;
		virtual uint32 PLUGIN_API addRef() SMTG_OVERRIDE;
		virtual uint32 PLUGIN_API release() SMTG_OVERRIDE;
		virtual Steinberg::FClassID isA() const;
		tresult PLUGIN_API initialize(FUnknown* context) SMTG_OVERRIDE;
		tresult PLUGIN_API terminate() SMTG_OVERRIDE;
		tresult PLUGIN_API setComponentState(IBStream* state) SMTG_OVERRIDE;
		tresult PLUGIN_API setState(IBStream* state) SMTG_OVERRIDE;
		tresult PLUGIN_API getState(IBStream* state) SMTG_OVERRIDE;
		int32 PLUGIN_API getParameterCount() SMTG_OVERRIDE;
		tresult PLUGIN_API getParameterInfo(int32 paramIndex, ParameterInfo& info /*out*/) SMTG_OVERRIDE;
		tresult PLUGIN_API getParamStringByValue(ParamID id, ParamValue valueNormalized /*in*/, String128 string /*out*/) SMTG_OVERRIDE;
		tresult PLUGIN_API getParamValueByString(ParamID id, TChar* string /*in*/, ParamValue& valueNormalized /*out*/) SMTG_OVERRIDE;
		ParamValue PLUGIN_API normalizedParamToPlain(ParamID id, ParamValue valueNormalized) SMTG_OVERRIDE;
		ParamValue PLUGIN_API plainParamToNormalized(ParamID id, ParamValue plainValue) SMTG_OVERRIDE;
		ParamValue PLUGIN_API getParamNormalized(ParamID id) SMTG_OVERRIDE;
		tresult PLUGIN_API setParamNormalized(ParamID id, ParamValue value) SMTG_OVERRIDE;
		tresult PLUGIN_API setComponentHandler(IComponentHandler* handler) SMTG_OVERRIDE;
		IPlugView* PLUGIN_API createView(FIDString name) SMTG_OVERRIDE;

		private:
			uint32 nbRef_;
			IPlugView* view_;

			ParameterContainer parameters_;
	};
} // namespace
