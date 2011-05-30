#ifndef _CHECKSCENE_H_
#define _CHECKSCENE_H_

#include "RSEngine.h"

using namespace RSE;
using namespace Ogre;

namespace Check{

	class CheckScene:public IScene{
	
	private:
		Root *m_pRSRoot;

	public:
		CheckScene(){}
		~CheckScene(){}

		FResult VInitScene();

		FResult VRender();

		FResult VUpdateScene(const float &delTime);

		FResult VPauseScene(const bool &paused);

		FResult VEndScene();

		FResult VCleanupScene();

	};
}

#endif