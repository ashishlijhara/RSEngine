#ifndef _RSGAMELOGICLAYER_H_
#define _RSGAMELOGICLAYER_H_

#include "IGameLayer.h"
#include "RSDefs.h"

namespace RSE{
	class RSGameLogicLayer: private Uncopyable, public IGameLayer{
	public:

		RSGameLogicLayer(){}

		virtual ~RSGameLogicLayer(){}

		FResult VInit();

		
		FResult VUpdate(const float &delTime);

		
		FResult VShutdown();
	};
}

#endif