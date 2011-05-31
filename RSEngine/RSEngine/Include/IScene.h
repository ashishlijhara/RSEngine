#ifndef _ISCENE_H_
#define _ISCENE_H_

#include "RSDefs.h"


namespace RSE{
	class IScene{
	
	public:
		IScene():m_bPaused(false){}

		virtual ~IScene(){}

		virtual FResult VInitScene() = 0;

		virtual FResult VRender() = 0;

		virtual FResult VUpdateScene(const float &delTime) = 0;

		virtual FResult VPauseScene(const bool &paused) = 0;

		virtual FResult VEndScene() = 0;

		virtual FResult VCleanupScene() = 0;

	protected:
		RSSceneNodesList m_SceneNodeList;

		RSSceneManager* m_pRSSceneManager;
		RSCamera *m_pRSCamera;

		bool m_bPaused;
	};
}

#endif