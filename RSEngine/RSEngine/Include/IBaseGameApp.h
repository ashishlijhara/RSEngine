#ifndef _IBASEGAMEAPP_H_
#define _IBASEGAMEAPP_H_

#include "RSDefs.h"
#include "IScene.h"

namespace RSE{

	class IBaseGameApp{
	public:

		IBaseGameApp():m_bPaused(false){}

		virtual ~IBaseGameApp() {}

		virtual FResult VInit() = 0;

		virtual FResult VRender() = 0;

		virtual FResult VRenderPaused() = 0;

		virtual FResult VUpdate(const float &delTime) = 0;

		virtual FResult VSetPaused(const bool &paused) = 0;

		virtual FResult VCleanup() = 0;

	protected:
		IScene *m_pScene;



		bool m_bPaused;

	};
}

#endif