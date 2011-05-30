#include "CheckGameApp.h"

namespace Check{
	FResult CheckGameApp::VInit(){
		FResult returnResult;
		memset(&returnResult, 0, sizeof(FResult));

		returnResult = m_pScene->VInitScene();


		return returnResult;
	}

	FResult CheckGameApp::VRender(){
		FResult returnResult;
		memset(&returnResult, 0, sizeof(FResult));

		returnResult = m_pScene->VRender();

		return returnResult;
	}

	FResult CheckGameApp::VRenderPaused(){
		FResult returnResult;
		memset(&returnResult, 0, sizeof(FResult));

		return returnResult;
	}
	
	
	FResult CheckGameApp::VSetPaused(const bool &paused){
		FResult returnResult;
		memset(&returnResult, 0, sizeof(FResult));

		m_bPaused = paused;
		m_pScene->VPauseScene(paused);

		return returnResult;
	}

	FResult CheckGameApp::VUpdate(const float &delTime){
		FResult returnResult;
		memset(&returnResult, 0, sizeof(FResult));

		returnResult = m_pScene->VUpdateScene(delTime);

		return returnResult;
	}

	FResult CheckGameApp::VCleanup(){
		FResult returnResult;
		memset(&returnResult, 0, sizeof(FResult));

		returnResult = m_pScene->VEndScene();
		returnResult = m_pScene->VCleanupScene();

		if(!Release(m_pScene)){
			SetError(&returnResult,"Error Releasing Scene Object");
		}

		return returnResult;
	}
}