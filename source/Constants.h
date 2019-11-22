#pragma once

#include "pluginterfaces/base/ftypes.h"

#define VERSION "0.0.0.1"
#define PLUGIN_NAME "Wavelet"
#define COMPANY_NAME "Atome.io"
#define COMPANY_URL "https://atome.io"
#define COMPANY_EMAIL "contact@atome.io"

namespace io::atome::wavelet {
	static const Steinberg::FUID ProcessorUID(0x1E4DC62B, 0x974147D6, 0x9CAB1B86, 0x50D4B11D);
	static const Steinberg::FUID ControllerUID(0xA8D238C1, 0x97F54908, 0xB32EB808, 0x3EA43CED);
} // namespace