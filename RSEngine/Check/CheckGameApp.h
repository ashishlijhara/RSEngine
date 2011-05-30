#ifndef _CHECKGAMEAPP_H_
#define _CHECKGAMEAPP_H_

#include "RSEngine.h"
#include "CheckScene.h"

using namespace RSE;
namespace Check{

	class CheckGameApp: public IBaseGameApp{

	public:

		CheckGameApp(){
			m_pScene = dynamic_cast<IScene*>(new Check::CheckScene());
		}

		~CheckGameApp(){
			
		}

		FResult VInit();

		FResult VRender();

		FResult VRenderPaused();

		FResult VSetPaused(const bool &paused); 

		FResult VUpdate(const float &delTime);

		FResult VCleanup();

		
	};
}

#endif