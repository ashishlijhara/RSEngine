#ifndef _RSAPPLICATIONLAYER_H_
#define _RSAPPLICATIONLAYER_H_

#include "IGameLayer.h"
#include "RSDefs.h"
#include "RSUncopyable.h"


namespace RSE{

	class RSOgreHandler;

	class RSApplicationLayer: Uncopyable, public IGameLayer{
	public:
		RSApplicationLayer(){}
		virtual ~RSApplicationLayer(){}

		FResult VInit();

		
		FResult VUpdate(const float &delTime);

		
		FResult VShutdown();

	private:
		RSOgreHandler *m_pRSOgreHandler;
	};
}

#endif 