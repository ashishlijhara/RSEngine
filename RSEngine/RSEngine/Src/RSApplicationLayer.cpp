#include "RSApplicationLayer.h"
#include "RSOgreHandler.h"

namespace RSE{

	FResult RSApplicationLayer::VInit(){
		FResult returnResult;
		memset(&returnResult,0, sizeof(FResult));

		new RSOgreHandler();
		m_pRSOgreHandler = RSOgreHandler::getSingletonPtr();
		returnResult = m_pRSOgreHandler->VInitOgre();

		return returnResult;
	}

	FResult RSApplicationLayer::VUpdate(const float &delTime){
		FResult returnResult;
		memset(&returnResult,0, sizeof(FResult));

		assert(m_pRSOgreHandler);
		returnResult = m_pRSOgreHandler->VUpdateOgre(delTime);
		//assert(m_pRSOgreHandler);
		//returnResult = m_pRSOgreHandler->VPauseOgre(pause);
		return returnResult;
	}

	FResult RSApplicationLayer::VShutdown(){
		FResult returnResult;
		memset(&returnResult,0, sizeof(FResult));

		assert(m_pRSOgreHandler);
		returnResult = m_pRSOgreHandler->VEndOgre();

		m_pRSOgreHandler->VCleanupOgre();

		if(!Release(m_pRSOgreHandler)){
			assert(m_pRSOgreHandler);
			SetError(&returnResult, "Unable to release Base Game App Object");
		}

		return returnResult;
	}

}