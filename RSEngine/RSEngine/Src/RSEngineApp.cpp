#include "RSEngineApp.h"
#include "RSApplicationLayer.h"
#include "RSGameLogicLayer.h"

namespace RSE{
	const FResult RSEngineApp::VInit(){
		FResult returnResult;
		memset(&returnResult,0,sizeof(FResult));

		m_pRSApplicationLayer = new RSApplicationLayer();
		m_pRSGameLogicLayer = new RSGameLogicLayer();

		returnResult = m_pRSApplicationLayer->VInit();
		assert(returnResult.m_Result != ORESULT_OK);

		returnResult = m_pRSGameLogicLayer->VInit();
		assert(returnResult.m_Result != ORESULT_OK);

		return returnResult;
	}

		
	const FResult RSEngineApp::VUpdate(const float &delTime){
		FResult returnResult;
		memset(&returnResult,0,sizeof(FResult));

		
		m_pRSApplicationLayer->VUpdate(delTime);
		m_pRSGameLogicLayer->VUpdate(delTime);

		return returnResult;
	}

	const FResult RSEngineApp::VPause(const bool &pause){
		FResult returnResult;
		memset(&returnResult,0,sizeof(FResult));

		

		return returnResult;
	}

	const FResult RSEngineApp::VEnd(){
		FResult returnResult;
		memset(&returnResult,0,sizeof(FResult));

		returnResult = m_pRSGameLogicLayer->VShutdown();
		assert(returnResult.m_Result != ORESULT_OK);

		returnResult = m_pRSApplicationLayer->VShutdown();
		assert(returnResult.m_Result != ORESULT_OK);

		return returnResult;
	}

	const FResult RSEngineApp::VCleanup(){
		FResult returnResult;
		memset(&returnResult,0,sizeof(FResult));

		if(!Release(m_pRSGameLogicLayer)){
			SetError(&returnResult, "Unable to release GameLogicLayer Object");
		}

		if(!Release(m_pRSApplicationLayer)){
			SetError(&returnResult, "Unable to release ApplicationLayer Object");
		}

		return returnResult;
	}
}