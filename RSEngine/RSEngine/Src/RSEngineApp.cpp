#include "RSEngineApp.h"
#include "RSOgreHandler.h"

namespace RSE{
	const FResult RSEngineApp::VInit(){
		FResult returnResult;
		memset(&returnResult,0,sizeof(FResult));

		new RSOgreHandler();
		m_pRSOgreHandler = RSOgreHandler::getSingletonPtr();
		returnResult = m_pRSOgreHandler->VInitOgre();
		//if(returnResult.m_Result==ORESULT_ERROR) return returnResult;

		return returnResult;
	}

		
	const FResult RSEngineApp::VUpdate(const float &delTime){
		FResult returnResult;
		memset(&returnResult,0,sizeof(FResult));

		assert(m_pRSOgreHandler);
		returnResult = m_pRSOgreHandler->VUpdateOgre(delTime);
		//if(returnResult.m_Result==ORESULT_ERROR) return returnResult;

		return returnResult;
	}

	const FResult RSEngineApp::VPause(const bool &pause){
		FResult returnResult;
		memset(&returnResult,0,sizeof(FResult));

		assert(m_pRSOgreHandler);
		returnResult = m_pRSOgreHandler->VPauseOgre(pause);

		return returnResult;
	}

	const FResult RSEngineApp::VEnd(){
		FResult returnResult;
		memset(&returnResult,0,sizeof(FResult));

		assert(m_pRSOgreHandler);
		returnResult = m_pRSOgreHandler->VEndOgre();

		return returnResult;
	}

	const FResult RSEngineApp::VCleanup(){
		FResult returnResult;
		memset(&returnResult,0,sizeof(FResult));

		assert(m_pRSOgreHandler);
		m_pRSOgreHandler->VCleanupOgre();

		if(!Release(m_pRSOgreHandler)){
			assert(m_pRSOgreHandler);
			SetError(&returnResult, "Unable to release Base Game App Object");
		}
		return returnResult;
	}
}